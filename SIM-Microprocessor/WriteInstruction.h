#pragma once
#include "OneOperandInstruction.h"

class WriteInstruction :
	public OneOperandInstruction
{
public:
	WriteInstruction(std::string inst);
	WriteInstruction();
	~WriteInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

