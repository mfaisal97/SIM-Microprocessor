#pragma once
#include "Instruction.h"

class JMPInstruction :
	public Instruction
{
protected:
	AddressOperand* goToAddr;

public:
	JMPInstruction(std::string inst);
	JMPInstruction();
	virtual ~JMPInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void ParseOperands(std::string &str);

	virtual void Print();
};

