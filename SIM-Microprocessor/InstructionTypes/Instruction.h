#pragma once
#include <string>
#include "../Memory/DataMemory.h"
#include "../OperandTypes/OperandsHeader.h"
#include <string>
#include <sstream>

class Instruction
{
protected:
	virtual Operand<int>* GetAnyOperand(std::string str);
	virtual AddressOperand* GetAddrOperand(std::string str);
	virtual void ParseOperands(std::string &str);

public:
	Instruction();
	virtual ~Instruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};