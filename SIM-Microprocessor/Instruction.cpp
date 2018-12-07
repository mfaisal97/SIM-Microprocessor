#include "Instruction.h"



Instruction::Instruction()
{
}


Instruction::~Instruction()
{
}

void Instruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	std::cout << "Executing the default Execution Function\n";
}

void Instruction::ParseOperands(std::string & str)
{
	std::cout << "Using Default ParseFunction\n";
}
