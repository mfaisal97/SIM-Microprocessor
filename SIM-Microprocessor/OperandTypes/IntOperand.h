#pragma once
#include "Operand.h"
class IntOperand :
	public Operand<int>
{
public:
	IntOperand(int);
	virtual ~IntOperand();

	virtual inline bool ValidData(const int &) const;
};