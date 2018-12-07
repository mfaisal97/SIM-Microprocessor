#pragma once
#include "Instruction.h"

class JMPInstruction :
	public Instruction
{
protected:
	AddressOperand goToAddr;

public:
	JMPInstruction();
	~JMPInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

