// Pom1 Apple 1 Emulator
// Copyright (C) 2000 Verhille Arnaud
// Copyright (C) 2012 John D. Corrado
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

#ifndef M6502_H
#define M6502_H

#define N 0x80
#define V 0x40
#define B 0x10
#define D 0x08
#define I 0x04
#define Z 0x02
#define C 0x01

class m6502
{
public:

    static unsigned char accumulator, xRegister, yRegister, statusRegister, stackPointer;
    static int IRQ, NMI;
    static unsigned short programCounter;
    static unsigned char btmp;
    static unsigned short op, opH, opL, ptr, ptrH, ptrL, tmp;
    static long lastTime;
    static int cycles, cyclesBeforeSynchro, _synchroMillis;
    //static SDL_Thread *thread;
    static int running;

    m6502();
    void startM6502(void);
    void stopM6502(void);
    void resetM6502(void);
    void setSpeed(int freq, int synchroMillis);
    void setIRQ(int state);
    void setNMI(void);
    int *dumpState(void);
    void loadState(int *state);
};

#endif // M6502_H
