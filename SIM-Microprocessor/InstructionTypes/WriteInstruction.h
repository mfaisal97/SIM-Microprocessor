#pragma once
#include "OneOperandInstruction.h"

class WriteInstruction :
	public OneOperandInstruction
{
public:
	WriteInstruction(std::string inst);
	WriteInstruction();
	virtual ~WriteInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};

