#pragma once
#include "TwoOperandInstruction.h"

class NegativeInstruction :
	public TwoOperandInstruction
{

public:
	NegativeInstruction();
	~NegativeInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

