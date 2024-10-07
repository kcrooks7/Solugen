#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "Helpers.h"
#include "HTML_Generator.h"
#include "CSS_Generator.h"
#include "JS_Generator.h"
#include "Generator_Factory.h"


using namespace std;

//Naming Convention: Capital Letter, Underscore then common letters for properties.
//common letters for methods no underscore followed by capitalized words. Main concerns first followed by
//secondary concern. Input variables are open.


//OOP Patterns...We use the Factory Pattern here, Use Virtual Inheritance to avoid Diamond conflict.


int main(){



    string XML_file;
    string OUTPUT_file;
    string FILE_text;
    FILE_flag XMLFile_flag;


    //Set Directory
    //Exception Handling


    //Gets one XML file
    //Exception Handling

    cout << "Select an XML file:";
    cin >> XML_file;

   	//Create New File
    //Exception Handling

    //Get flag from XML here.
    XMLFile_flag = getXMLFileFlag(XML_file);

    cout<< "Name your output file without extension:";
    cin >>OUTPUT_file;
    string fileName = "";

    //Choose code generator based on file flag.
    //Insert Factory Pattern Here
    Generator_Factory MyFactory;
    Generator* myGen = MyFactory.createGenerator(XML_file);
    fileName = OUTPUT_file + "." + getFTString(XMLFile_flag);
    myGen->genFile(fileName);
    delete myGen;


	//Print message and end program.
	cout << "\nFile "+ OUTPUT_file+"."+getFTString(XMLFile_flag) + " Done Processing.";

    return 0;

}
