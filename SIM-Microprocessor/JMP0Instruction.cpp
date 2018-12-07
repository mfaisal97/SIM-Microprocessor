#include "JMP0Instruction.h"



JMP0Instruction::JMP0Instruction()
{
}


JMP0Instruction::~JMP0Instruction()
{
}

void JMP0Instruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	if (((typeid(in1) == typeid(AddressOperand)) ? mem.GetDataAt(in1.GetData()) : in1.GetData()) == 0) {
		counter.SetData(goToAddr.GetData());
	}
	else
	{
		counter.SetData(counter.GetData() + 1);
	}
}
