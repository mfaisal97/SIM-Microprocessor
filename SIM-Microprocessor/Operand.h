#pragma once
#include <iostream>

template <typename T>
class Operand
{

protected:
	T Data;
	virtual inline bool ValidData(const T &) const;

public:

	Operand(const T & data);
	~Operand();
	const T& GetData() const;
};

