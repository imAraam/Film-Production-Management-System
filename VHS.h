#ifndef VHS_H
#define VHS_H

#include "Material.h"
#include <string>

class Vhs : public Material
{
public:


	Vhs(); // Call Material constructor and assign values using local variable in the .cpp file

	bool isVHS(); //returns true if material is VHS

	void getVHSfeatures(); //retrieves unique features of VHS (only 1 subtitle and 1 audio track) 

	void getVHSpackage(); //retrieves plastic/cardboard packaging
};


#endif
