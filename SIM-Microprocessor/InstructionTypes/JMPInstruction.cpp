#include "JMPInstruction.h"



JMPInstruction::JMPInstruction(std::string inst)
{
	ParseOperands(inst);
}

JMPInstruction::JMPInstruction()
{
}


JMPInstruction::~JMPInstruction()
{
	delete goToAddr;
}

void JMPInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	counter.SetData(*(goToAddr->GetData()));
}

void JMPInstruction::ParseOperands(std::string & str)
{
	std::string str1;
	std::istringstream strStream(str);
	strStream >> str1;
	goToAddr = GetAddrOperand(str1);
}

void JMPInstruction::Print()
{
	std::cout << "\t\t\tPCCounter = x" << *goToAddr->GetData() << "\n";
}
