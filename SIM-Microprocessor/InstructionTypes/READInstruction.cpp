#include "READInstruction.h"

READInstruction::READInstruction(std::string inst)
{
	ParseOperands(inst);
}

READInstruction::READInstruction()
{
}


READInstruction::~READInstruction()
{
}

void READInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	int x_in;
	std::cout << "Please, Enter num to be stored in " << *(addr->GetData()) << " :";
	std::cin >> x_in;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please, Enter num to be stored in " << *(addr->GetData()) << " :";
		std::cin >> x_in;
	}
	
	int* x_in_casted = new int;
	*x_in_casted = *(IntOperand(x_in).GetData());

	mem.SetDataAt(dynamic_cast<AddressOperand*>(addr), x_in_casted);
	counter.SetData(*(counter.GetData()) + 1);
}

void READInstruction::ParseOperands(std::string & str)
{
	std::string str1;
	std::istringstream strStream(str);
	strStream >> str1;
	
	addr = GetAddrOperand(str1);
}

void READInstruction::Print()
{
	std::cout << "\t\t\tReading:\tx" << *addr->GetData() << "\n";
}
