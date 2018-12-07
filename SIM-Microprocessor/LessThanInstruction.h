#pragma once
#include "ThreeOperandInstruction.h"

class LessThanInstruction :
	public ThreeOperandInstruction
{
public:
	LessThanInstruction();
	~LessThanInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

