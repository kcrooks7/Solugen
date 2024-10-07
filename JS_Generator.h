#pragma once
#ifndef JS_GENERATOR_H
#define JS_GENERATOR_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Generator.h"

using namespace std;


class JS_Generator:virtual public Generator{

public:


    JS_Generator(string xmlFile):Generator(xmlFile)
    {
            //File_data.open(xmlFile);

    }
    ~JS_Generator(){

    }


    void genFile(string fileName)override;







};

#endif // JS_GENERATOR_H_INCLUDED
