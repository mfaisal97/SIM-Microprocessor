#pragma once
#include "OneOperandInstruction.h"

class WriteInstruction :
	public OneOperandInstruction
{
public:
	WriteInstruction();
	~WriteInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

