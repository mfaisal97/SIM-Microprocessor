#pragma once
#include "OneOperandInstruction.h"

class READInstruction :
	public OneOperandInstruction
{
public:
	READInstruction(std::string inst);
	READInstruction();
	~READInstruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void ParseOperands(std::string &str);
};

