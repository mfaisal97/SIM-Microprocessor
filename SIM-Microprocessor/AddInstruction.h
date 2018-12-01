#pragma once
#include "Instruction.h"
#include "Operand.h"
#include "AddressOperand.h"

class AddInstruction :
	public Instruction
{
private:
	Operand<int> in1;
	Operand<int> in2;

	AddressOperand out;


public:
	AddInstruction();
	virtual ~AddInstruction();

	virtual void Execute(DataMemory& mem) const;
};

