#include "DecodeCode.h"
#include <stdio.h>

mipsinstruction decode(int value)
{
	mipsinstruction instr;

	instr.funct = value & 0x3F;
    instr.immediate = value & 0xFFFF;
	if (instr.immediate >> 15) {
       int x = 0x7FFF;
       x = ~(x);
       instr.immediate = instr.immediate | x;
    }
    instr.rd = (value & 0xF800);
    instr.rd = instr.rd >> 11;
	instr.rt = (value & 0x1F0000) >> 16;
    instr.rs = (value & 0x3E00000) >> 21;
    instr.opcode = (value & 0xFC000000) >> 26;
	return instr;
}


