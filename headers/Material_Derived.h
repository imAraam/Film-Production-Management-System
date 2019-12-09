#ifndef MATERIAL_DERIVED_H
#define MATERIAL_DERIVED_H

#include "Material_Base.h"
#include <string>
#include <sstream>
#include <iostream>

class mType : public Material
{
public:
	std::string packagingSpecifications;
	std::string materialType;

	mType() 
	{

	}

	void getPackagingSpecs() //retrieves the correct type of packaging for each respective material
	{
		if (materialType == "Single DVD" || materialType == "Double DVD")
		{
			packagingSpecifications = "Plastic Box";
		}
		else if (materialType == "Blu-Ray")
		{
			packagingSpecifications = "Plastic Box (different size)";
		}
		else if (materialType == "Combo Box") 
		{
			packagingSpecifications = "Cardboard box";
		}
		else if (materialType == "VHS")
		{
			packagingSpecifications = "Plastic/Cardboard box";
		}
		else
		{
			packagingSpecifications = "";
		}
	}

	std::string getMaterialType(int get) //returns the material type using a switch case similarly to the project class
	{
		std::string line;
		std::cout << "Please enter a number to choose a material type for your project.\n" 
		<< "1 = Single DVD \t\t 2 = Double DVD \t 3 = Blu-Ray \t\t 4 = Combo Set \t\t\t5 = VHS" << std::endl;

		//Input validation to insure that the user inputs an integer
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
			std::cout << "\n\n";
			std::cout << "Please enter a valid number between 1-5!" << std::endl;
			std::cout << "Please enter a number to choose a material type.\n"
				<< "1 = Single DVD \t\t 2 = Double DVD \t 3 = Blu-Ray \t\t 4 = Combo Set \t\t\t5 = VHS" << std::endl;
		}
		
		std::cout << "\n\n" << std::endl;

		switch (get)
		{
		case 1:
			materialType = "Single DVD";
			break;
		case 2:
			materialType = "Double DVD"; 
			break;
		case 3:
			materialType = "Blu-Ray";
			break;
		case 4:
			materialType = "Combo Box"; // contains 2 or 3 DVDs
			break;
		case 5:
			materialType = "VHS";
			break;
		default:
			getMaterialType(get); //Should the user input an integer over 5 or under 1, recursion is invoker to insure the
			//user input a valid integer
			break;
		}

		return materialType;
	}
}; 

#endif