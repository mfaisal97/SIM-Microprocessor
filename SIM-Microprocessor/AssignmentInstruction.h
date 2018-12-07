#pragma once
#include "TwoOperandInstruction.h"

class AssignmentInstruction :
	public TwoOperandInstruction
{

public:
	AssignmentInstruction();
	~AssignmentInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

