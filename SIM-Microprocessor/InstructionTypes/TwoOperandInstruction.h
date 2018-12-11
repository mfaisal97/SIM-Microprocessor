#pragma once
#include "Instruction.h"

class TwoOperandInstruction : public Instruction
{
protected:
	Operand<int>* in1;

	AddressOperand* out;

	std::string Operation;

	virtual void ParseOperands(std::string &str);

public:
	TwoOperandInstruction();
	virtual ~TwoOperandInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};

