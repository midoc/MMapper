/************************************************************************
**
** Authors:   Ulf Hermann <ulfonk_mennhar@gmx.de> (Alve),
**            Marek Krejza <krejza@gmail.com> (Caligor),
**            Nils Schimmelmann <nschimme@gmail.com> (Jahara)
**
** This file is part of the MMapper project.
** Maintained by Nils Schimmelmann <nschimme@gmail.com>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the:
** Free Software Foundation, Inc.
** 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
************************************************************************/

#include "parserutils.h"

namespace ParserUtils {

static const unsigned char colorEndMark = 'm';
static const unsigned char escChar = '\033';

// latin1 to 7-bit Ascii
static const unsigned char latin1ToAscii[] = {
    /*192*/ 'A',
    'A',
    'A',
    'A',
    'A',
    'A',
    'A',
    'C',
    'E',
    'E',
    'E',
    'E',
    'I',
    'I',
    'I',
    'I',
    'D',
    'N',
    'O',
    'O',
    'O',
    'O',
    'O',
    'x',
    'O',
    'U',
    'U',
    'U',
    'U',
    'Y',
    'b',
    'B',
    'a',
    'a',
    'a',
    'a',
    'a',
    'a',
    'a',
    'c',
    'e',
    'e',
    'e',
    'e',
    'i',
    'i',
    'i',
    'i',
    'o',
    'n',
    'o',
    'o',
    'o',
    'o',
    'o',
    ':',
    'o',
    'u',
    'u',
    'u',
    'u',
    'y',
    'b',
    'y'
};

QString &removeAnsiMarks(QString &str)
{
    QString out = "";
    bool started = false;
    for ( int i = 0; i < str.length(); i++ ) {
        if ( started && (str.at(i).toLatin1() == colorEndMark)) {
            started = false;
            continue;
        }
        if (str.at(i).toLatin1() == escChar) {
            started = true;
            continue;
        }
        if (started) continue;
        out.append(str.at(i));
    }
    str = out;
    return str;
}

QString &latinToAscii(QString &str)
{
    unsigned char ch;
    int pos;
    for (pos = 0; pos < str.length(); pos++) {
        ch = str.at(pos).toLatin1();
        if (ch > 128) {
            if (ch < 192)
                ch = 'z';
            else
                ch = latin1ToAscii[ ch - 192 ];
            str[pos] = ch;
        }
    }
    return str;
}

}
