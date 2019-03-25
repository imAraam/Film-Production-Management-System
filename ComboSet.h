#ifndef COMBOSET_H
#define COMBOSET_H

#include "Material.h"
#include <string>

class ComboBox : public Material
{
public:

	ComboBox();

	bool isComboSet(); // returns true if material is a combo box set

	void getComboFeatures(); //retrieves unique features of combo box set (can have multiple DVDs) 

	void getComboPackage(); //retrieves cardboard box packaging
};




#endif
