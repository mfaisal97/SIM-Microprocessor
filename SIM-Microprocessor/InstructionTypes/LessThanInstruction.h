#pragma once
#include "ThreeOperandInstruction.h"

class LessThanInstruction :
	public ThreeOperandInstruction
{
public:
	LessThanInstruction(std::string inst);
	LessThanInstruction();
	virtual ~LessThanInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

