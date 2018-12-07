#include "NegativeInstruction.h"



NegativeInstruction::NegativeInstruction()
{
}


NegativeInstruction::~NegativeInstruction()
{
}

void NegativeInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	mem.SetDataAt(out, -1*((typeid(in1) == typeid(AddressOperand)) ? mem.GetDataAt(in1.GetData()) : in1.GetData()));
	counter.SetData(counter.GetData() + 1);
}
