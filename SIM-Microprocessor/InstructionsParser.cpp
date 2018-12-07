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


	return false;
}
