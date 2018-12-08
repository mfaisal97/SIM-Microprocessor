#include "MultiplyInstruction.h"



MultiplyInstruction::MultiplyInstruction(std::string inst)
{
	Operation = "*";
	ParseOperands(inst);
}

MultiplyInstruction::MultiplyInstruction()
{
	Operation = "*";
}


MultiplyInstruction::~MultiplyInstruction()
{
}

void MultiplyInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	int* val = new int;
	*val = *((typeid(*in1) == typeid(AddressOperand)) ? mem.GetDataAt(dynamic_cast<AddressOperand*> (in1)) : in1->GetData()) * *((typeid(*in2) == typeid(AddressOperand)) ? mem.GetDataAt(dynamic_cast<AddressOperand*> (in2)) : in2->GetData());
	mem.SetDataAt(out, val);
	counter.SetData(*(counter.GetData()) + 1);
}
