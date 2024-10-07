#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Helpers.h"
using namespace std;

class Generator{

public:

    ifstream File_data;
    ofstream OUTPUT_file;
    string OUTPUT_text;


    Generator(string xmlFile) {

            //This method is safer.
            File_data.open(xmlFile);
    }


    Generator(){

    }
    virtual ~Generator(){

    }

    //Pure Virtual Function
    virtual void genFile(string fileName){};

    void closeFile(){

    if(File_data.is_open()){
            File_data.close();

    }

    }

    string getTagName(string xLine){
        //Assuming each line is well formed with one tag.
        //Dev must use the proper HTML code for angle brackets etc, --&lt;&gt;&amp;--.
        string TAG_name;
        int LINE_length = xLine.length();

        int i = 0;
        char  CUR_char = xLine[i];
        LINE_length-=1;
        while (i < LINE_length){

            if (CUR_char == '<'){
                i++;
                CUR_char = xLine[i];
                while(CUR_char != '>'){
                    TAG_name = TAG_name + CUR_char;
                    i++;
                    CUR_char = xLine[i];
                }
            }
            else{
                i++;

                }
        }

        return TAG_name;
    }


    string getTagContent(string xLine){
        //Assuming each line is well formed with one tag.
        //Dev must use the proper HTML code for angle brackets etc, --&lt;&gt;&amp;--.
        string TAG_content;
        int LINE_length = xLine.length();
        cout<<LINE_length;

        int i = 0;
        char  CUR_char = xLine[i];
        LINE_length-=1;
        cout<<CUR_char;cout<<"\n";
        while (i < LINE_length){

            if (CUR_char == '>'){
                cout<<"_IN_\n";
                i+=1;
                CUR_char = xLine[i];

                while(CUR_char != '<'){
                    cout<<CUR_char;cout<<"\n";
                    TAG_content = TAG_content + CUR_char;
                    i+=1;
                    CUR_char = xLine[i];

                }
                i=LINE_length;
                break;

            }
            else{
                i+=1;
                CUR_char = xLine[i];

            }

        }

        return TAG_content;
    }
    string eraseWhiteSpace(string theString){

        theString.erase(std::remove_if(theString.begin(),theString.end(),::isspace),theString.end());
        string outString = theString;
        return outString;
    }

    bool isBlock(string HTMLTag){

    bool isBL = false;
    int ArraySize = BLOCK_count;

    for(int j=0;j<=ArraySize-1;j++){

        if (HTMLTag==BLOCK_elements[j]){

            isBL=true;
            j=ArraySize-1;

        }else{

        }

    }

    return isBL;
    }

    bool isInline(string HTMLTag){

    bool result = false;
    int ArraySize = INLINE_count;
    for(int i=0;i<=ArraySize-1;i+=1){

        if (HTMLTag==INLINE_elements[i]){

            result=true;
            break;

        }else{

        }

    }

    return result;
    }

    //Array list of all HTML Block elements.
    //"head","body" are treated as block elements.
    static const int BLOCK_count = 38;
    string BLOCK_elements[BLOCK_count]{"head","body","address","article","aside","blockquote","canvas","dd","div","dl","dt","fieldset"
                        "figcaption","figure","footer","form","h1","h2","h3","h4","h5","h6","header",
                        "hr","li","main","nav","noscript","ol","p","pre","section","table","tfoot","ul","video","details","summary"};


    //Array list of all HTML Inline elements.
    //"title","style","link","meta","base" are treated as inline elements.
    static const int INLINE_count = 38;
    string INLINE_elements[INLINE_count]{"title","style","link","meta","base","a","abbr","acronym","b","bdo","big","br","button","cite","code","dfn","em","i","img","input"
                         "kbd","label","map","object","output","q","samp","script","select","small","span","strong","sub"
                         "sup","textarea","time","tt","var"};

};





#endif // GENERATOR_H
