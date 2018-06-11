#include "SquadState.h"
#include <iostream>
#include <vector>
#include "Mage.h"
#include "Warrior.h"
#include "Squad.h"

using std::cout;
using std::endl;
using std::cin;


SquadState::SquadState()
{
	do
	{
		system("cls");
		cout << "Choice" << endl <<
			" 1 : Ajouter un character " << endl <<
			" 2 : Enlever tout les characters " << endl <<
			" -1 : Retourner au menu principal " << endl;
		cout << " Entrer votre choix: ";
		int choix = 0;
		cin >> choix;

		switch (choix)
		{
		case -1:
			return;
		case 1:
			AddCharacter();
			break;
		case 2:
			DeleteCharacter();
			break;
		}

	}while (true);
}


SquadState::~SquadState()
{
}

void SquadState::AddCharacter()
{
	const std::vector<Characters*>& characters = Squad::GetCharacters();
	if (characters.size() == Squad::Max_Characters)
	{
		cout << "Squad is full " << endl;
		return;
	}
	do
	{
		system("cls");
		cout << "Choix disponibles: " << endl <<
			" 1 : Ajout d'un warrior" << endl <<
			" 2 : Ajout d'un Mage" << endl <<
			" -1 : Revenir a l'ecran principal" << endl;

		cout << " Entrer votre choix: ";
			int choix = 0;
		cin >> choix;

		switch(choix)
		{
		case -1:
			return;
		case 2:
			Squad::AddCharacter(new Mage());
			break;
		case 1:
			Squad::AddCharacter(new Warrior());
			break;
		}

	} while (characters.size() < Squad::Max_Characters);

}

void SquadState::DeleteCharacter()
{
	Squad::ClearAllCharacters();
}
