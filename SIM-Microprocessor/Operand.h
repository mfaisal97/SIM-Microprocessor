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
	virtual T* GetData();
	virtual void SetData(T);
};

template<typename T>
Operand<T>::Operand() :Data(0)
{
}

template<typename T>
Operand<T>::Operand(T data)
{
	if (ValidData(data)) {
		this->Data = data;
	}
	else {
		std::cout << "Error parsing Operand!\n";
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
	std::cout << "Using Operand<T>::ValidData(T) == true as Deafult\n";
	return true;
}

template<typename T>
T* Operand<T>::GetData()
{
	return &(this->Data);
}

template<typename T>
void Operand<T>::SetData(T data)
{
	if (ValidData(data)) {
		Data = data;
	}
	else {
		std::cout << "Error: value " << data << "Can not be set in this operand\n";
	}
}