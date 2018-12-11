#include "NegativeInstruction.h"



NegativeInstruction::NegativeInstruction(std::string inst)
{
	Operation = " = -";
	ParseOperands(inst);
}

NegativeInstruction::NegativeInstruction()
{
	Operation = " = -";
}


NegativeInstruction::~NegativeInstruction()
{
}

void NegativeInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	int* val = new int;
	*val = *((typeid(*in1) == typeid(AddressOperand)) ? mem.GetDataAt(dynamic_cast<AddressOperand*> (in1)) : in1->GetData());
	*val = -(*val);
	mem.SetDataAt(out, val);
	counter.SetData(*(counter.GetData()) + 1);
}
