#include "Instruction.h"



Operand<int>* Instruction::GetAnyOperand(std::string str)
{
	if (str[0] == 'x' || str[0] == 'X') {
		str.erase(str.begin());
		int val = strtoll(str.c_str(), NULL,0);
		return new AddressOperand(val);
	}
	else if (isdigit(str[0])) {
		int val = strtoll(str.c_str(), NULL, 0);
		return new IntOperand(val);
	}
	else
	{
		std::cout << "Error Wrong syntax of \"" << str << "\" >>>>> Using default 0\n";
	}

	return new Operand<int>();
}

AddressOperand* Instruction::GetAddrOperand(std::string str)
{
	if (str[0] == 'x' || str[0] == 'X') {
		str.erase(str.begin());
		int val = strtoll(str.c_str(), NULL, 0);
		return new AddressOperand(val);
	}
	else
	{
		std::cout << "Error Wrong addr operand syntax of \"" << str << "\" >>>>> Using default 0\n";
	}
	return new AddressOperand();
}

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

void Instruction::Print()
{
	std::cout << "This the default base Instruction\n";
}

void Instruction::ParseOperands(std::string & str)
{
	std::cout << "Using Default ParseFunction\n";
}
