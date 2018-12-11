#pragma once
#include "TwoOperandInstruction.h"

class NegativeInstruction :
	public TwoOperandInstruction
{

public:
	NegativeInstruction(std::string inst);
	NegativeInstruction();
	virtual ~NegativeInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

