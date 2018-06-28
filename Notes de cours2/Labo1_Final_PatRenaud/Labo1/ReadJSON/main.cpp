#include "json/json.h"
#include <string>
#include <fstream>
#include <iostream>
#include <list>

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

	void Print()
	{
		std::cout << "-------------------------------" << std::endl;
		std::cout << "First Name: " << firstName << std::endl;
		std::cout << "Second Name: " << secondName << std::endl;
		std::cout << "Age: " << age << std::endl << std::endl;
	}
};

Person* ReadPersonFrom(Json::Value& a_Node);

int main()
{
	std::list<Person*> persons = std::list<Person*>();



	std::ifstream PersonsJson("file.json", std::ifstream::binary);
	Json::Value root;
	PersonsJson >> root;

	Json::Value Persons = Json::arrayValue;
	Persons = root["Persons"];

	for (int i = 0; i < Persons.size(); i++)
	{		
		persons.push_back(ReadPersonFrom(Persons[i]));
	}
	PersonsJson.close();




	for (std::list<Person*>::iterator person = persons.begin(); person != persons.end(); person++)
	{
		(*person)->Print();

		delete *person;
		*person = nullptr;
	}
	persons.clear();

	system("pause");
	return 0;
}

Person* ReadPersonFrom(Json::Value& a_Element)
{
	std::string firstName;
	std::string secondName = "";
	int age = -1;
	
	firstName = a_Element["FirstName"].asString();
	secondName = a_Element["SecondName"].asString();
	age = a_Element["Age"].asInt();

	return new Person(firstName, secondName, age);
}
