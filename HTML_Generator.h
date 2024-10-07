#pragma once
#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Generator.h"

using namespace std;


class HTML_Generator:virtual public Generator{

public:


    HTML_Generator(string xmlFile):Generator(xmlFile)
    {

    }
    ~HTML_Generator(){

    }


    void genFile(string fileName)override;


};

#endif // HTML_GENERATOR_H
