#pragma once
#include "JMPInstruction.h"

class JMP0Instruction :
	public JMPInstruction
{
private:
	Operand<int>* in1;

public:
	JMP0Instruction(std::string inst);
	JMP0Instruction();
	~JMP0Instruction();

	virtual void Execute(DataMemory & mem, AddressOperand& counter) const;
	virtual void ParseOperands(std::string &str);
};

