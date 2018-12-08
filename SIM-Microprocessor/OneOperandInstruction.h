#pragma once
#include "Instruction.h"
class OneOperandInstruction :
	public Instruction
{
protected:
	Operand<int>* addr;
	virtual void ParseOperands(std::string &str);

public:
	OneOperandInstruction(std::string inst);
	OneOperandInstruction();
	~OneOperandInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

