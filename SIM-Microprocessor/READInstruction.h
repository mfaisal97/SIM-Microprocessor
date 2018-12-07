#pragma once
#include "OneOperandInstruction.h"

class READInstruction :
	public OneOperandInstruction
{
public:
	READInstruction();
	~READInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

