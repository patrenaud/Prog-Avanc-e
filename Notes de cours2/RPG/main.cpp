#include "Game.h"

int main()
{
	// Création d'une nouvelle game
	Game *game = new Game();

	// Loop while pour rester dans la game
	game->Run();

	// Delete la game lorsque terminée
	delete game;
}