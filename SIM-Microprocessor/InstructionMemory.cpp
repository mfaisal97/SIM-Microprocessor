#include "InstructionMemory.h"


InstructionMemory::InstructionMemory(DataMemory & m):mem(m)
{
}

InstructionMemory::~InstructionMemory()
{
}

void InstructionMemory::SetCounter(AddressOperand op)
{
	counter.SetData(op.GetData());
}

AddressOperand InstructionMemory::GetCounter()
{
	return counter;
}

void InstructionMemory::ExecuteCounterInstruction()
{
	if (IsInitialized(counter)) {
		GetDataAt(counter).Execute(mem, *this);
	}
	else {
		std::cout << "End of Instructions\n";
	}
}

void InstructionMemory::AddInstruction(Instruction inst)
{
	SetDataAt(maxCurrent, inst);
	maxCurrent.SetData(maxCurrent.GetData());
}
