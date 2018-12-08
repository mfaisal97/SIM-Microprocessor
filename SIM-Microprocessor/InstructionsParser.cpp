#include "InstructionsParser.h"

InstructionsParser::InstructionsParser()
{
}


InstructionsParser::~InstructionsParser()
{
}

bool InstructionsParser::AddInstructionsFromFile(std::string fileName)
{
	std::ifstream InputFile(fileName);
	if (InputFile.is_open()) {
		while (!InputFile.eof()) {
			std::string line;
			std::getline(InputFile, line);
			AddInstructionFromString(line);
		}
		InputFile.close();
	}
	else {
		std::cout << "Error Opening Input Instructions File!\n";
		return false;
	}

	return true;
}


bool InstructionsParser::AddInstructionFromString(std::string instStr)
{
	std::string command;
	std::string restOfCommand;
	std::istringstream instStream(instStr);
	instStream >> command;
	std::getline(instStream, restOfCommand);

	for (char& c : command)
	{
		c = tolower(c);
	}

	for (char& c : restOfCommand)
	{
		if (c == ',') {
			c = ' ';
		}
	}

	if (command == "add") {
		AddInstruction* addinst = new AddInstruction(restOfCommand);
		addinst->Print();
		std::cout << restOfCommand << "\n";
		FetchedInstructions.push(addinst);
	}/*
	else if (command == "neg") {
		FetchedInstructions.push(NegativeInstruction(restOfCommand));
	}
	else if (command == "mul") {
		FetchedInstructions.push(MultiplyInstruction(restOfCommand));
	}
	else if (command == "jmp") {
		FetchedInstructions.push(JMPInstruction(restOfCommand));
	}
	else if (command == "jmp0") {
		FetchedInstructions.push(JMP0Instruction(restOfCommand));
	}
	else if (command == "ass") {
		FetchedInstructions.push(AddInstruction(restOfCommand));
	}
	else if (command == "le") {
		FetchedInstructions.push(LessThanInstruction(restOfCommand));
	}
	else if (command == "read") {
		FetchedInstructions.push(READInstruction(restOfCommand));
	}
	else if (command == "write") {
		FetchedInstructions.push(WriteInstruction(restOfCommand));
	}
	else if (command == "halt") {
		FetchedInstructions.push(HaltInstruction(restOfCommand));
	}*/
	else
	{
		std::cout << "Error. Attempt to add an Unkown Instruction\n";
	}
	
	return true;
}

Instruction* InstructionsParser::NextFetchedInstruction()
{
	Instruction* fetched = FetchedInstructions.front();
	FetchedInstructions.pop();
	return fetched;
}

bool InstructionsParser::HasInstructions()
{
	return FetchedInstructions.size() > 0;
}
