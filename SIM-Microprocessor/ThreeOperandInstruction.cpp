#include "ThreeOperandInstruction.h"


ThreeOperandInstruction::ThreeOperandInstruction()
{
}


ThreeOperandInstruction::~ThreeOperandInstruction()
{
}

void ThreeOperandInstruction::Execute(DataMemory & mem, AddressOperand & counter) const
{
}

void ThreeOperandInstruction::Print()
{
	std::cout << "\t\t\tMem[" << *out->GetData() << "] =";
	if (typeid(*in1) == typeid(AddressOperand)) {
		std::cout << " Mem[" << *in1->GetData() << "] ";
	}
	else {
		std::cout << " " << *in1->GetData() << " ";
	}
	std::cout << Operation;
	if (typeid(*in2) == typeid(AddressOperand)) {
		std::cout << " Mem[" << *in2->GetData() << "] ";
	}
	else {
		std::cout << " " << *in2->GetData() << " ";
	}
	std::cout << "\n";
}

void ThreeOperandInstruction::ParseOperands(std::string & str)
{
	std::string str1, str2, str3;
	std::istringstream strStream(str);
	strStream >> str1 >> str2 >>str3;

	in1 = GetAnyOperand(str1);
	in2 = GetAnyOperand(str2);
	out = GetAddrOperand(str3);
}
