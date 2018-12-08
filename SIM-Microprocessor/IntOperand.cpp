#include "IntOperand.h"


IntOperand::IntOperand(int data) : Operand<int>(data)
{
}


IntOperand::~IntOperand()
{
}

bool IntOperand::ValidData(const int &) const
{
	return true;						//all values of int are allowed to be entered immediate values
}
