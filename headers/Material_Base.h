#ifndef MATERIAL_BASE_H
#define MATERIAL_BASE_H

#include <string>
#include <vector>

class Material
{
private:

	int l_i = 0; //Used in getVectorData() to set the language object vector size to the number of languages the 
			//user wishes to add for that object
	int s_i = 0;

	int comboSetDVD = 0; //As a combo set can include 2 or 3 DVDs, this variable is used to prompt the user for one or the other

	long int idNumber = 0;
	std::string title; 
	std::string format;
	std::string audioFormat; //Dolby, Dolby digital, MPEG-1, PCM or DTS
	std::string runTime;
	std::vector <std::string> language;
	double retailPrice;
	std::vector <std::string> subtitles;
	double frameAspect; //Wide screen


	//Accessor functions

	double getID() const;//retrieves the ID of the material. 
						//const as this function is only intended to print, not modify the value

	std::string getTitle() const;//^^

	std::string getFormat() const;

	std::string getAudioFormat() const;

	std::string getRunTime() const;

	std::vector <std::string> getLanguage() const;

	double getRetailPrice() const;

	std::vector <std::string> getSubtitle() const;

	double getFrameAspect() const;



public:

	Material() //Default constructor
	{

	}

	//Parameterized constructor
	Material(long int idN, std::string titleString, std::string formatString, std::string audio, std::string runT,
		std::vector <std::string> languageString, double price, std::vector <std::string> subtitleString, double frame, int la_in,
		int su_in)
	{
		idNumber = idN;
		title = titleString;
		format = formatString;
		audioFormat = audio;
		runTime = runT;
		language = languageString;
		retailPrice = price;
		subtitles = subtitleString;
		frameAspect = frame;
		l_i = la_in; //increment variable included in constructor as it is needed to track the number of languages the user wishes
					//to add for each material object
		s_i = su_in;//^^
	}


	void displayVector(const std::vector <Material>&, std::string, std::string); //Prints the type Material vector of object(s)
									//& operator as vectors are costly to call

	void getVectorData(std::vector <Material>& vectorOfObjects, std::string); //Populates the vector with data from the user at run time

	void anotherObject(std::vector <Material>& vectorOfObjects, std::string); //Allows the creation of further objects for
	//combo sets or double sided DVDs
};


#endif
