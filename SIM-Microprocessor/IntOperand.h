#pragma once
#include "Operand.h"
class IntOperand :
	public Operand<int>
{
public:
	IntOperand(int);
	~IntOperand();

	virtual inline bool ValidData(const int &) const;
};