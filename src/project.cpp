#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>

#include "Project.h"


void Project::displayVector(const std::vector <Project>& vectorOfObjects)
{
	size_t size = vectorOfObjects.size();


	std::cout << "\n";

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "The project name is: " << vectorOfObjects[i].getProjectName() << std::endl;
		std::cout << "\n";

		std::cout << "The title is: " << vectorOfObjects[i].getTitle() << std::endl;
		std::cout << "The summary is: " << vectorOfObjects[i].getSummary() << std::endl;
		std::cout << "The genre is: " << vectorOfObjects[i].getGenre() << std::endl;
		std::cout << "The release date is: " << vectorOfObjects[i].getReleaseDate() << std::endl;



		std::cout << "The location(s) available: ";
		int v_s = vectorOfObjects[i].l_i; //Set the vector size variable to the size of the instance of vector in object

		locations.resize(v_s);//Resize vector data member from Material class to avoid out of range error 
							//when trying to display elements
		size_t size_l = locations.size();
		for (unsigned int l = 0; l < size_l; l++)
		{
			std::cout << vectorOfObjects[i].locations[l];
			std::cout << "\t";
		}
		std::cout << "\n";



		std::cout << "The language available is: " << vectorOfObjects[i].getLanguage() << std::endl;
		std::cout << "The run-time is: " << vectorOfObjects[i].getRunTime() << std::endl;



		std::cout << "The keyword(s) available: ";
		int k_s = vectorOfObjects[i].k_i; //Set the vector size variable to the size of the instance of vector in object

		keywords.resize(k_s);//Resize vector data member from Material class to avoid out of range error 
							//when trying to display elements
		size_t size_k = keywords.size();
		for (unsigned int k = 0; k < size_k; k++)
		{
			std::cout << vectorOfObjects[i].keywords[k];
			std::cout << "\t";
		}
		std::cout << std::endl;
		std::cout << "The weekly ticket sale is: " << getTicketSale() << std::endl;
		std::cout << "\n\n";
	}

}

void Project::getVectorData(std::vector <Project>& vectorOfObjects)
{
	//Boolean variables used to allow the user to add multiple languages to the vectors
	bool anotherLocation = true;
	bool anotherKeyword = true;

	//day, month, year variables to allow the user to set a release date
	std::string day, month, year;
	int day_i, month_i, year_i;

	//Variables to take the user input and pass it to the object constructor
	std::string pName, t, s, g, re, l, lan, r, k;
	std::vector <std::string> l_vector;
	std::vector <std::string> k_vector;
	double sale = 0;
	int lo_in = 0;
	int ke_in = 0;

	if (projectStatus == "Released")
	{
		
		std::cin.clear(); //To flush input stream for successful subsequent inputs

		std::cout << "\n\n";

		std::cout << "Enter the project name: ";
		std::getline(std::cin, pName);

		std::cout << "Enter the title name: ";
		std::getline(std::cin, t);

		std::cout << "Enter the summary: ";
		std::getline(std::cin, s);

		std::cout << "Enter the genre: ";
		std::getline(std::cin, g);

		std::cout << "The release date" << std::endl;
		std::cout << "Enter the expected day of release: " << std::endl;
		//To make sure input is a valid number input in a string
		while (std::cin >> day)
		{
			std::stringstream ss(day);
			if (ss >> day_i)
			{
				if (ss.eof()) //If it successfuly reaches the end of file without encountering an error then the cin operation 
				{   // was a success
					break;
				}
			}
			std::cout << "Please enter a valid day!" << std::endl; //If the entire line could not be successfully converted to an int
		}
		std::cout << "Enter the expected month of release: " << std::endl;
		while (std::cin >> month)
		{
			std::stringstream ss(month);
			if (ss >> month_i)
			{
				if (ss.eof()) 
				{   
					break;
				}
			}
			std::cout << "Please enter a valid month!" << std::endl; 
		}
		std::cout << "Enter the expected year of release: " << std::endl;
		while (std::cin >> year)
		{
			std::stringstream ss(year);
			if (ss >> year_i)
			{
				if (ss.eof()) 
				{   
					break;
				}
			}
			std::cout << "Please enter a valid year!" << std::endl;
		}
		re = day + '/' + month + '/' + year; //Concatenate date strings to return proper date format

		std::cout << "Enter the location: ";
		std::cin.ignore();
		std::getline(std::cin, l);
		lo_in++; //Increment variable once for the first location added
		l_vector.push_back(l);
		do {
			char add;
			std::cout << "Do you wish to add another location? (y/n): ";
			std::cin >> add;
			add = toupper(add);
			//Char input validation to insure either 'Y' or 'N' are entered
			while (add != 'Y' && add != 'N')
			{
				std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
				std::cout << "Do you wish to add another location? (y/n): ";
				std::cin >> add;
				add = toupper(add);
			}
			if (add == 'Y')
			{
				lo_in++; //Increment everytime the user adds a new language
				std::cout << "Enter another location: ";
				std::cin.ignore(); //Flush user input to allow user to be prompted for another location
				std::getline(std::cin, l);
				std::cout << "\n";
				l_vector.push_back(l); //Add another location to the location vector 
			}
			else if (add == 'N')
			{
				anotherLocation = false;
			}

		} while (anotherLocation == true);

		std::cin.ignore();
		std::cout << "Enter the language: ";
		std::getline(std::cin, lan);

		std::cout << "Enter the run-time: ";
		std::getline(std::cin, r);

		std::cout << "Enter the keyword: ";
		std::getline(std::cin, k);
		ke_in++;
		k_vector.push_back(k);
		do {
			char add;
			std::cout << "Do you wish to add another keyword? (y/n): ";
			std::cin >> add;
			add = toupper(add);

			while (add != 'Y' && add != 'N')
			{
				std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
				std::cout << "Do you wish to add another keyword? (y/n): ";
				std::cin >> add;
				add = toupper(add);
			}
			if (add == 'Y')
			{
				ke_in++;
				std::cout << "Enter another keyword: ";
				std::cin.ignore();
				std::getline(std::cin, k);
				std::cout << "\n";
				k_vector.push_back(k);
			}
			else if (add == 'N')
			{
				anotherKeyword = false;
			}

		} while (anotherKeyword == true);

		std::cout << "\n\n\n";

		Project newP(pName, t, s, g, re, l_vector, lan, r, k_vector, lo_in, ke_in); //Pass the variables to the object constructor
		vectorOfObjects.push_back(newP); //Push back the object in the vector of objects
	}
}

void Project::anotherObject(std::vector <Project>& vectorOfObjects)
{
	char add;

	if (projectStatus == "Released")
	{
		std::cout << "Do you wish to add another project? (y/n) ";
		std::cin >> add;
		add = toupper(add);

		while (add != 'Y' && add != 'N')
		{
			std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
			std::cout << "Do you wish to add another project? (y/n) ";
			std::cin >> add;
			add = toupper(add);
		}
		if (add == 'Y')
		{
			std::cin.ignore();
			getVectorData(vectorOfObjects);
			std::cout << "\n\n";
			anotherObject(vectorOfObjects);
		}
	}
	else
	{
		std::cout << "Another project cannot be added" << std::endl;
	}
	std::cout << "\n" << std::endl;
}

std::string Project::setProjectStatus()
{
	std::string line;
	int get;
	std::cout << "Please enter the project status for your project (1 = Released, 2 = Unreleased, 3 = Now Playing): ";


	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> get)
		{
			if (ss.eof()) 
			{  
				break;
			}
		}
		if (!line.empty())
		{
			std::cout << "Please enter a valid number between 1-3!" << std::endl;
			std::cout << "Please enter the project status for your project (1 = Released, 2 = Unreleased, 3 = Now Playing): ";
		}
	}

	switch (get)
	{
	case 1:
		projectStatus = "Released";
		break;
	case 2:
		projectStatus = "Unreleased";
		break;
	case 3:
		projectStatus = "Now Playing";
		break;
	default:
		setProjectStatus();
	}
	std::cout << "\n\n";
	

	return projectStatus;
}


//Accessors

std::string Project::getProjectName() const
{
	return projectName;
}

std::string Project::getTitle() const
{
	return title;
}

std::string Project::getSummary() const
{
	return summary;
}

std::string Project::getGenre() const
{
	return genre;
}

std::string Project::getReleaseDate() const
{
	return releaseDate;
}

std::vector <std::string> Project::getLocations() const
{
	return locations;
}

std::string Project::getLanguage() const
{
	return language;
}

std::string Project::getRunTime() const
{
	return runTime;
}

std::vector <std::string> Project::getKeywords() const
{
	return keywords;
}

long double Project::getTicketSale() const
{
	return ticketSale;
}



//Mutators

void Project::setTicketSale(std::vector <Project>& vectorOfObjects) //Take in a vector of objects parameter to allow 
//the function to compare project names until the correct one is found
{

	if (projectStatus == "Now Playing") //Only allow the addition of weekly ticket sales if the project status is 'Now Playing'
	{
		size_t size = vectorOfObjects.size();

		std::string pName;

		std::cout << "Enter the name of the project you wish to add ticket sales to: ";
		std::cin >> pName;

		std::cout << "\n";

		for (unsigned int i = 0; i < size; i++)
		{
			if (vectorOfObjects[i].getProjectName() == pName) //Loop until the correct project name is found to add ticket sales to
			{
				std::string line;
				std::cout << "Enter the weekly ticket sale for " << pName << " : " << std::endl;
				std::getline(std::cin, line);

				//To make sure input is a valid number input
				while (std::getline(std::cin, line))
				{
					std::stringstream ss(line);
					if (ss >> ticketSale)
					{
						if (ss.eof()) //If it successfuly reaches the end of file without encountering an error then the cin operation 
						{   // was a success
							break;
						}
					}
					std::cout << "Error!" << std::endl; //If the entire line could not be successfully converted to a double
				}
			}
		}
	}
	else
	{
		std::cout << "Project status is not 'Now Playing'." << std::endl;
		std::cout << "\n\n";
	}
	
}

//write vector of projects to file
void Project::writeVectorOfProjects(std::vector<Project> vecOfProj) {

	std::ofstream file("projects.txt"); //open file stream 

	for (int p = 0; p < sizeof(vecOfProj); p++) { //for each element(project) in the vector:

												 //once in file, data should be displayed as:
												///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
												//// l_i	k_i	title	summary	genre	releaseDate	(location	location	location)	language	runTime		(keyword	keyword)	ticketsale	projectName	projectStatus	///////
												//// l_i	k_i	title	summary	genre	releaseDate	(location	location)	language	runTime		(keyword)	ticketsale	projectName	projectStatus							///////
												//// l_i	k_i	title	summary	genre	releaseDate	(location)	language	runTime		(keyword	keyword		keyword)	ticketsale	projectName	projectStatus				///////
												///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		std::string locations;
		for (int lv = 0; lv < vecOfProj[p].l_i; lv++) { //for each element in locations vector:

			locations += (vecOfProj[p].locations[lv] + "\t"); // add each location to string with tabs between them

		}

		std::string keywords;
		for (int kv = 0; kv < vecOfProj[p].k_i; kv++) { //for each element in keywords vector:

			keywords += (vecOfProj[p].keywords[kv] + "\t");//add each keyword to string with tabs between them

		}

		file << vecOfProj[p].l_i //size of locations
			<< "\t" << vecOfProj[p].k_i //size of keywords
			<< "\t" << vecOfProj[p].title
			<< "\t" << vecOfProj[p].summary
			<< "\t" << vecOfProj[p].genre
			<< "\t" << vecOfProj[p].releaseDate
			<< "\t" << locations //locations vector need to figure out how to write each element  (not standard size)
			<< "\t" << vecOfProj[p].language
			<< "\t" << vecOfProj[p].runTime
			<< "\t" << keywords //keywords vector need to figure out how to write each element (not standard size)
			<< "\t" << vecOfProj[p].ticketSale
			<< "\t" << vecOfProj[p].projectName
			<< "\t" << vecOfProj[p].projectStatus
			<< "\n"; //next project starts on new line


	}


}
