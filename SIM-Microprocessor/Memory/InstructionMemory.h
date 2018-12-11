#pragma once
#include "../InstructionTypes/InstructionsHeader.h"
#include "Memory.h"
#include "DataMemory.h"

class InstructionMemory:
	public Memory<Instruction>
{
private:
	AddressOperand* counter;
	DataMemory& mem;
	AddressOperand* maxCurrent;

public:
	InstructionMemory(DataMemory& m);
	virtual ~InstructionMemory();

	void SetCounter(AddressOperand*);
	AddressOperand* GetCounter();
	bool ExecuteCounterInstruction();
	void AddInstruction(Instruction*);
	int GetMaxCurrent();
};

