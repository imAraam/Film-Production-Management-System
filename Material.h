#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material
{
private:
	//Can contain multiple language tracks and subtitles in different languages
	bool isSingleDVD;
	bool isDoubleDVD; 
	bool isBluRay;

	//They may also contain bonus features 
	//(additional material such as short films or director comments of the production) --------Need to add-------------


public:

	double idNumber; 
	std::string title; //Could be different from project/film title
	std::string format;
	std::string audioFormat; //Dolby, Dolby digital, MPEG-1, PCM or DTS
	std::string runTime;
	std::string language;
	double retailPrice;
	std::string subtitles; 
	double frameAspect; //Wide screen

	Material(double idN, std::string titleString, std::string formatString, std::string audio, std::string runT, std::string languageString, double price, std::string subtitleString, double frame)
	{
		idN = idNumber;
		titleString = title;
		formatString = format;
		audio = audioFormat;
		runT = runTime;
		languageString = language;
		price = retailPrice;
		subtitleString = subtitles;
		frame = frameAspect;
	}

	std::string getMaterialType(); //returns the material type by setting one of the private data members to true

	double getID()
	{
		return idNumber;
	}//retrieves the ID of the material returned by getMaterialType

	std::string getTitle();//^^

	std::string getFormat(); 

	std::string getAudioFormat();

	std::string getrunTime();

	std::string getLanguage();

	double getRetailPrice();

	std::string getSubtitle();

	double getFrameAspect();

	void getDVDpackage();//retrieves plastic box packaging for single or double DVDS

	void getBluRayPackage();//retrieves plastic box packaging (different size) for blue-rays
};


#endif
