#pragma once
#include "DataMemory.h"
#include "InstructionMemory.h"
#include "Operand.h"
#include "IntOperand.h"
#include "AddressOperand.h"

class Instruction
{
public:
	Instruction();
	~Instruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void ParseOperands(std::string &str);
};