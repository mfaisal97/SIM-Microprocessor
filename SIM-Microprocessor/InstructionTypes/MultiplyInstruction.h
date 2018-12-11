#pragma once
#include "ThreeOperandInstruction.h"

class MultiplyInstruction :
	public ThreeOperandInstruction
{
public:
	MultiplyInstruction(std::string inst);
	MultiplyInstruction();
	virtual ~MultiplyInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

