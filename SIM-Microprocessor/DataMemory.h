#pragma once
#include "Memory.h"

class DataMemory :
	public Memory<int>
{
public:
	DataMemory();
	~DataMemory();
};

