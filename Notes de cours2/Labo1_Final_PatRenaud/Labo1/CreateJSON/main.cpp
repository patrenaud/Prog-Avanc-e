#include "json/json.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Person
{
	std::string firstName;
	std::string secondName;
	int age;

	Person(const std::string a_FirstName, const std::string a_SecondName, const int a_Age)
		: firstName(a_FirstName)
		, secondName(a_SecondName)
		, age(a_Age)
	{

	}
};

void CreateJsonFor(const Person* a_Person, Json::Value& a_Value);

int main()
{
	std::vector<Person*> persons = std::vector<Person*>();
	persons.push_back(new Person("John", "Doe", 26));
	persons.push_back(new Person("Jane", "Doe", 25));
	persons.push_back(new Person("Willy", "Doe", 12));
	persons.push_back(new Person("Agathe", "Doe", 3));

	// -------- Enter your code here! ------------

	Json::Value root;
	Json::Value Persons = Json::arrayValue;

	for (int i = 0; i < persons.size(); i++)
	{
		CreateJsonFor(persons[i], Persons);
	}
	
	root["Persons"] = Persons;
	
	std::ofstream jsonFile("file.json");
	jsonFile << root;
	jsonFile.close();


	for (std::vector<Person*>::iterator person = persons.begin(); person != persons.end(); person++)
	{
		delete *person;
		*person = nullptr;
	}
	persons.clear();

	system("pause");
	return 0;
}

void CreateJsonFor(const Person* a_Person, Json::Value& a_Element)
{

	Json::Value person = Json::objectValue;
	person["FirstName"] = a_Person->firstName;
	person["SecondName"] = a_Person->secondName;
	person["Age"] = a_Person->age;

	a_Element.append(person);

}