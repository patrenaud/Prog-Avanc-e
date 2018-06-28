#include "tinyxml2.h"
#include <string>
#include <iostream>

using namespace tinyxml2;

XMLDocument& CreateDocument();
void SaveXML(XMLDocument& xmlDoc, const std::string filename);

void WriteIntXML(XMLDocument& xmlDoc);
void WriteStringXML(XMLDocument& xmlDoc);

void ReadXML(const std::string filename);

int main()
{
	// Create the xml document instance
	XMLDocument& xmlDoc = CreateDocument();

	WriteIntXML(xmlDoc);
	WriteStringXML(xmlDoc);

	SaveXML(xmlDoc, "file.xml");
	ReadXML("file.xml");

	system("pause");
	return 0;
}

XMLDocument& CreateDocument()
{
	// Création d'un document in insertion d'un premier enfant
	XMLDocument* xmlDoc = new XMLDocument();
	XMLElement* root = xmlDoc->NewElement("root");
	xmlDoc->InsertFirstChild(root);

	return *xmlDoc;
}

void SaveXML(XMLDocument& xmlDoc, const std::string filename)
{
	if (xmlDoc.SaveFile(filename.c_str()) == XML_SUCCESS)
	{
		std::cout << "Save success! " << std::endl;
	}
	else
	{
		std::cout << "Save failed" << std::endl;
	}
}

void WriteIntXML(XMLDocument& xmlDoc)
{
	XMLNode* intsElement = xmlDoc.NewElement("ints");
	for (int i = 0; i < 5; i++)
	{
		XMLElement* intElement = xmlDoc.NewElement("int");
		intElement->SetAttribute("index", i);
		intsElement->InsertEndChild(intElement);
	}

	xmlDoc.FirstChildElement()->InsertEndChild(intsElement);

	// Voici le résultat.
	//    <root>
	//		<ints>
	//		   <int "index" = 0>0</int>
	//		 </ints>
	//    <root>
}

void WriteStringXML(XMLDocument& xmlDoc)
{
	XMLNode* stringsElement = xmlDoc.NewElement("strings");
	for (int i = 0; i < 5; i++)
	{
		XMLElement* element = xmlDoc.NewElement("string");
		element->SetAttribute("index", i);
		element->SetText(("string # " + std::to_string(i)).c_str());
		stringsElement->InsertEndChild(element);
	}
	xmlDoc.FirstChildElement()->InsertEndChild(stringsElement);
}

void ReadXML(const std::string filename)
{
	XMLDocument xmlDoc;
	xmlDoc.LoadFile(filename.c_str());

	XMLElement* root = xmlDoc.FirstChildElement(/*root*/);
	XMLElement* intsElement = root->FirstChildElement("ints");

	XMLElement* element = intsElement->FirstChildElement();
	std::cout << "List of ints: " << std::endl;
	while (element != nullptr)
	{
		// element->GetText pour du texte
		int intValue;
		if (element->QueryIntAttribute("index", &intValue) == XML_SUCCESS)
		{
			std::cout << intValue << std::endl;
		}
		element = element->NextSiblingElement();
	}

	XMLElement* stringsElement = root->FirstChildElement("strings");
	element = stringsElement->FirstChildElement();

	std::cout << "List of strings " << std::endl;
	while (element != nullptr)
	{
		std::cout << element->GetText() << " : ";
		int intValue;
		if (element->QueryIntAttribute("index", &intValue) == XML_SUCCESS)
		{
			std::cout << intValue << std::endl;
		}
		element = element->NextSiblingElement();
	}
}