#include "Operand.h"

template<typename T>
Operand<T>::Operand(const T & data)
{
	if (ValidData(data)) {
		this->Data = data;
	}
	else {
		cout << "Error parsing Operand!\n";
		exit(0);
	}
}

template<typename T>
Operand<T>::~Operand()
{
}


template<typename T>
inline bool Operand<T>::ValidData(const T & data) const
{
	cout << "Using Operand<T>::ValidData(T) == true as Deafult\n";
	return true;
}

template<typename T>
const T& Operand<T>::GetData()  const
{
	return this->Data;
}
