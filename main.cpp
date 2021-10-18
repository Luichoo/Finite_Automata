/**
 * @file main.cpp
 * @authors Luis Blanco - Alejandro Salas
 * @brief Management of a finite automata
 * @version 0.1
 * @date 2021-10-09
 * 
 * 
 */
#include <iostream>
#include <string.h>
#include "graph.h"
#include "filecheck.h"


using namespace std;


#define MAXDATA 100

int main(){
N *states;
states = NULL;
string value;
string state;
bool check = true;
int data=0;
char *V=new char[MAXDATA];
system("cls");

if(fcharge(&states,V,&data))
    cout << "Automata is ready\n" <<data<< endl;

int opc = 0,times = 0;

while(true){
    cout << "Menu\n1.Insert States\n2.Insert Connections\n3.Display States\n4.Display Final States\n5.Display matrix\n0.Exit" << endl;
    validateInput(&opc);
    system("cls");
    cout<<endl;
    switch(opc){
        case 1:
            cout<<"Option 1: insert state\n"<<endl;
            times = 0;
            validateInput(&state);
            check = node_exist(states,state);
            while(check && times < 2)
            {
                cout << "invalid input, the state already exist" << endl;
                validateInput(&state);
                check = node_exist(states,state);
                times += 1;
            }
            if(times == 2 && check){
                cout << "Too many errors, going back to menu" << endl;
                break;
            }
            check = insert_state(&states,state,false);
            cout << endl;
            if(check){
                cout << "Success" << endl;
            }
            else{
                cout << "Fail" << endl;
            }

            break;
        case 2:
            if(states){
                check = insert_adj(&states,V,&data);
                cout << endl;
                if(check){
                    cout << "Success" << endl;
                }
                else{
                    cout << "Fail" << endl;
                }                
            }
            else
                cout << "The automata is empty" << endl << endl;
            break;
        case 3:
            if(states)
                display_ALL(states);
            else
                cout << "The automata is empty" << endl << endl;
            break;
        case 4:
            if(states)
                display_final_States(states);
            else
                cout << "The automata is empty" << endl << endl;
            break;
        case 5:
            if(states)
                automata_matrix(states,data,V);
            else
                cout << "The automata is empty" << endl << endl;   
            break;
        case 0:
            cout << "Tschusss";
            exit(EXIT_SUCCESS);
            break;  
        default:
            cout << "\nInvalid option" << endl;              
    }
    system("pause");
    system("cls");
}
return EXIT_FAILURE;
}
