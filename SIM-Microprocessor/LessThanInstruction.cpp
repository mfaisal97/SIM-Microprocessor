#include "LessThanInstruction.h"



LessThanInstruction::LessThanInstruction()
{
}


LessThanInstruction::~LessThanInstruction()
{
}

void LessThanInstruction::Execute(DataMemory & mem, AddressOperand& counter)const
{
	mem.SetDataAt(out, ((typeid(in1) == typeid(AddressOperand)) ? mem.GetDataAt(in1.GetData()) : in1.GetData()) <= ((typeid(in2) == typeid(AddressOperand)) ? mem.GetDataAt(in2.GetData()) : in2.GetData()));
	counter.SetData(counter.GetData() + 1);
}
