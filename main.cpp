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

void message(){
cout<<"  /$$$$$$             /$$                                          /$$           "<<endl;   
cout<<" /$$__  $$            | $$                                        | $$              "<<endl;
cout<<"| $$  \\ $$ /$$   /$$ /$$$$$$    /$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$    /$$$$$$ "<<endl;
cout<<"| $$$$$$$$| $$  | $$|_  $$_/   /$$__  $$| $$_  $$_  $$ |____  $$|_  $$_/   |____  $$"<<endl;
cout<<"| $$__  $$| $$  | $$  | $$    | $$  \\ $$| $$ \\ $$ \\ $$  /$$$$$$$  | $$      /$$$$$$$"<<endl;
cout<<"| $$  | $$| $$  | $$  | $$ /$$| $$  | $$| $$ | $$ | $$ /$$__  $$  | $$ /$$ /$$__  $$"<<endl;
cout<<"| $$  | $$|  $$$$$$/  |  $$$$/|  $$$$$$/| $$ | $$ | $$|  $$$$$$$  |  $$$$/|  $$$$$$$"<<endl;
cout<<"|__/  |__/ \\______/    \\___/   \\______/ |__/ |__/ |__/ \\_______/   \\___/   \\_______/"<<endl;
}
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
    cout << "\nThe Automata is ready\n"<< endl;

int opc = 0,times = 0;

while(true){
    message();
    cout << "Menu\n1.Insert States\n2.Insert Connections\n3.Display States\n4.Display Final States\n5.Display matrix\n0.Exit" << endl;
    validateInput(&opc);
    system("cls");
    message();
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
            cout<<"Option 2: insert Connections\n"<<endl;
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
            cout<<"Option 3: Display all\n"<<endl;
            if(states)
                display_ALL(states);
            else
                cout << "The automata is empty" << endl << endl;
            break;
        case 4:
            cout<<"Option 4: Display final states\n"<<endl;
            if(states)
                display_final_States(states);
            else
                cout << "The automata is empty" << endl << endl;
            break;
        case 5:
            cout<<"Option 5: Display matrix\n"<<endl;
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
