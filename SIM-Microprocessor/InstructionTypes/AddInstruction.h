#pragma once
#include "ThreeOperandInstruction.h"

class AddInstruction :
	public ThreeOperandInstruction
{
public:
	AddInstruction(std::string inst);
	AddInstruction();
	virtual ~AddInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

