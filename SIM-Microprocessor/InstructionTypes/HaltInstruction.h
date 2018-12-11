#pragma once
#include "Instruction.h"

class HaltInstruction :
	public Instruction
{
protected:
	virtual void ParseOperands(std::string &str);

public:
	HaltInstruction(std::string inst);
	HaltInstruction();
	virtual ~HaltInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};