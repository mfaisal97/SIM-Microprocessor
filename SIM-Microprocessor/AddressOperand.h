#pragma once
#include "Operand.h"
#include "Memory.h"

class AddressOperand :
	public Operand<int>
{
protected:
	virtual inline bool ValidData(const int &) const;

public:
	AddressOperand();
	AddressOperand(int);
	~AddressOperand();

};

