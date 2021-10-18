/**
 * @file filecheck.h
 * @brief Header for charging the data 
 * @version 0.1
 * @date 2021-10-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */   
#ifndef FILECHECK_H_INCLUDED 
#define FILECHECK_H_INCLUDED

#include <iostream>
#include "graph.h"
#include <fstream>
#include <sstream>

using namespace std;

#define FILENAME "data.txt"

bool fcharge(N **states){
    ifstream file;
    stringstream sstream;
    int pos=0,max,counter=0;
    string text,aux,aux2,word;
    bool check;
    char delimiter =',',aux3;
    
    file.open("data.txt", ios :: in);
    if(file.fail()){
         cout << "File not found, The automata is empty " << endl << endl;
         return false;
    }
    while(!file.eof()){
        switch (pos)
        {
        case 0:
            getline(file,text);
            max = stoi(text);
            break;
        case 1:
            getline(file,text);
            sstream = (stringstream)text;
            while(getline(sstream,aux,delimiter)){
                check=insert_state(&(*states),aux,true);
            }
        case 2:
            getline(file,text);
            sstream = (stringstream)text;
                while(getline(sstream, aux, delimiter)){
                check=node_final(*states, aux);
            }
        default:
            while(!file.eof()){
                getline(file,text);
                sstream = (stringstream)text;
                getline(sstream, aux, delimiter);
                getline(sstream, aux2, delimiter);
                getline(sstream, word, delimiter);
                aux3 = word[0];
                    check = insert_adjF(&(*states),aux,aux2,aux3);
                
            }
            break;
        }
        pos+=1;
    }
file.close();
return true;
}



#endif