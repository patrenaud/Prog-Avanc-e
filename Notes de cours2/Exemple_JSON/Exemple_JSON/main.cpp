#include "json\json.h"
#include <fstream>
#include <iostream>

void CreateJson();
void ReadJson();

int main()
{
	CreateJson();
	ReadJson();

	system("pause");
	return 0;
}

void CreateJson()
{
	Json::Value root;

	Json::Value characters = Json::arrayValue;

	Json::Value character = Json::objectValue;

	character["id"] = "Warrior";

	Json::Value stats = Json::objectValue;
	stats["armor"] = 50;
	stats["hp"] = 40;
	character["stats"] = stats;

	characters.append(character);

	character["id"] = "Mage";

	stats["armor"] = 10;
	stats["hp"] = 25;
	character["stats"] = stats;

	characters.append(character);

	root["characters"] = characters;

	std::ofstream jsonFile("characters.json");
	jsonFile << root;
	jsonFile.close();
}

void ReadJson()
{
	std::ifstream charactersJson("characters.json", std::ifstream::binary);
	Json::Value root;
	charactersJson >> root;

	Json::Value charactersArray = Json::arrayValue;
	charactersArray = root["characters"];
	for (int i = 0; i < charactersArray.size(); i++)
	{
		std::cout << "id: " << charactersArray[i]["id"].asString() << std::endl;
		std::cout << "stats: " << std::endl;
		std::cout << "  armor: " << charactersArray[i]["stats"]["armor"].asInt() << std::endl;
		std::cout << "  hp: " << charactersArray[i]["stats"]["hp"].asInt() << std::endl << std::endl;

	}

	charactersJson.close();
}