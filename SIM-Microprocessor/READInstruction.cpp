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

	int* x_in_casted = new int;
	*x_in_casted = *(IntOperand(x_in).GetData());

	mem.SetDataAt(dynamic_cast<AddressOperand*>(addr), x_in_casted);
	counter.SetData(*(counter.GetData()) + 1);
}

void READInstruction::ParseOperands(std::string & str)
{
	addr = GetAddrOperand(str);
}
