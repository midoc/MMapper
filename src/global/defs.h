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

#ifndef DEFS_H
#define DEFS_H

#ifndef TRUE
enum { TRUE = 1, FALSE = 0 };
#endif

enum { LEFT = 0, RIGHT };
enum { SOURCE = 0, DESTINATION };

#define bit1 1
#define bit2 2
#define bit3 4
#define bit4 8
#define bit5 16
#define bit6 32
#define bit7 64
#define bit8 128
#define bit9 256
#define bit10 512
#define bit11 1024
#define bit12 2048
#define bit13 4096
#define bit14 8192
#define bit15 16384
#define bit16 32768
#define bit17 65536
#define bit18 131072
#define bit19 262144
#define bit20 524288
#define bit21 1048576
#define bit22 2097152
#define bit23 4194304
#define bit24 8388608
#define bit25 16777216
#define bit26 33554432
#define bit27 67108864
#define bit28 134217728
#define bit29 268435456
#define bit30 536870912
#define bit31 1073741824
#define bit32 2147483648

#define UNSET(dest,bit) (dest &=~bit)
#define SET(dest,bit) (dest |=bit)
#define ISSET(src,bit) (src & bit)
#define ISNOTSET(src,bit) (!(src & bit))
#define KEEP(dest,bit) (dest = dest)

// 2 -> set, 0 -> unset, 1 -> keep
#define SETIF(dest,bit,b) (b == 2 ? SET(dest,bit): ( b == 0 ? UNSET(dest,bit) : KEEP(dest,bit) ) )

enum DirectionType { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3, UP = 4, DOWN = 5, NONE = 6, UNKNOWN = 7 };
enum { FIRST = 0, SECOND = 1, THIRD = 2, FOURTH = 3, FIFTH = 4, SIXTH = 5 };

#endif
