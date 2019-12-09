#pragma once
#ifndef CREW_H
#define CREW_H
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <iterator>

//Each project has a crew. This crew consists of all the people involved
//in the production of the film such as the producer, director, writer,
//cast (set of actors), editor, production designer, set decorator and costume designer

class Crew {

private:

	int cast_number = 0;//used to set cast vector size in getCrewVectorData(), to set cast vector size

	std::string producer;
	std::string director;
	std::string writer;
	std::vector <std::string> cast; //vector to store multiple actors (strings)
	std::string castString;
	std::string editor;
	std::string productionDesigner;
	std::string setDecorator;
	std::string costumeDesigner;

public:
	Crew() { //defeault constructor

	}

	//paramerterized constructor
	Crew(int cast_num, std::string prod, std::string dir, std::string writ, std::vector<std::string> c,std::string soc, std::string edit, std::string prodDes, std::string setDec, std::string cosDes) {
		cast_number = cast_num;
		producer = prod;
		director = dir;
		writer = writ;
		cast = c;
		castString = soc;
		editor = edit;
		productionDesigner = prodDes;
		setDecorator = setDec;
		costumeDesigner = cosDes;
	}

	void displayCrewVector(const std::vector<Crew>&);
	//prints the vector of crew objects

	void getCrewVectorData(std::vector<Crew>& vectorOfCrewObjects);
	//populates vector with data from user at run time

	void anotherCrewObject(std::vector <Crew>& vectorOfCrewObjects);
	//allows the creation and addition of another crew object

	//accessor functions-----------------------------------------
	std::string getProducer() const;

	std::string getDirector() const;

	std::string getWriter() const;

	std::vector<std::string> getCast() const;

	std::string getEditor() const;

	std::string getProductionDesigner() const;

	std::string getSetDecorator() const;

	std::string getCostumeDesigner() const;

	//mutator functions------------------------------------------
	std::string setProducer();

	std::string setDirector();

	std::string setWriter();

	std::vector<std::string> setCast();

	std::string setEditor();

	std::string setProductionDesigner();

	std::string setSetDecorator();

	std::string setCostumeDesigner();

	std::string setCastString(std::vector<std::string>); // take cast vector and turn it into a string

	//=======================================WRITE==========================================================



	//write crew member variables to stream objects
	friend std::ostream & operator << (std::ostream &out, const Crew &obj) {

		out << obj.cast_number
			<< "\n" << obj.producer 
			<< "\n" << obj.director
			<< "\n" << obj.writer
			<< "\n" << obj.castString // cast vector as a string
			<< "\n" << obj.editor
			<< "\n" << obj.productionDesigner
			<< "\n" << obj.setDecorator
			<< "\n" << obj.costumeDesigner
			<< std::endl;
		return out;
	}
	/*to write, in main put:
	*std::ofstream out("crews.txt") -- create outstream object
	*out << crew1 -- write the class object to the file
	*out.close()	-- stop the out stream
	*/

	void writeCrews(std::vector<Crew>); //writing function, does not return anything

	//====================================READ=====================================================================
	//read data from stream object and fill it in member variables
	friend std::istream & operator >> (std::istream &in, Crew &obj) {
		in >> obj.cast_number;
		in >> obj.producer;
		in >> obj.director;
		in >> obj.writer;
		in >> obj.castString;//figure out vectors
		in >> obj.editor;
		in >> obj.productionDesigner;
		in >> obj.setDecorator;
		in >> obj.costumeDesigner;
		return in;
	}
	// to read, in main put:
	//std::ifstream in("crew.txt");
	//Crew crew1; -- declare object to store info about to be read
	//in>>crew1; 
	//in.close -- stop in stream

	std::vector<Crew> readCrews(); //returns vector of read crews

	//===================================================================================================

};
