#include "HaltInstruction.h"



HaltInstruction::HaltInstruction(std::string inst)
{
	ParseOperands(inst);
}

HaltInstruction::HaltInstruction()
{
}


HaltInstruction::~HaltInstruction()
{
}

void HaltInstruction::Execute(DataMemory & mem, AddressOperand & counter) const
{
}
