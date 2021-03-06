#include "roomfilter.h"
#include <assert.h>
#include <errno.h>

const char *RoomFilter::parse_help =
    "Parse error; format is: [-(name|desc|note|exits|all)] pattern\r\n";


bool RoomFilter::parseRoomFilter(const QString &line, RoomFilter &output)
{
    QString pattern = line;
    char kind = PAT_NAME;
    if (line.size() >= 2 && line[0] == '-') {
        QString kindstr = line.section(" ", 0, 0);
        if (kindstr == "-desc" || kindstr == "-d") kind = PAT_DESC;
        else if (kindstr == "-name") kind = PAT_NAME;
        else if (kindstr == "-exits" || kindstr == "-e") kind = PAT_EXITS;
        else if (kindstr == "-note" || kindstr == "-n") kind = PAT_NOTE;
        else if (kindstr == "-all" || kindstr == "-a") kind = PAT_ALL;
        else return false;

        pattern = line.section(" ", 1);
    }
    output = RoomFilter(pattern, Qt::CaseInsensitive, kind);
    return true;
}

const bool RoomFilter::filter(const Room *r) const
{
    if (kind == PAT_DESC)
        return QString((*r)[1].toString()).contains(pattern, cs);
    else if (kind == PAT_ALL) {
        for (auto elt : (*r))
            if (elt.toString().contains(pattern, cs))
                return 1;
        return 0;
    } else if (kind == PAT_NAME)
        return QString((*r)[0].toString()).contains(pattern, cs);
    else if (kind == PAT_NOTE)
        return QString((*r)[4].toString()).contains(pattern, cs);
    else if (kind == PAT_EXITS) {
        ExitsList exits = r->getExitsList();
        for (ExitsList::const_iterator exitIter = exits.begin(); exitIter != exits.end(); ++exitIter) {
            const Exit &e = *exitIter;
            if (QString((e)[0].toString()).contains(pattern, cs))
                return 1;
        }
    }
    return 0;
}
