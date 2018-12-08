#include "InstructionMemory.h"


InstructionMemory::InstructionMemory(DataMemory & m):mem(m)
{
	counter = new AddressOperand;
	maxCurrent = new AddressOperand;
	counter->SetData(0);
	maxCurrent->SetData(0);
}

InstructionMemory::~InstructionMemory()
{
}

void InstructionMemory::SetCounter(AddressOperand* op)
{
	counter->SetData(*(op->GetData()));
}

AddressOperand* InstructionMemory::GetCounter()
{
	return counter;
}

bool InstructionMemory::ExecuteCounterInstruction()
{
	if (IsInitialized(counter)) {
		std::cout << "Executing Inst #" << *(counter->GetData()) << ":";
		GetDataAt(counter)->Print();
		GetDataAt(counter)->Execute(mem, *counter);
		if (typeid(GetDataAt(counter)) == typeid(HaltInstruction)) {
			std::cout << "End of Instructions\n";
			return false;
		}
		return true;
	}
	else {
		std::cout << "End of Instructions\n";
		return false;
	}

}

void InstructionMemory::AddInstruction(Instruction* inst)
{
	SetDataAt(maxCurrent, inst);
	maxCurrent->SetData(*(maxCurrent->GetData()));
}
