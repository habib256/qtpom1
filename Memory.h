// Pom1 Apple 1 Emulator
// Copyright (C) 2012 John D. Corrado
// Copyright (C) 2000-2014 Verhille Arnaud
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <QDataStream>
using namespace std;

class Memory
{
public:

    Memory();

    // Memory Options
    void initMemory(void);
    void resetMemory(void);
    void setWriteInRom(bool b);
    bool getWriteInRom(void);

    // Load Memory from file
    int loadBasic(void);
    int loadKrusader(void);
    int loadWozMonitor(void);


    quint8 memRead(quint16 address);
    //quint8 memReadAbsolute(quint16 adr);
    void memWrite(quint16 address, quint8 value);
    unsigned char *dumpMemory(quint16 start, quint16 end);

private :

    // Memory itself tab
    vector <quint8> mem;



    int ramSize; // in kilobytes
    bool writeInRom;

};

#endif // MEMORY_H

