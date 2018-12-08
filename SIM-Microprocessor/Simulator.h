#pragma once
#include "InstructionMemory.h"
#include "DataMemory.h"
#include "InstructionsParser.h"

class Simulator
{
private:
	DataMemory mem;
	InstructionMemory instMem;
	InstructionsParser instParser;
	bool simRunning;

	void AddFile(std::string FileName);
	void AddInstruction(std::string str);
	void ExecuteNextInstruction();
	void ExcuteAllFetchedInstructions();
	void QueryMemoryData(AddressOperand);
	void QueryInstData(AddressOperand);
	void GetHelp();
	void ParseCommand(std::string& str);

public:
	Simulator();
	~Simulator();

	void Start();
};