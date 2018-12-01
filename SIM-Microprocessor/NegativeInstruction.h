#pragma once
#include "Instruction.h"
#include "Operand.h"
#include "AddressOperand.h"

class NegativeInstruction :
	public Instruction
{
private:
	Operand<int> in;

	AddressOperand out;

public:
	NegativeInstruction();
	~NegativeInstruction();

	virtual void Execute(DataMemory& mem) const;
};

