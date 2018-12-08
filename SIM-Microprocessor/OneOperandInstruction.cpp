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
}

void OneOperandInstruction::Execute(DataMemory & mem, AddressOperand & counter) const
{
}

void OneOperandInstruction::ParseOperands(std::string & str)
{
	addr = GetAnyOperand(str);
}
