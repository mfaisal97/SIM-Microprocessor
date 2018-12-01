#pragma once
#include "Instruction.h"
#include "Operand.h"
#include "AddressOperand.h"

class MultiplyInstruction :
	public Instruction
{
private:
	Operand<int> in1;
	Operand<int> in2;

	AddressOperand out;

public:
	MultiplyInstruction();
	~MultiplyInstruction();

	virtual void Execute(DataMemory& mem) const;
};

