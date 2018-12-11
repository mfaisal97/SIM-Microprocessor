#include "SIM.h"


SIM::SIM():instMem(mem)
{
	simRunning = true;
}


SIM::~SIM()
{
}

void SIM::AddFile(std::string FileName)
{
	instParser.AddInstructionsFromFile(FileName);

	while (instParser.HasInstructions()) {
		instMem.AddInstruction(instParser.NextFetchedInstruction());
	}
}

void SIM::AddInstruction(std::string str)
{
	instParser.AddInstructionFromString(str);

	while (instParser.HasInstructions()) {
		instMem.AddInstruction(instParser.NextFetchedInstruction());
	}
}

void SIM::ExecuteNextInstruction()
{
	instMem.ExecuteCounterInstruction();
}

void SIM::ExcuteAllFetchedInstructions()
{
	while (instMem.ExecuteCounterInstruction()) {
		system("pause");
	}
}

void SIM::QueryMemoryData(AddressOperand addr)
{
	if (instMem.IsInitialized(&addr)) {
		std::cout << "mem[" << *addr.GetData() << "] = " << *mem.GetDataAt(&addr) << "\n";
	}
	else {
		std::cout << "Out of Boundary Error. Trying to read unitialized memory.\n";
	}
}

void SIM::QueryInstMemory(AddressOperand addr)
{
	if (instMem.IsInitialized(&addr)) {
		std::cout << "instmem[" << *addr.GetData() << "] = ";
		instMem.GetDataAt(&addr)->Print();
		std::cout << "\n";
	}
	else {
		std::cout << "Out of Boundary Error. Trying to read unitialized memory.\n";
	}
}

void SIM::QueryAllInstMemory()
{
	int maxcurr = instMem.GetMaxCurrent() -1;
	for (int i = 0; i <= maxcurr; ++i) {
		AddressOperand addr(i);
		std::cout << "instmem[" << *addr.GetData() << "] = ";
		instMem.GetDataAt(&addr)->Print();
	}

}

void SIM::GetHelp()
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

void SIM::ParseCommand(std::string & str)
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
	else if (command == "") {

	}
	else {
		std::cout << "Wrong command. Please try Again\n";
	}
}

void SIM::Start()
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
