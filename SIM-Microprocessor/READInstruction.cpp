#include "READInstruction.h"



READInstruction::READInstruction()
{
}


READInstruction::~READInstruction()
{
}

void READInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	int x_in;
	std::cout << "Please, Enter num to be stored in " << addr.GetData() << " :";
	std::cin >> x_in;

	mem.SetDataAt(addr.GetData(), IntOperand(x_in).GetData());
	counter.SetData(counter.GetData() + 1);
}
