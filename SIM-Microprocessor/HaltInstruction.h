#pragma once
#include "Instruction.h"

class HaltInstruction :
	public Instruction
{
public:
	HaltInstruction();
	~HaltInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};