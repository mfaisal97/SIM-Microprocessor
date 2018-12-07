#pragma once
#include "Instruction.h"
#include "Memory.h"
#include "DataMemory.h"

typedef Memory<Instruction> bengo;

class InstructionMemory:
	public bengo
{
private:
	AddressOperand counter = 0;
	DataMemory& mem;
	AddressOperand maxCurrent = 0;

public:
	InstructionMemory(DataMemory& m);
	~InstructionMemory();

	void SetCounter(AddressOperand);
	AddressOperand GetCounter();
	void ExecuteCounterInstruction();
	void AddInstruction(Instruction);
};

