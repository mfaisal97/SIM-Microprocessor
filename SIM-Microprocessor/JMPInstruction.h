#pragma once
#include "Instruction.h"
#include "AddressOperand.h"

class JMPInstruction :
	public Instruction
{
private:
	AddressOperand getToAddr;

public:
	JMPInstruction();
	~JMPInstruction();

	virtual void Execute(DataMemory& mem) const;
};

