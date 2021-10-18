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
#include <vector>

using namespace std;

#define FILENAME "data.txt"

bool fcharge(N **states,char *V,int *counter){
    ifstream file;
    stringstream sstream;
    int pos=0,max;
    string text,aux,aux2,word;
    bool check;
    char delimiter =',',aux3;
    
    file.open(FILENAME, ios :: in);
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
            break;
        case 2:
            getline(file,text);
            sstream = (stringstream)text;
                while(getline(sstream, aux, delimiter)){
                check=node_final(*states, aux);
            }
            break;
        default:
            while(!file.eof()){

                getline(file,text);
                sstream = (stringstream)text;
                getline(sstream, aux, delimiter);
                getline(sstream, aux2, delimiter);
                getline(sstream, word, delimiter);
                
                if(aux=="\0"||aux2=="\0"||aux3=='\0')
                    break;

                aux3 = word[0];
                V[*counter]=aux3;
                *counter+=1;
                check = insert_adjF(&(*states),aux,aux2,aux3);
                
            }
            break;
        }
        pos+=1;
    }
    resize_data(V,&(*counter));
file.close();
return true;
}



#endif