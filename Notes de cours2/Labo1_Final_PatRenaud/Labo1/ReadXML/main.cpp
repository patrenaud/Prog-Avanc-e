#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <list>
using namespace tinyxml2;

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

Person* ReadPersonFrom(XMLElement* a_Node);

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns></returns>
int main()
{
	std::list<Person*> persons = std::list<Person*>();

	// Insert your code here
	XMLDocument xmlDoc;
	xmlDoc.LoadFile("file.xml");
	XMLElement* root = xmlDoc.FirstChildElement("root");
	XMLElement* element = root->FirstChildElement();

	while (element != nullptr)
	{
		persons.push_back(ReadPersonFrom(element));

		element = element->NextSiblingElement();
	}


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

/// <summary>
/// Read the XML element and create the person from it.
/// </summary>
/// <param name="a_Element">the element to read (contains person's info)</param>
/// <return>pointer to a new person created with information in the XML element</return>
Person* ReadPersonFrom(XMLElement* a_Element)
{
	std::string firstName;
	std::string secondName = "";
	int age = -1;

	const char *temp;
	int IntValue;

	if (a_Element->QueryStringAttribute("FirstName", &temp) == XML_SUCCESS)
	{
		firstName = std::string(temp);
	}

	if (a_Element->QueryStringAttribute("SecondName", &temp) == XML_SUCCESS)
	{
		secondName = std::string(temp);
	}

	if (a_Element->QueryIntAttribute("Age", &IntValue) == XML_SUCCESS)
	{
		age = IntValue;
	}


	return new Person(firstName, secondName, age);
}
