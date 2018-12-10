#include "Simulator.h"



Simulator::Simulator():instMem(mem)
{
	simRunning = true;
}


Simulator::~Simulator()
{
}

void Simulator::AddFile(std::string FileName)
{
	instParser.AddInstructionsFromFile(FileName);

	while (instParser.HasInstructions()) {
		instMem.AddInstruction(instParser.NextFetchedInstruction());
	}
}

void Simulator::AddInstruction(std::string str)
{
	instParser.AddInstructionFromString(str);

	while (instParser.HasInstructions()) {
		instMem.AddInstruction(instParser.NextFetchedInstruction());
	}
}

void Simulator::ExecuteNextInstruction()
{
	instMem.ExecuteCounterInstruction();
}

void Simulator::ExcuteAllFetchedInstructions()
{
	while (instMem.ExecuteCounterInstruction()) {
		system("pause");
	}
}

void Simulator::QueryMemoryData(AddressOperand addr)
{
	std::cout << "mem[" << *addr.GetData() << "] = " << *mem.GetDataAt(&addr) << "\n";
}

void Simulator::QueryInstMemory(AddressOperand addr)
{
	std::cout << "instmem[" << *addr.GetData() << "] = ";
	instMem.GetDataAt(&addr)->Print();
	std::cout << "\n";
}

void Simulator::QueryAllInstMemory()
{
	int maxcurr = instMem.GetMaxCurrent() -1;
	for (int i = 0; i <= maxcurr; ++i) {
		AddressOperand addr(i);
		std::cout << "instmem[" << *addr.GetData() << "] = ";
		instMem.GetDataAt(&addr)->Print();
		std::cout << "\n";
	}

}

void Simulator::GetHelp()
{
	std::cout << "*********************************************\n";
	std::cout << "Please, choose one of the following commands:\n";
	std::cout << "AddFile\t{file_name}\t\t\t\tTo add new instructions from file\n";
	std::cout << "AddInst\t{Instruction}\t\t\t\tTo add new instruction directly\n";
	std::cout << "ExNext\t\t\t\t\t\tTo Excute the following instruction\n";
	std::cout << "ExAll\t\t\t\t\t\tTo Excute all the remaining instructions\n";
	std::cout << "QMD\t{Data_address}\t\t\t\tTo get the current corresponding value for this address\n";
	std::cout << "QID\t{Instruction_address}\t\t\tTo get the corresponding instruction for this address\n";
	std::cout << "QIDAll\t\t\t\t\tTo get all stored instructions\n";
	std::cout << "Help\t\t\t\t\t\tTo get the view this help dialogue again\n";
	std::cout << "Exit\t\t\t\t\t\tTo end the simulation\n";
	std::cout << "*********************************************\n\n\n";
}

void Simulator::ParseCommand(std::string & str)
{
	std::istringstream strStream(str);
	std::string command;
	strStream >> command;

	for (char& c : command) {
		c = tolower(c);
	}

	if (command == "addfile")
	{
		strStream >> command;
		std::string name;
		std::getline(strStream, name);
		name = command + name;
		AddFile(name);
	}
	else if (command == "addinst") {
		strStream >> command;
		std::string inst;
		std::getline(strStream, inst);
		inst = command + inst;
		AddInstruction(inst);
	}
	else if (command == "exnext") {
		ExecuteNextInstruction();
	}
	else if (command == "exall") {
		ExcuteAllFetchedInstructions();
	}
	else if (command == "qmd") {
		int addr = -1;
		strStream >> addr;
		if (addr == -1) {
			std::cout << "Wrong command. Please try Again\n";
		}
		else {
			QueryMemoryData(AddressOperand(addr));
		}
	}
	else if (command == "qid") {
		int addr = -1;
		strStream >> addr;

		if (addr == -1) {
			std::cout << "Wrong command. Please try Again\n";
		}
		else {
			QueryInstMemory(AddressOperand(addr));
		}
	}
	else if (command == "qidall") {
		QueryAllInstMemory();
	}
	else if (command == "help") {
		GetHelp();
	}
	else if (command == "exit") {
		simRunning = false;
	}
	else {
		std::cout << "Wrong command. Please try Again\n";
	}
}

void Simulator::Start()
{
	GetHelp();
	while (simRunning)
	{
		std::cout << "\n$ ";
		std::string str;
		std::getline(std::cin, str);
		ParseCommand(str);
	}
}
