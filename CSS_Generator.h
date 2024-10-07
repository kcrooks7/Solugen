#pragma once
#ifndef CSS_GENERATOR_H
#define CSS_GENERATOR_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Generator.h"

using namespace std;

class CSS_Generator:virtual public Generator{

public:

    CSS_Generator(string xmlFile):Generator(xmlFile)
    {
        //File_data.open(xmlFile);

    }
    ~CSS_Generator(){

    }

    void genFile(string fileName)override;

    bool isValidSelector(string Selector){
        bool IVS = true;

        string Selector1 = Selector;
        Selector.erase(std::remove_if(Selector.begin(),Selector.end(),::isspace),Selector.end());

        if (Selector1 == "*" ){
            IVS = true;
        }else if(isBlock(Selector1) || isInline(Selector1) ){
            IVS = true;
        }else if(hasSymbol(Selector1,'>')){

            IVS = (isInline(takeFront(Selector1,'>'))||isBlock(takeFront(Selector1,'>')))&&
                    (isInline(takeBack(Selector1,'>'))||isBlock(takeBack(Selector1,'>')));

        }else if(hasSymbol(Selector1,' ')){

            IVS = (isInline(takeFront(Selector1,' '))||isBlock(takeFront(Selector1,' ')))&&
                    (isInline(takeBack(Selector1,' '))||isBlock(takeBack(Selector1,' ')));

        }else if(hasSymbol(Selector1,'+')){

            IVS = (isInline(takeFront(Selector1,'+'))||isBlock(takeFront(Selector1,'+')))&&
                    (isInline(takeBack(Selector1,'+'))||isBlock(takeBack(Selector1,'+')));

        }else if(hasSymbol(Selector1,'~')){

            IVS = (isInline(takeFront(Selector1,'~'))||isBlock(takeFront(Selector1,'~')))&&
                    (isInline(takeBack(Selector1,'~'))||isBlock(takeBack(Selector1,'~')));

        }else if(hasSymbol(Selector1,'.')){

            IVS = (isInline(takeFront(Selector1,'.'))||isBlock(takeFront(Selector1,'.')));

        }else if(hasSymbol(Selector1,'#')){
            IVS = true;

        }
        return IVS;
    }



    bool hasSymbol(string testString,char theSymbol){
        bool HS = false;

        for(char i:testString){
                if(theSymbol==i){
                    HS = true;
                }
        }

        return HS;
    }
    string takeFront(string testString,char theSymbol){
        string thefront = "";

        for(char i:testString){
                if(theSymbol==i){
                    break;
                }else{
                    thefront = thefront + i;
                }
        }

        return thefront;

    }

    string takeBack(string testString,char theSymbol){
        string theBack = "";
        bool start = false;

        for(char i:testString){

                if(start){
                    theBack = theBack + i;
                }
                if(theSymbol==i){
                    start = true;
                }
        }
        theBack.erase(std::remove_if(theBack.begin(),theBack.end(),::isspace),theBack.end());
        return theBack;

    }

    private:





};





#endif // CSS_GENERATOR_H
