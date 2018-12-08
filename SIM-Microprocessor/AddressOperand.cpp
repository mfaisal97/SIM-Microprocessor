#include "AddressOperand.h"



AddressOperand::AddressOperand()
{
}

AddressOperand::AddressOperand(int data ) : Operand<int>(data)
{
}


AddressOperand::~AddressOperand()
{
}

bool AddressOperand::ValidData(const int & data) const
{
	return data >=0 && data < size;
}
