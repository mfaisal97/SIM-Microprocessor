#pragma once
#include "DataMemory.h"

class Instruction
{
public:
	Instruction();
	~Instruction();

	virtual void Execute(DataMemory& mem) const = 0;
};