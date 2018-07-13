#pragma once
#include "Boxx.h"
#include <string>

class StorageBoxx :
	public Boxx
{
public:
	StorageBoxx(int width, int height, int lenght, const std::string& label);
	~StorageBoxx();

private:
	std::string m_Label;
};

