#pragma once
#include "Memory/MemoriesHeader.h"
#include "InstructionsParser.h"

class SIM
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
	void QueryInstMemory(AddressOperand);
	void QueryAllInstMemory();
	void GetHelp();
	void ParseCommand(std::string& str);

public:
	SIM();
	~SIM();

	void Start();
};