#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "Material_Base.h"


void Material::displayVector(const std::vector<Material>& vectorOfObjects, std::string m, std::string p)
{
	size_t size = vectorOfObjects.size();

	for (unsigned int i = 0; i < size; i++)
	{
		if (m == "Combo Box") // To identify the different DVDs of the combo box
		{
			std::cout << "DVD " << i + 1 << "\n" << std::endl;
		}
		else if (m == "Double DVD") // To identify the different sides of the double DVD
		{
			if (i == 0) 
			{
				std::cout << "Front side:" << "\n" << std::endl;
			}
			else if (i == 1)
			{
				std::cout << "Back side:" << "\n" << std::endl;
			}
		}
		std::cout << "The Material is: " << m << std::endl;

		std::cout << "The ID is: " << vectorOfObjects[i].getID() << std::endl; //Use private accessor functions to retrieve
		//respective data for materials
		std::cout << "The title is: " << vectorOfObjects[i].getTitle() << std::endl;
		std::cout << "The format is: " << vectorOfObjects[i].getFormat() << std::endl;
		std::cout << "The audio-format is: " << vectorOfObjects[i].getAudioFormat() << std::endl;
		std::cout << "The run-time is: " << vectorOfObjects[i].getRunTime() << std::endl;
		std::cout << "The language(s) available: ";
		int v_s = vectorOfObjects[i].l_i; //Set the vector size variable to the size of the instance of vector in object

		language.resize(v_s);//Resize vector data member from Material class to avoid out of range error 
							//when trying to display elements
		size_t size_l = language.size();
		for (unsigned int l = 0; l < size_l; l++)
		{
			std::cout << vectorOfObjects[i].language[l];
			std::cout << "\t";
		}
		std::cout << "\n";
		std::cout << "The retail-price is: " << vectorOfObjects[i].getRetailPrice() << std::endl;
		std::cout << "The subtitle(s) available: ";
		int s_s = vectorOfObjects[i].s_i;
		subtitles.resize(s_s);
		size_t size_s = subtitles.size();
		for (unsigned int s = 0; s < size_s; s++)
		{
			std::cout << vectorOfObjects[i].subtitles[s];
			std::cout << "\t";
		}
		std::cout << "\n";
		std::cout << "The frame-aspect is: " << vectorOfObjects[i].getFrameAspect() << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "The packaging specifications: " << p << std::endl;

		std::cout << "\n\n";
	}
}

void Material::getVectorData(std::vector <Material>& vectorOfObjects, std::string m)
{
	//Used to validate integer and double type value input
	std::string line;

	//Boolean variables used to allow the user to add multiple languages to the vectors
	bool anotherLanguage = true;
	bool anotherSubtitle = true;

	//Variables to take the user input and pass it to the object constructor
	long int id;
	std::string t, f, a, rt, l, s;
	std::vector <std::string> l_vector;
	double p, fr;
	std::vector <std::string> s_vector;
	int la_in = 0;
	int su_in = 0;

	if (m == "Combo Box" && (vectorOfObjects.empty())) //As a combo box set can include either 2 or 3 DVDs
	//2nd condition to ensure message is only displayed once at the start, empty() comparison used as it will  
	//not be empty after the first object is added to the vector
	{
		std::cout << "How many DVDs do you wish to include in your combo set? (2 or 3)" << std::endl;
		std::cin >> comboSetDVD;
		//input validation to insure the user does not enter more than 3 or less than 2
		while (comboSetDVD != 2 && comboSetDVD != 3)
		{
			std::cout << "Please enter a valid number!" << std::endl;
			std::cout << "How many DVDs do you wish to include in your combo set? (2 or 3)" << std::endl;
			std::cin >> comboSetDVD;
		}
	}
	else if (m == "Double DVD" && (vectorOfObjects.empty())) //Print a message to inform the user of which side they are 
	//entering details on if it's a double DVD
	{
		std::cout << "Please enter the details of the front side and then the back side of the Double DVD:" << std::endl;
	}

	std::cout << "\n\n";
	std::cout << "Enter the ID number: ";
	//input validation to insure input type is an integer
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> id)
		{
			if (ss.eof()) //If it successfuly reaches the end of file without encountering an error then the cin operation 
			{   // was a success
				break;
			}
		}
		std::cout << "Please enter a valid number!" << std::endl; //If the entire line could not be successfully converted to an int
	}

	std::cout << "Enter the title: ";
	std::getline(std::cin, t);
	std::cout << "Enter the format: ";
	std::getline(std::cin, f);
	std::cout << "Enter the audio-format: ";
	std::getline(std::cin, a);
	std::cout << "Enter the run-time: ";
	std::getline(std::cin, rt);
	std::cout << "Enter the language(s): ";
	std::getline(std::cin, l);
	la_in++; //Increment variable once for the first language added
	l_vector.push_back(l);
	do {
		char add;
		std::cout << "Do you wish to add another language? (y/n): ";
		std::cin >> add;
		add = toupper(add);
		std::cout << "\n";
		//Char input validation to insure either 'Y' or 'N' are entered
		while (add != 'Y' && add != 'N')
		{
			std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
			std::cout << "Do you wish to add another language? (y/n): ";
			std::cin >> add;
			add = toupper(add);
		}
		if (add == 'Y')
		{
			la_in++; //Increment everytime the user adds a new language
			std::cout << "Enter another language: ";
			std::cin.ignore(); //To flush input stream for successful subsequent inputs
			std::getline(std::cin, l);
			std::cout << "\n";
			l_vector.push_back(l); //Add another language to the language vector
		}
		else if (add == 'N')
		{
			anotherLanguage = false;
		}

	} while (anotherLanguage == true);

	std::cin.ignore();
	std::cout << "Enter the price: ";
	//input validation to insure input type is a double
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> p)
		{
			if (ss.eof())  
			{   
				break;
			}
		}
		std::cout << "Please enter a valid number!" << std::endl; 
	}

	if (m == "VHS") // As VHS can only hold 1 subtitle
	{
		std::cout << "Enter the subtitle(s): ";
		std::cin.ignore(); //To flush input stream for successful subsequent inputs
		std::getline(std::cin, s);
		su_in++;
		s_vector.push_back(s);
	}
	else 
	{
		std::cout << "Enter the subtitle(s): ";
		std::getline(std::cin, s);
		su_in++;
		s_vector.push_back(s);
		do {
			char add;
			std::cout << "Do you wish to add another subtitle? (y/n): ";
			std::cin >> add;
			add = toupper(add);
			std::cout << "\n";
			//Char input validation to insure either 'Y' or 'N' are entered
			while (add != 'Y' && add != 'N')
			{
				std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
				std::cout << "Do you wish to add another subtitle? (y/n): ";
				std::cin >> add;
				add = toupper(add);
			}
			if (add == 'Y')
			{
				su_in++;
				std::cout << "Enter another subtitle: ";
				std::cin.ignore();
				std::getline(std::cin, s);
				std::cout << "\n";
				s_vector.push_back(s);
			}
			else if (add == 'N')
			{
				anotherSubtitle = false;
			}

		} while (anotherSubtitle == true);
	}

	std::cout << "Enter the frame-aspect: ";
	std::cin.ignore();
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> fr)
		{
			if (ss.eof())
			{
				break;
			}
		}
		std::cout << "Please enter a valid number!" << std::endl;
	}


	std::cout << "\n\n\n";


	Material newM(id, t, f, a, rt, l_vector, p, s_vector, fr, la_in, su_in); //Pass the variables to the object constructor
	vectorOfObjects.push_back(newM); //Push back the object in the vector of objects
}

void Material::anotherObject(std::vector <Material>& vectorOfObjects, std::string m)
{
	if (m == "Combo Box" && comboSetDVD == 2)// If the user requests 2 DVDs
	{
		getVectorData(vectorOfObjects, m); //Only 1 as main already calls getVectorData() so the function is called twice
	}
	else if (m == "Combo Box" && comboSetDVD == 3) //If the user requests 3 DVDs
	{
		getVectorData(vectorOfObjects, m);
		getVectorData(vectorOfObjects, m);
	}
	else if (m == "Double DVD")
	{
		getVectorData(vectorOfObjects, m);//For the back side
	}
	
	std::cout << "\n\n";

}


//Accessor functions

double Material::getID() const
{
	return idNumber;
}

std::string Material::getTitle() const
{
	return title;
}

std::string Material::getFormat() const
{
	return format;
}

std::string Material::getAudioFormat() const
{
	return audioFormat;
}

std::string Material::getRunTime() const
{
	return runTime;
}

std::vector <std::string> Material::getLanguage() const
{
	return language;
}

double Material::getRetailPrice() const
{
	return retailPrice;
}

std::vector <std::string> Material::getSubtitle() const
{
	return subtitles;
}

double Material::getFrameAspect() const
{
	return frameAspect;
}
