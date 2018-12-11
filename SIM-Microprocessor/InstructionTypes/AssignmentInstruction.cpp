#include "AssignmentInstruction.h"



AssignmentInstruction::AssignmentInstruction(std::string inst)
{
	Operation = " = ";
	ParseOperands(inst);
}

AssignmentInstruction::AssignmentInstruction()
{
	Operation = " = ";
}


AssignmentInstruction::~AssignmentInstruction()
{
}

void AssignmentInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	int* val = new int;
	*val = *((typeid(*in1) == typeid(AddressOperand)) ? mem.GetDataAt(dynamic_cast<AddressOperand*> (in1)) : in1->GetData());
	mem.SetDataAt(out, val);
	counter.SetData(*(counter.GetData()) + 1);
}
