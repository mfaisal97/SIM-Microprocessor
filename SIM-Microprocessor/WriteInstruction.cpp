#include "WriteInstruction.h"



WriteInstruction::WriteInstruction()
{
}


WriteInstruction::~WriteInstruction()
{
}

void WriteInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	if (typeid(addr) == typeid(AddressOperand)) {
		std::cout << "Printing:\t" << mem.GetDataAt(addr.GetData()) << "\t\t\tFrom Addr: \t" << addr.GetData();
	}
	else {
		std::cout << "Printing:\t" << addr.GetData() << "\t\t\tFrom Addr: \t" << "Direct Input";
	}
	counter.SetData(counter.GetData() + 1);
}
