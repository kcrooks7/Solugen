#pragma once
#include "HTML_Generator.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Helpers.h"

using namespace std;


//Test if a tag has a closing backslash. 0 for no, 1 for yes infront, 2 for yes at the back.
    int isCloser(string HTMLTag){

        int isCL=0;
        int TagLength;
        TagLength =((HTMLTag.size())-1);
        if (HTMLTag[0]=='/'){
            isCL=1;
        }else if(HTMLTag[TagLength]=='/'){
            isCL=2;
        }else{
            isCL=0;
        }

        return isCL;
    }

void HTML_Generator::genFile(string fileName){

        OUTPUT_file.open(fileName);
        std::string HTMLLine = "";
        //HTML Line details.
        std::string HTMLTag = "";
        std::string HTMLContents ="";
        std::string HTMLAttribVal ="";
        std::string HTMLRegex = "";

        std::string TAG_name="";

        stack<string> Closer;
        int CloserResult=0;


        OUTPUT_file<<"<!DOCTYPE html>"<<endl;
        OUTPUT_file<<"<HTML xmlns=\"http://www.w3.org/1999/xhtml\", xml:lang=\"en\">"<<endl;

        while (getline(File_data,OUTPUT_text)){

        //HTML_Generator Code
        while(OUTPUT_text[0]!= '<'){
            OUTPUT_text = OUTPUT_text.erase(0,1);
        }
        TAG_name = getTagName(OUTPUT_text);

        if(TAG_name == "record"){
                    HTMLTag.erase(std::remove_if(HTMLTag.begin(),HTMLTag.end(),::isspace),HTMLTag.end());

                    HTMLLine ="";
                    HTMLTag = "";
                    HTMLContents ="";
                    HTMLAttribVal ="";
                    HTMLRegex = "";
                }else if(TAG_name=="Element"){

                    HTMLTag = ""+getTagContent(OUTPUT_text);
                    cout<<getTagContent(OUTPUT_text);
                    //Remove white space.
                    HTMLTag.erase(std::remove_if(HTMLTag.begin(),HTMLTag.end(),::isspace),HTMLTag.end());

                }else if(TAG_name=="Contents"){

                    //Handle large contents in tag.
                    HTMLContents = ""+getTagContent(OUTPUT_text);
                    cout<<getTagContent(OUTPUT_text);

                }else if(TAG_name=="AttribVal"){

                    //Handle large attribute list.
                    HTMLAttribVal = ""+getTagContent(OUTPUT_text);
                    cout<<getTagContent(OUTPUT_text);

                }else if(TAG_name=="REGEX"){

                    HTMLRegex = ""+getTagContent(OUTPUT_text);
                    cout<<getTagContent(OUTPUT_text);

                }else if(TAG_name== "/record"){

                    //Use backslash for special characters. \" for quotes.

                    //Check if Tag is block or inline and handle accordingly.

                    //Check if Tag is Block or Inline.

                    if (isBlock(HTMLTag)){
                            HTMLTag.erase(std::remove_if(HTMLTag.begin(),HTMLTag.end(),::isspace),HTMLTag.end());
                            if(HTMLTag=="head"){
                                HTMLLine = "<" + HTMLTag + ">";
                                OUTPUT_file<<HTMLLine<<endl;
                                OUTPUT_file<<"\n";
                                Closer.push("</" + HTMLTag + ">");

                            }else if(HTMLTag=="body"){

                                OUTPUT_file<<Closer.top();
                                Closer.pop();
                                HTMLLine = "\n<" + HTMLTag + ">";
                                OUTPUT_file<<HTMLLine<<endl;
                                OUTPUT_file<<"\n";
                                Closer.push("</" + HTMLTag + ">");

                            }else if(Closer.top()=="</body>"){

                                HTMLLine = "\n<" + HTMLTag + " " + HTMLAttribVal + ">" + HTMLContents;
                                OUTPUT_file<<HTMLLine<<endl;
                                OUTPUT_file<<"\n";
                                Closer.push("</" + HTMLTag + ">");
                            }else{
                                OUTPUT_file<<Closer.top();
                                Closer.pop();
                                HTMLLine = "\n<" + HTMLTag + " " + HTMLAttribVal + ">" + HTMLContents;
                                OUTPUT_file<<HTMLLine<<endl;
                                OUTPUT_file<<"\n";
                                Closer.push("</" + HTMLTag + ">");


                            }

                    }else if(isInline(HTMLTag)){
                    HTMLLine = "<" + HTMLTag + " " + HTMLAttribVal + ">" + HTMLContents + "</" + HTMLTag + ">";
                    OUTPUT_file<<HTMLLine<<endl;
                    OUTPUT_file<<"\n";
                    }else{
                    HTMLTag = eraseWhiteSpace(HTMLTag);

                    if(HTMLTag=="drop_down_menu"){
                            HTMLLine = "<label for=\"my-dropdown\">Make a Choice:</label>\n"
                                        "<select id=\"my-dropdown\">\n"
                                        "<option value=\"Choice1\">Choice 1</option>\n"
                                        "<option value=\"Choice2\">Choice 2</option>\n"
                                        "<option value=\"Choice3\">Choice 3</option>\n"
                                        "<!-- Add more options as needed -->\n"
                                        "</select>\n";
                            OUTPUT_file<<HTMLLine<<endl;
                            OUTPUT_file<<"\n";
                    //Add others from 30 list and create own.
                    }else{
                    //Use comments....<!-- comments  -->
                    HTMLLine = "<!-- <" + HTMLTag + " " + HTMLAttribVal + ">" + HTMLContents + "</" + HTMLTag + "> -->";
                    OUTPUT_file<<HTMLLine<<endl;
                    OUTPUT_file<<"\n";

                    }



                    }

            }else if(TAG_name== "/HFI"){
                while(!Closer.empty()){
                OUTPUT_file<<Closer.top()<<endl;
                OUTPUT_file<<"\n";
                Closer.pop();

                }


                break;
            }else{


            }

        }
        OUTPUT_file<<"\n</HTML>";
        OUTPUT_file.close();
        File_data.close();

    }

