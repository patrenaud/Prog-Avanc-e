#include "Game.h"

int main()
{
	// Cr�ation d'une nouvelle game
	Game *game = new Game();

	// Loop while pour rester dans la game
	game->Run();

	// Delete la game lorsque termin�e
	delete game;
}