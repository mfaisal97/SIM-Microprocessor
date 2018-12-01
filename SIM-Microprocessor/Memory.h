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

	const T& GetDataAt(const AddressOperand& addr) const;

	void SetDataAt(const AddressOperand& addr, T data);

	bool IsInitialized(const AddressOperand& addr) const;
};