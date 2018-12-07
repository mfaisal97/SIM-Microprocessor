#pragma once
#include "Instruction.h"
class OneOperandInstruction :
	public Instruction
{
protected:
	Operand<int> addr;
public:
	OneOperandInstruction();
	~OneOperandInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

