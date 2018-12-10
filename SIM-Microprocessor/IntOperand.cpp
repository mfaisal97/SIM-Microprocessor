#include "IntOperand.h"


IntOperand::IntOperand(int data)
{
	if (this->ValidData(data)) {
		this->Data = data;
	}
	else {
		std::cout << "Error parsing Operand!\n";
		exit(0);
	}
}


IntOperand::~IntOperand()
{
}

bool IntOperand::ValidData(const int &) const
{
	return true;						//all values of int are allowed to be entered immediate values
}
