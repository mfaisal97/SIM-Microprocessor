#include "HaltInstruction.h"



void HaltInstruction::ParseOperands(std::string & str)
{
}

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

void HaltInstruction::Print()
{
	std::cout << "\t\t\tStop Simulation\n";
}
