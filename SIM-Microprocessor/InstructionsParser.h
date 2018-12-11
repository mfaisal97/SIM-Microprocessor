#pragma once
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "InstructionTypes/InstructionsHeader.h"


class InstructionsParser
{
private:
	std::queue <Instruction*> FetchedInstructions;

public:
	InstructionsParser();
	~InstructionsParser();

	bool AddInstructionsFromFile(std::string fileName);
	bool AddInstructionFromString(std::string instStr);

	Instruction* NextFetchedInstruction();
	bool HasInstructions();
};