#pragma once
#include <string>
#include "DataMemory.h"
#include "Operand.h"
#include "IntOperand.h"
#include "AddressOperand.h"
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
	~Instruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void Print();
};