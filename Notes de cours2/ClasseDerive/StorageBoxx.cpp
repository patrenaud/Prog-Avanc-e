#include "StorageBoxx.h"



StorageBoxx::StorageBoxx(int width, int height, int lenght, const std::string& label)
	: Boxx(width, height, lenght)
	, m_Label(label)
{
}


StorageBoxx::~StorageBoxx()
{
}
