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
}

void JMPInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	counter.SetData(*(goToAddr->GetData()));
}

void JMPInstruction::ParseOperands(std::string & str)
{
	goToAddr = GetAddrOperand(str);
}
