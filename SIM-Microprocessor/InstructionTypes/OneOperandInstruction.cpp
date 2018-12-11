#include "OneOperandInstruction.h"



OneOperandInstruction::OneOperandInstruction(std::string inst)
{
	ParseOperands(inst);
}

OneOperandInstruction::OneOperandInstruction()
{
}


OneOperandInstruction::~OneOperandInstruction()
{
	delete addr;
}

void OneOperandInstruction::Execute(DataMemory & mem, AddressOperand & counter) const
{
}

void OneOperandInstruction::ParseOperands(std::string & str)
{
	std::string str1;
	std::istringstream strStream(str);
	strStream >> str1;

	addr = GetAnyOperand(str1);
}
