#pragma once
#include "CSS_Generator.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <stack>
#include <cctype>
#include "Helpers.h"

using namespace std;




void CSS_Generator::genFile(string fileName){

        OUTPUT_file.open(fileName);
        //CSS Boxing schema specification is used for this genFile implementation.
        std::string CSS_Selector = "";
        //CSS Line details.
        std::string CSSWidth = "";
        std::string CSSHeight = "";
        std::string CSSPadding = "";
        std::string CSSBorder = "";
        std::string CSSMargin = "";
        std::string CSSOutline = "";
        std::string CSSBackgroundColor = "";
        std::string CSSColor = "";
        std::string CSSFont = "";
        std::string CSSTextDecoration = "";
        //Used for each block of CSS
        std::string CSS_Block="";

        std::string TAG_name="";

        stack<string> Closer;
        int CloserResult=0;


        OUTPUT_file<<"/*" + fileName + "*/\n"<<endl;


        while (getline(File_data,OUTPUT_text)){

        //CSS_Generator Code
        while(OUTPUT_text[0]!= '<'){
            OUTPUT_text = OUTPUT_text.erase(0,1);
        }
        TAG_name = getTagName(OUTPUT_text);

        if(TAG_name == "record"){


                    CSS_Selector.erase(std::remove_if(CSS_Selector.begin(),CSS_Selector.end(),::isspace),CSS_Selector.end());
                    //Head, Meta, Script,
                    CSSWidth = "";
                    CSSHeight = "";
                    CSSPadding = "";
                    CSSBorder = "";
                    CSSMargin = "";
                    CSSOutline = "";
                    CSSBackgroundColor = "";
                    CSSColor = "";
                    CSSFont = "";
                    CSSTextDecoration = "";

                    CSS_Block ="";

                }else if(TAG_name=="Element"){

                    CSS_Selector = ""+getTagContent(OUTPUT_text);
                    //Remove white space.
                    CSS_Selector.erase(std::remove_if(CSS_Selector.begin(),CSS_Selector.end(),::isspace),CSS_Selector.end());
                    if (CSS_Selector=="head"){
                        CSS_Selector = "*";
                    }

                }else if(TAG_name=="Width"){

                    //.
                    CSSWidth = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Height"){

                    //.
                     CSSHeight = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Padding"){

                    CSSPadding = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Border"){

                    CSSBorder = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Margin"){

                    CSSMargin = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="BackgroundColor"){

                    CSSBackgroundColor = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Color"){
                    //.
                     CSSColor = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="Font"){

                    CSSFont = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name=="TextDecoration"){

                    CSSTextDecoration = ""+getTagContent(OUTPUT_text);

                }else if(TAG_name== "/record"){

                    if(isValidSelector(CSS_Selector)){
                    CSS_Block = CSS_Selector  + "{" +
                                "width:" + CSSWidth + ";\n" +
                                "height:" + CSSHeight + ";\n" +
                                "padding:" + CSSPadding + ";\n" +
                                "border:" + CSSBorder + ";\n" +
                                "margin:" + CSSMargin + ";\n" +
                                "outline:" + CSSOutline + ";\n" +
                                "background-color:" + CSSBackgroundColor + ";\n" +
                                "color:" + CSSColor + ";\n" +
                                "font-family:" + CSSFont + ";\n" +
                                "text-decoration:" + CSSTextDecoration + ";\n" +
                                "\n}\n";
                                OUTPUT_file<<CSS_Block<<endl;

                    }else{

                    //Use comments if not valid..../*-- comments  --*/
                    CSS_Block = "/*" + CSS_Selector  + "{" +
                                "width:" + CSSWidth + ";\n" +
                                "height:" + CSSHeight + ";\n" +
                                "padding:" + CSSPadding + ";\n" +
                                "border:" + CSSBorder + ";\n" +
                                "margin:" + CSSMargin + ";\n" +
                                "outline:" + CSSOutline + ";\n" +
                                "background-color:" + CSSBackgroundColor + ";\n" +
                                "color:" + CSSColor + ";\n" +
                                "font-family:" + CSSFont + ";\n" +
                                "text-decoration:" + CSSTextDecoration + ";\n" +
                                "\n}\n*/";

                    OUTPUT_file<<" "<<endl;
                    OUTPUT_file<<"\n";

                    }
            }else if(TAG_name== "/CBF"){

                OUTPUT_file<<"\n";
                break;
            }else{


            }

        }
        OUTPUT_file<<"\n /*End of CSS File*/";
        OUTPUT_file.close();
        File_data.close();


}
