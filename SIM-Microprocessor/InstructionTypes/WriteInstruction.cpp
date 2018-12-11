#include "WriteInstruction.h"



WriteInstruction::WriteInstruction(std::string inst)
{
	ParseOperands(inst);
}

WriteInstruction::WriteInstruction()
{
}


WriteInstruction::~WriteInstruction()
{
}

void WriteInstruction::Execute(DataMemory & mem, AddressOperand& counter) const
{
	if (typeid(*addr) == typeid(AddressOperand)) {
		std::cout << "Printing:\t" << *mem.GetDataAt(dynamic_cast<AddressOperand*>(addr)) << "\t\t\tFrom Addr: \t" << *addr->GetData();
	}
	else {
		std::cout << "Printing:\t" << *addr->GetData() << "\t\t\tFrom Addr: \t" << "Direct Input";
	}
	counter.SetData(*(counter.GetData()) + 1);
}

void WriteInstruction::Print()
{
	if (typeid(*addr) == typeid(AddressOperand)) {
		std::cout << "\t\t\tWriting:\tx" << *addr->GetData() << "\n";
	}
	else {
		std::cout << "\t\t\tWriting:\t" << *addr->GetData() << "\n";
	}
}
