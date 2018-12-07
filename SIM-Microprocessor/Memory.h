#pragma once
#include "AddressOperand.h"

template <typename T>
class Memory
{
protected :
	T* DataBank;
	bool* Initialized;

public:
	static const int size = 1024;

	Memory();
	~Memory();

	T& GetDataAt(const AddressOperand&) const;

	void SetDataAt(const AddressOperand&, T);

	bool IsInitialized(const AddressOperand& ) const;
};