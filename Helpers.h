#pragma once
#ifndef HELPERS_H
#define HELPERS_H
#include <string>
#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>
using namespace std;


enum FILE_type{HTML,CSS,JS,PY,JV,CPP,SQL,TXT};
enum SQL_type{MYSQL,MSSQL,PGSQL,OTHER};
enum FILE_flag{DBF,HFI,CBF,CFF,JFF,JMF,JVF,PFI,CPF,ERR};


inline FILE_type getFileType(string FileString){

        if (FileString == "HTML"){
            return HTML;
        }else if(FileString == "CSS"){
            return CSS;
        }else if(FileString == "JS"){
            return JS;
        }else if(FileString == "PY"){
            return PY;
        }else if(FileString == "JV"){
            return JV;
        }else if(FileString == "CPP"){
            return CPP;
        }else if(FileString == "SQL"){
            return SQL;
        }else{
            return TXT;
        }

}

inline string getFTString(FILE_type F_type){

        if (F_type == HTML){
            return "HTML";
        }else if(F_type == CSS){
            return "CSS";
        }else if(F_type == JS){
            return "JS";
        }else if(F_type == PY){
            return "PY";
        }else if(F_type == JV){
            return "JV";
        }else if(F_type == CPP){
            return "CPP";
        }else if(F_type == SQL){
            return "SQL";
        }else{
            return "TXT";
        }

}


inline string getFTString(FILE_flag F_type){

        if (F_type == HFI){
            return "HTML";
        }else if(F_type == CBF){
            return "CSS";
        }else if(F_type == CFF){
            return "CSS";
        }else if(F_type == JMF){
            return "JS";
        }else if(F_type == JFF){
            return "JS";
        }else if(F_type == PFI){
            return "PY";
        }else if(F_type == JVF){
            return "JV";
        }else if(F_type == DBF){
            return "SQL";
        }else if(F_type == CPF){
            return "CPP";
        }else{
            return "TXT";
        }

}

inline FILE_flag getXMLFileFlag(string filename){

    //Needs to be redone
    string newLine;
    ifstream FILE_sent;
    FILE_sent.open(filename);
    string TAKE_3 = "";
    int i =0;


    while(getline(FILE_sent,newLine)){

       for(int linlength=1;linlength < newLine.length(); ++linlength){
        if(newLine[i] == '<'){
            for(int j=1;j<=3;++j){

            TAKE_3 = TAKE_3 + newLine[(i+j)];
            linlength = newLine.length();
            }
        }else{

        i+=1;
        }
       }

       if(TAKE_3 == "?xm"){
        TAKE_3="";
        continue;
       }else if(TAKE_3 == ""){
        continue;
       }else{

        break;
       }

    }

    FILE_sent.close();

    if (TAKE_3 == "HFI"){
            return HFI;
        }else if(TAKE_3 == "CBF"){
            return CBF;
        }else if(TAKE_3 == "CFF"){
            return CFF;
        }else if(TAKE_3 == "JMF"){
            return JMF;
        }else if(TAKE_3 == "JFF"){
            return JFF;
        }else if(TAKE_3 == "PFI"){
            return PFI;
        }else if(TAKE_3 == "JVF"){
            return JVF;
        }else if(TAKE_3 == "DBF"){
            return DBF;
        }else{
            return ERR;
        }
}


inline FILE_flag getFileFlag(ifstream openfile){

    FILE_flag FILEflag;
    FILEflag = ERR;


    return FILEflag;
}
#endif // HELPERS_H








