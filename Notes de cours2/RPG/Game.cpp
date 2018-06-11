#include "Game.h"
#include "SquadState.h"
#include "FightState.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
}


Game::~Game()
{
}

void Game::Run()
{
	do
	{
		std::cout << "Voici les choix disponibles" << endl <<
			" 1 : Affecter notre squad" << endl <<
			" -1 : Quitter le jeu" << endl;

		cout << "Entrer votre choix: ";
		int choix = 0;
		cin >> choix;

		BaseGameState *state = nullptr;
		switch (choix)
		{
		case -1:
			return;
		case 1:
			state = new SquadState();
			break;
		case 2:
			state = new FightState();
			break;
		}

		delete state;

	} while (true);
}
