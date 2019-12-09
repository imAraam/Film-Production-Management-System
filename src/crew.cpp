#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "crew.h"

//-----------------------------------------------------------------------------------------------------------------------
void Crew::displayCrewVector(const std::vector<Crew>& vectorOfCrewObjects) {

	size_t size = vectorOfCrewObjects.size();

	for (unsigned int i = 0; i < size; i++) {
		std::cout << "\n\n\n";
		std::cout << "The producer is: " << vectorOfCrewObjects[i].getProducer() << std::endl;
		std::cout << "The director is: " << vectorOfCrewObjects[i].getDirector() << std::endl;
		std::cout << "The writer is: " << vectorOfCrewObjects[i].getWriter() << std::endl;
		std::cout << "The editor is: " << vectorOfCrewObjects[i].getEditor() << std::endl;
		std::cout << "The production designer is: " << vectorOfCrewObjects[i].getProductionDesigner() << std::endl;
		std::cout << "The set decorator is: " << vectorOfCrewObjects[i].getSetDecorator() << std::endl;
		std::cout << "The costume designer is: " << vectorOfCrewObjects[i].getCostumeDesigner() << std::endl;
		std::cout << "The cast are: ";

		//set cast vector size and print each member inside it 
		int vec_size = vectorOfCrewObjects[i].cast_number;//set the vector size to number of cast members

		cast.resize(vec_size);

		size_t size_cast = cast.size();

		//loop to print each cast member in the vector
		for (unsigned int c = 0; c < size_cast; c++) {
			std::cout << vectorOfCrewObjects[i].cast[c] << "\t";
		}
		std::cout << "\n" << std::endl;
	}

}
//----------------------------------------------------------------------------------------------------------------------

void Crew::getCrewVectorData(std::vector<Crew>& vectorOfCrewObjects) {
	//bool variable used to let the user add more than one cast member
	bool anotherCastMember = true;

	//variables to take user input and pass it to obhect constructor
	std::string pro;
	std::string dir;
	std::string wri;
	std::vector<std::string> cas_vec;
	std::string castMember;
	int castNumber = 0;
	std::string edi;
	std::string proDes;
	std::string setDec;
	std::string cosDes;
	std::string stringOfCast;

	std::cout << "Enter the producers name: ";
	std::getline(std::cin, pro);
	std::cout << "Enter the directors name: ";
	std::getline(std::cin, dir);
	std::cout << "Enter the writers name: ";
	std::getline(std::cin, wri);
	std::cout << "Enter the editors name: ";
	std::getline(std::cin, edi);
	std::cout << "Enter the production designers name: ";
	std::getline(std::cin, proDes);
	std::cout << "Enter the set decoraters name: ";
	std::getline(std::cin, setDec);
	std::cout << "Enter the costume designers name: ";
	std::getline(std::cin, cosDes);
	std::cout << "Enter a cast members name: ";
	std::getline(std::cin, castMember);
	castNumber++;//increment number of cast members
	cas_vec.push_back(castMember);
	do {

		char choice;
		std::cout << "Do you wish to add another cast member? (y/n): ";
		std::cin >> choice;
		choice = toupper(choice);
		std::cout << "\n";
		//Char input validation to insure either 'Y' or 'N' are entered
		while (choice != 'Y' && choice != 'N')
		{
			std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
			std::cout << "Do you wish to add another cast member? (y/n): ";
			std::cin >> choice;
			choice = toupper(choice);
		}
		if (choice == 'Y') {
			castNumber++;//increment number of cast members 
			std::cout << "Enter another cast member: ";
			std::cin.ignore(); //To flush input stream for successful subsequent inputs
			std::getline(std::cin, castMember);
			std::cout << "\n";
			cas_vec.push_back(castMember);
		}
		else if (choice == 'N') 
		{
			anotherCastMember = false;
		}
	} while (anotherCastMember == true);
	

	stringOfCast = Crew::setCastString(cas_vec);
	Crew newCrewObj(castNumber, pro, dir, wri, cas_vec, stringOfCast, edi, proDes, setDec, cosDes);//pass variables into object constructer
	vectorOfCrewObjects.push_back(newCrewObj);//push back vector of objects with current object
}
//-----------------------------------------------------------------------------------------------------------------------------------

void Crew::anotherCrewObject(std::vector<Crew>& vectorOfCrewObjects) {

	char choice;
	std::cout << "Do you wish to create another crew object? (y/n): " << std::endl;
	std::cin >> choice;
	choice = toupper(choice);
	//Input validation
	while (choice != 'Y' && choice != 'N')
	{
		std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
		std::cout << "Do you wish to create another crew object? (y/n): ";
		std::cin >> choice;
		choice = toupper(choice);
	}


	std::cout << "\n\n\n";
	if (choice == 'Y') {
		std::cin.ignore();
		getCrewVectorData(vectorOfCrewObjects);
	}
	
}

//accessor functions

std::string Crew::getProducer() const {
	return producer;
}

std::string Crew::getDirector() const {
	return director;
}

std::string Crew::getWriter() const {
	return writer;
}

std::vector<std::string> Crew::getCast() const {
	return cast;
}

std::string Crew::getEditor() const {
	return editor;
}

std::string Crew::getProductionDesigner() const {
	return productionDesigner;
}

std::string Crew::getSetDecorator() const {
	return setDecorator;
}

std::string Crew::getCostumeDesigner() const {
	return costumeDesigner;
}

//mutators

std::string Crew::setProducer() {
	std::cin >> producer;
	return producer;
}

std::string Crew::setDirector() {
	std::cin >> director;
	return director;
}

std::string Crew::setWriter() {
	std::cin >> writer;
	return writer;
}

std::vector<std::string> Crew::setCast() {
	bool t = true;
	char choice;
	std::string castMember;

	do {
		std::cin >> castMember;
		cast.push_back(castMember);

		std::cout << "do you want to add another cast member? (y/n): ";
		std::cin >> choice;

		if (toupper(choice) == 'N') {
			t = false;
		}
		else if (toupper(choice) == 'Y') {
			t = true;
		}
	} while (t == true);
	return cast;
}

std::string Crew::setEditor() {
	std::cin >> editor;
	return editor;
}

std::string Crew::setProductionDesigner() {
	std::cin >> productionDesigner;
	return productionDesigner;
}

std::string Crew::setSetDecorator() {
	std::cin >> setDecorator;
	return setDecorator;
}
std::string Crew::setCostumeDesigner() {
	std::cin >> costumeDesigner;
	return costumeDesigner;
}

std::string Crew::setCastString(std::vector<std::string>cast) {

	std::stringstream ss;
	for (size_t i = 0; i < cast.size(); i++) {
		if (i != 0)
			ss << ",";
		ss << cast[i];
	}
	std::string castString = ss.str();

	return castString;
}