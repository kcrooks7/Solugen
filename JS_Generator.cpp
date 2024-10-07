#pragma once
#include "JS_Generator.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Helpers.h"

using namespace std;

void JS_Generator::genFile(string fileName){

        OUTPUT_file.open(fileName);
        std::string Element_ID = "";
        //Javascript line details.
        std::string JSonclick = "";
        std::string JSondbclick ="";
        std::string JSonload ="";
        std::string JSonabort ="";
        std::string JSonmouseover ="";
        //Javascript block of code
        std::string JS_Block="";

        std::string TAG_name="";

        //Closing code
        stack<string> Closer;
        int CloserResult=0;

        OUTPUT_file<<"/*" + fileName + "*/\n"<<endl;

        while (getline(File_data,OUTPUT_text)){

        while(OUTPUT_text[0]!= '<'){
            OUTPUT_text = OUTPUT_text.erase(0,1);
        }
        TAG_name = getTagName(OUTPUT_text);

        if(TAG_name == "record"){
                    Element_ID.erase(std::remove_if(Element_ID.begin(),Element_ID.end(),::isspace),Element_ID.end());

                    std::string JSLine = "";
                    //HTML Line details.
                    std::string JSonclick = "";
                    std::string JSondbclick ="";
                    std::string JSonload ="";
                    std::string JSonabort ="";
                    std::string JSonmouseover ="";
                }else if(TAG_name=="Element"){

                    Element_ID = ""+getTagContent(OUTPUT_text);
                    //Remove white space.
                    Element_ID = eraseWhiteSpace(Element_ID);

                }else if(TAG_name=="onclick"){

                    //Handle large contents in tag.
                    JSonclick = ""+getTagContent(OUTPUT_text);


                }else if(TAG_name=="ondbclick"){

                    //Handle large attribute list.
                    JSondbclick = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="onload"){

                    JSonload = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="onabort"){

                    JSonabort = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="onmouseover"){

                    JSonmouseover = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name== "/record"){


                    JS_Block = "const " + Element_ID + "=document.getElementById(\"" + Element_ID + "\");\n" +
                                Element_ID +".addEventListener(\"click\", function() {\n" +
                                "/*Remove or Edit console message*/" +
                                "console.log(\"Element with ID: " + Element_ID + "clicked.\");\n" + JSonclick + "});\n";

                    JS_Block = JS_Block + "const " + Element_ID + "=document.getElementById(\"" + Element_ID + "\");\n" +
                                Element_ID +".addEventListener(\"dbclick\", function() {\n" +
                                "/*Remove or Edit console message*/" +
                                "console.log(\"Element with ID: " + Element_ID + " double clicked.\");\n" + JSondbclick +"});";

                    JS_Block = JS_Block + "const " + Element_ID + "=document.getElementById(\"" + Element_ID + "\");\n" +
                                Element_ID +".addEventListener(\"load\", function() {\n" +
                                "/*Remove or Edit console message*/" +
                                "console.log(\"Element with ID: " + Element_ID + " loaded.\");\n" + JSonload +"});";

                    JS_Block = JS_Block + "const " + Element_ID + "=document.getElementById(\"" + Element_ID + "\");\n" +
                                Element_ID +".addEventListener(\"abort\", function() {\n" +
                                "/*Remove or Edit console message*/" +
                                "console.log(\"Element with ID: " + Element_ID + " aborted.\");\n" + JSonabort +"});";


                    JS_Block = JS_Block + "const " + Element_ID + "=document.getElementById(\"" + Element_ID + "\");\n" +
                                Element_ID +".addEventListener(\"mouseover\", function() {\n" +
                                "/*Remove or Edit console message*/" +
                                "console.log(\"Element with ID: " + Element_ID + " mouse overed.\");\n" + JSonmouseover +"});";

                                OUTPUT_file<<JS_Block<<endl;



            }else if(TAG_name== "/JFI"){
                OUTPUT_file<<"\n";
                break;

            }else{


            }

        }
        OUTPUT_file<<"\n /*End of Javascript File*/";
        OUTPUT_file.close();
        File_data.close();

    }
