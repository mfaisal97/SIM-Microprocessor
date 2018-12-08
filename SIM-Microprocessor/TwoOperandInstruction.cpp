#include "TwoOperandInstruction.h"



TwoOperandInstruction::TwoOperandInstruction()
{
}


TwoOperandInstruction::~TwoOperandInstruction()
{
}

void TwoOperandInstruction::Execute(DataMemory & mem, AddressOperand & counter) const
{
}

void TwoOperandInstruction::ParseOperands(std::string & str)
{
	std::string str1, str2;
	std::istringstream strStream(str);
	strStream >> str1 >> str2;

	in1 = GetAnyOperand(str1);
	out = GetAddrOperand(str2);
}

void TwoOperandInstruction::Print()
{
	std::cout << "\t\t\tMem[" << out->GetData() << "]";
	std::cout << Operation;
	if (typeid(*in1) == typeid(AddressOperand)) {
		std::cout << "Mem[" << in1->GetData() << "] ";
	}
	std::cout << "\n";
}
