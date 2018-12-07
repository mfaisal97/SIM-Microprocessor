#pragma once
#include "Instruction.h"

class TwoOperandInstruction : public Instruction
{
protected:
	Operand<int> in1;

	AddressOperand out;
public:
	TwoOperandInstruction();
	~TwoOperandInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

