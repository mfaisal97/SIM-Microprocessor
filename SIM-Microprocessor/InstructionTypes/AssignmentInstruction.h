#pragma once
#include "TwoOperandInstruction.h"

class AssignmentInstruction :
	public TwoOperandInstruction
{

public:
	AssignmentInstruction(std::string inst);
	AssignmentInstruction();
	virtual ~AssignmentInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
};

