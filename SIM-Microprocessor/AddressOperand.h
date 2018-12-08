#pragma once
#include "Operand.h"

class AddressOperand :
	public Operand<int>
{
protected:
	virtual inline bool ValidData(const int &) const;

public:
	static const int size = 1024;

	AddressOperand();
	AddressOperand(int);
	~AddressOperand();

};