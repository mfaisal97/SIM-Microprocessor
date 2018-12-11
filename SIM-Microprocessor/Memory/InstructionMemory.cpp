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
	delete counter;
	delete maxCurrent;
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
		if (typeid(*GetDataAt(counter)) == typeid(HaltInstruction)) {
			std::cout << "End of Instructions\n";
			return false;
		}
		GetDataAt(counter)->Execute(mem, *counter);
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
	maxCurrent->SetData(*(maxCurrent->GetData()) + 1);
}

int InstructionMemory::GetMaxCurrent()
{
	return *maxCurrent->GetData();
}
