#include "Memory.h"

template<typename T>
Memory<T>::Memory()
{
	DataBank = new T[size];
	Initialized = new bool[size];

	for (int i = 0; i < size; ++i) {
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
const T & Memory<T>::GetDataAt(const AddressOperand & addr) const
{
	if (IsInitialized(addr.GetData())) {
		return DataBank[addr.GetData()];
	}
	else {
		cout << "Out of Boundary Error. Trying to read unitialized memory.\n";
		return NULL;
	}
	
}

template<typename T>
void Memory<T>::SetDataAt(const AddressOperand & addr, T data)
{
	DataBank[addr.GetData()] = data;
	Initialized[addr.GetData()] = true;
}

template<typename T>
bool Memory<T>::IsInitialized(const AddressOperand & addr) const
{
	return Initialized[addr.GetData()];
}

