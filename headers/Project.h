#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

class Project
{
private:
	int l_i = 0;//Used in getVectorData() to set the locations object vector size to the number of locations the 
			//user wishes to add for that object
	int k_i = 0;


	std::string title;
	std::string summary;
	std::string genre;
	std::string releaseDate;
	std::vector <std::string> locations;
	std::string language;
	std::string runTime;
	std::vector <std::string> keywords;



	long double ticketSale = 0;
	std::string projectName;
	std::string projectStatus;


public:

	Project() //Default constructor
	{

	}

	//Parameterized constructor
	Project(std::string pName, std::string t, std::string s, std::string g, std::string dateOfRelease,
		std::vector <std::string> loc, std::string lang, std::string rT, std::vector <std::string> kw,
		int lo_in, int ke_in)
	{
		projectName = pName;
		title = t;
		summary = s;
		genre = g;
		releaseDate = dateOfRelease;
		locations = loc;
		language = lang;
		runTime = rT;
		keywords = kw;
		l_i = lo_in;
		k_i = ke_in;
	}

	std::string setProjectStatus();// switch statement, case 1 == released, case 2 == unreleased, case 3 == now playing

	/*Projects under production == "unreleased" (would have no associated materials)
	Projects no longer at cinemas == "released" (allows the addition of material information)
	Projects in cinemas == "now playing" (allows the addition of weekly set box office figures)*/

	void displayVector(const std::vector <Project>&);

	void getVectorData(std::vector <Project>& vectorOfObjects);

	void anotherObject(std::vector <Project>& vectorOfObjects);


	//write vector of projects
	void writeVectorOfProjects(std::vector<Project>);


	//Accessor functions

	std::string getProjectName() const; //retrieves the name of the project. 
						//const as this function is only intended to print, not modify the value

	std::string getTitle() const;

	std::string getSummary() const;

	std::string getGenre() const;

	std::string getReleaseDate() const;

	std::vector <std::string> getLocations() const;

	std::string getLanguage() const;

	std::string getRunTime() const;

	std::vector <std::string> getKeywords() const;

	long double getTicketSale() const;



	//Mutator function

	void setTicketSale(std::vector <Project>& vectorOfObjects);  
	//Only if setProjectStatus returns Now Playing can this member function retrieve its weekly box office ticket sales
	//Uses the vectorOfObjects to scan through the project names in order to find the correct project to add ticket sales to
};

#endif
