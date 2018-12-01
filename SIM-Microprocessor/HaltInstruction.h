#pragma once
#include "Instruction.h"
class HaltInstruction :
	public Instruction
{
public:
	HaltInstruction();
	~HaltInstruction();
};

