#pragma once
#include <iostream>

template <typename T>
class Operand
{

protected:
	T Data;
	virtual inline bool ValidData(const T &) const;

public:

	Operand();
	Operand(T data);
	~Operand();
	T GetData() const;
	void SetData(T);
};

