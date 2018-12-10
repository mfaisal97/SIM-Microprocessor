#include "AddressOperand.h"



AddressOperand::AddressOperand()
{
}

AddressOperand::AddressOperand(int data )
{
	if (this->ValidData(data)) {
		this->Data = data;
	}
	else {
		std::cout << "Error parsing Operand!\n";
		exit(0);
	}
}


AddressOperand::~AddressOperand()
{
}

bool AddressOperand::ValidData(const int & data) const
{
	return data >=0 && data < size;
}
