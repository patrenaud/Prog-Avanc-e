#include "tinyxml2.h"
#include <string>
#include <vector>
#include <iostream>
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
};

void CreateXmlFor(const Person* a_Person, XMLElement* a_Element);

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns></returns>
int main()
{
	std::vector<Person*> persons = std::vector<Person*>();
	persons.push_back(new Person("John", "Doe", 26));
	persons.push_back(new Person("Jane", "Doe", 25));
	persons.push_back(new Person("Willy", "Doe", 12));
	persons.push_back(new Person("Agathe", "Doe", 3));

	// création de doc
	XMLDocument xmlDoc;
	XMLElement* root = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(root);

	// Write	
	for (int i = 0; i < persons.size(); i++)
	{
		XMLElement* personElement = xmlDoc.NewElement("Person");
		CreateXmlFor(persons[i], personElement);
		root->InsertEndChild(personElement);
	}

	// Save failsafe
	if ((xmlDoc.SaveFile("file.xml")) == XML_SUCCESS)
	{
		std::cout << "Save success! " << std::endl;
	}
	else
	{
		std::cout << "Save failed" << std::endl;
	}

	for (std::vector<Person*>::iterator person = persons.begin(); person != persons.end(); person++)
	{
		delete *person;
		*person = nullptr;
	}
	persons.clear();

	return 0;
}

/// <summary>
/// Creates the XML element for the person in parameter. 
/// </summary>
/// <param name="a_Person">the person to add in the xml</param>
/// <param name="a_Element">the element to add attributes into</param>

void CreateXmlFor(const Person* a_Person, XMLElement* a_Element)
{
	a_Element->SetAttribute("Age", a_Person->age);
	a_Element->SetAttribute("SecondName", a_Person->secondName.c_str());
	a_Element->SetAttribute("FirstName", a_Person->firstName.c_str());
}
