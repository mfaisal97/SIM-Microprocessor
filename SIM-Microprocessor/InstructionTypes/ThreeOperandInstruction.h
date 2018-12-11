#pragma once
#include "Instruction.h"
class ThreeOperandInstruction :
	public Instruction
{
protected:
	Operand<int>* in1;
	Operand<int>* in2;

	AddressOperand* out;

	std::string Operation;

	virtual void ParseOperands(std::string &str);

public:
	ThreeOperandInstruction();
	virtual ~ThreeOperandInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};

