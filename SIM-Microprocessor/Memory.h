#pragma once
#include "AddressOperand.h"

template <typename T>
class Memory
{
protected :
	T** DataBank;
	bool* Initialized;

public:

	Memory();
	~Memory();

	virtual T* GetDataAt(AddressOperand*);

	virtual void SetDataAt(AddressOperand*, T*);

	virtual bool IsInitialized(AddressOperand* ) const;
};

template<typename T>
Memory<T>::Memory()
{
	DataBank = new T*[AddressOperand::size];
	Initialized = new bool[AddressOperand::size];

	for (int i = 0; i < AddressOperand::size; ++i) {
		Initialized[i] = 0;
	}
}

template<typename T>
Memory<T>::~Memory()
{
	delete[]DataBank;
	delete[]Initialized;
}

template<typename T>
T* Memory<T>::GetDataAt(AddressOperand* addr)
{
	if (IsInitialized(addr)) {
		return DataBank[*(addr->GetData())];
	}
	else {
		std::cout << "Out of Boundary Error. Trying to read unitialized memory.\n";
	}
}

template<typename T>
void Memory<T>::SetDataAt(AddressOperand* addr, T* data)
{
	if (IsInitialized(addr)) {
		T* d = DataBank[*(addr->GetData())];
		delete d;
	}
	DataBank[*(addr->GetData())] = data;
	Initialized[*(addr->GetData())] = true;
}

template<typename T>
bool Memory<T>::IsInitialized(AddressOperand* addr) const
{
	return Initialized[*(addr->GetData())];
}

