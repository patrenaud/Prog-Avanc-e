#pragma once
#include"BaseGameState.h"

class SquadState : public BaseGameState
{
public:
	SquadState();
	~SquadState();

private:
	void AddCharacter();
	void DeleteCharacter();
};

