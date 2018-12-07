#include "AssignmentInstruction.h"



AssignmentInstruction::AssignmentInstruction()
{
}


AssignmentInstruction::~AssignmentInstruction()
{
}

void AssignmentInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	mem.SetDataAt(out, ((typeid(in1) == typeid(AddressOperand)) ? mem.GetDataAt(in1.GetData()) : in1.GetData()));
	counter.SetData(counter.GetData() + 1);
}
