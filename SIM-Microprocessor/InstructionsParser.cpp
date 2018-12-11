#include "InstructionsParser.h"

InstructionsParser::InstructionsParser()
{
}


InstructionsParser::~InstructionsParser()
{
	while (FetchedInstructions.size() > 0) {
		Instruction* fetched = FetchedInstructions.front();
		delete fetched;
		FetchedInstructions.pop();
	}
}

bool InstructionsParser::AddInstructionsFromFile(std::string fileName)
{
	std::ifstream InputFile(fileName);
	if (InputFile.is_open()) {
		while (!InputFile.eof()) {
			std::string line;
			std::getline(InputFile, line);
			if (line.find_first_not_of(' ') != std::string::npos)
			{
				AddInstructionFromString(line);
			}
		}
		InputFile.close();
		std::cout << "File Parsed Successfully.\n";
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

	if (command[0] == '#') {

	}
	else if (command == "add") {
		FetchedInstructions.push(new AddInstruction(restOfCommand));
	}
	else if (command == "neg") {
		FetchedInstructions.push(new NegativeInstruction(restOfCommand));
	}
	else if (command == "mul") {
		FetchedInstructions.push(new MultiplyInstruction(restOfCommand));
	}
	else if (command == "jmp") {
		FetchedInstructions.push(new JMPInstruction(restOfCommand));
	}
	else if (command == "jmp0") {
		FetchedInstructions.push(new JMP0Instruction(restOfCommand));
	}
	else if (command == "ass") {
		FetchedInstructions.push(new AssignmentInstruction(restOfCommand));
	}
	else if (command == "le") {
		FetchedInstructions.push(new LessThanInstruction(restOfCommand));
	}
	else if (command == "read") {
		FetchedInstructions.push(new READInstruction(restOfCommand));
	}
	else if (command == "write") {
		FetchedInstructions.push(new WriteInstruction(restOfCommand));
	}
	else if (command == "halt") {
		FetchedInstructions.push(new HaltInstruction(restOfCommand));
	}
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