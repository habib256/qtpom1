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

#include <iostream>
#include <fstream>
#include <string>

#include <QFile>
#include "Memory.h"
//#include "configuration.h"
//#include "pia6820.h"

Memory::Memory()
{
    initMemory();
}

void Memory::initMemory(){
    ramSize = 64;  // Ouaahh 64Kbytes !
    for (int i=0; i < ramSize*1024; i++)
    {
        mem.push_back(0);
    }
    loadBasic();
    //loadKrusader();
    loadWozMonitor();
    setWriteInRom(0);
}

void Memory::resetMemory(void)
{
    for (int i=0; i < ramSize*1024; i++)
    {
        mem[i]=0;
    }
}

void Memory::setWriteInRom(bool b)
{
    writeInRom = b;
}

bool Memory::getWriteInRom(void)
{
    return writeInRom;
}

int Memory::loadBasic(void)
{
    QFile file(":/roms/basic.rom");
    if (!file.open(QIODevice::ReadOnly)) {
        cout << "ERROR : Cannot Read basic File." << endl;
        return 1;
    }
    QByteArray fileContent = file.readAll();
    cout <<"Basic Loaded to 0xE000 : " << fileContent.size() << " Bytes" << endl;
    for (int i = 0; i < fileContent.size(); ++i) {
        mem[i+0xE000]=(unsigned int) fileContent[i];
    }
}


// Loading Krusader do not work for now ...
int Memory::loadKrusader(void)
{
    QFile file(":/roms/krusader-1.3.rom");
    if (!file.open(QIODevice::ReadOnly)) {
        cout << "ERROR : Cannot Read krusader-1.3 File." << endl;
        return 1;
    }
    QByteArray fileContent = file.readAll();
    cout <<"Krusader-1.3 Loaded to 0xF000 : " << fileContent.size() << " Bytes" << endl;
    for (int i = 0; i < fileContent.size(); ++i) {
        mem[i+0xF000]=(unsigned int) fileContent[i];
    }
}

int Memory::loadWozMonitor(void)
{
    QFile file(":/roms/WozMonitor.rom");
    if (!file.open(QIODevice::ReadOnly)) {
        cout << "ERROR : Cannot Read WozMonitor File." << endl;
        return 1;
    }
    QByteArray fileContent = file.readAll();
    cout <<"WozMonitor Loaded to 0xFF00 : " << fileContent.size() << " Bytes" << endl;
    for (int i = 0; i < fileContent.size(); ++i) {
        mem[i+0xFF00]=(unsigned int) fileContent[i];
    }
}



unsigned int Memory::memRead(unsigned int address)
{
    return mem[address];
}

void Memory::memWrite(unsigned short address, unsigned char value)
{
    if (address >= 0xFF00 && !writeInRom)
        return;
    mem[address] = value;
}


