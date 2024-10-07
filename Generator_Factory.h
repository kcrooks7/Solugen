#pragma once
#ifndef GENERATOR_FACTORY_H
#define GENERATOR_FACTORY_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

class Generator_Factory{

public:
    Generator_Factory(){

    }
    ~Generator_Factory(){

    }
    FILE_flag XMLFile_flag;
    Generator* createGenerator(string xmlfile){

        XMLFile_flag = getXMLFileFlag(xmlfile);
        Generator* output = nullptr;
        switch(XMLFile_flag){
        case HFI:
            {
            cout<<"HTML File Generated";
            HTML_Generator* myGen = new HTML_Generator(xmlfile);
            output = myGen;
            break;
            }
        case CBF:
            {
            cout<<"CSS File Generated";
            CSS_Generator* CSSGen = new CSS_Generator(xmlfile);
            output = CSSGen;
            break;
            }
        case JMF:
            {
            cout<<"JavaScript File Generated";
            JS_Generator* JSGen = new JS_Generator(xmlfile);
            output = JSGen;
            break;
            }
        case JFF:
            break;
        case CFF:
            break;
        case DBF:
            break;
        default:
            cout<<"Case not found.";

        }
        return output;

    }



};


#endif // GENERATOR_FACTORY_H
