#include "JMPInstruction.h"



JMPInstruction::JMPInstruction()
{
}


JMPInstruction::~JMPInstruction()
{
}

void JMPInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	counter.SetData(goToAddr.GetData());
}
