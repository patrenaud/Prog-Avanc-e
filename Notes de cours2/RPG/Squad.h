#pragma once

#include<vector>
#include "Characters.h"

class Squad
{
public:	
	
	virtual ~Squad();

	static const int Max_Characters = 3;

	static void AddCharacter(Characters* a_Character) { m_Characters.push_back(a_Character); }
	static void ClearAllCharacters();

	static const std::vector<Characters*>& GetCharacters() {return m_Characters; }
	static const Characters* GetCharacter(const int index) { return m_Characters[index]; }

private:
	Squad() {}
	static std::vector<Characters*> m_Characters;
};

