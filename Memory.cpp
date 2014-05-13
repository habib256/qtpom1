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

#include "Memory.h"
//#include "configuration.h"
//#include "pia6820.h"

Memory::Memory()
{
   initMemory();
   // TEST
   mem[5]=0xFF;
   mem[0x8]=0xFF;
   mem[0xA7]=0xF5;
   mem[0xFFFF]=0xA3;

}

void Memory::initMemory(){
    ramSize = 64;  // Ouaahh 64Kbytes !
    for (int i=0; i < ramSize*1024; i++)
    {
    mem.push_back(0);
    }
    loadWozMonitor();
    loadBasic();
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


int Memory::loadWozMonitor(void)
{
    return 0;
}

int Memory::loadBasic(void)
{
    return 0;
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


