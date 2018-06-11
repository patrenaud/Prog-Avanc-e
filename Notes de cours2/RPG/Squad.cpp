#include "Squad.h"

std::vector<Characters*> Squad::m_Characters = {};

Squad::~Squad()
{
	ClearAllCharacters();
}

void Squad::ClearAllCharacters()
{
	for (int i = 0; i < m_Characters.size(); i++)
	{
		
		if (m_Characters[i] != nullptr)
		{
			delete m_Characters[i];
			m_Characters[i] = nullptr;			
		}
	}
	m_Characters.clear();
}
