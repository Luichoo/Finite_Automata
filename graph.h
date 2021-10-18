/**
 * @file graph.h
 * @authors Luis Blanco - Alejandro Salas
 * @brief 
 * @version 0.1
 * @date 2021-10-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED


using namespace std;

typedef struct ady A;
typedef struct node N;


struct ady{
    N *node;
    char value;
    A *next;
};
struct node
{
    bool end;
    string state;
    A *adj;
    N *next;   
};

template <class T>

void validateInput(T *val)
{
    cout << "Enter input: ";
    while (true) {
        fflush(stdin);
        if (cin >> *val) {
            break;
            
        } else {
            cout << "\nEnter a valid value." << endl;
            cout << endl << "Enter input: ";
            cin.clear();
        }
    }
}

bool YNopt(){
    
    char opt;
    while(true){
        cout << "Enter Y/N:  ";cin >> opt;
        fflush(stdin);
        if(opt == 'y'||opt == 'Y'){
            return true;
        }
        else if(opt == 'n'||opt == 'N')
            return false;      
        cout << "Invalid value." << endl << endl;  
    }
    
}

void display_adj(A *adj, int i, string state){
    if(adj){
        cout << "\t" << i << ".-" << "  (" << state << ", " << adj->node->state << ", " << adj->value << ")" << endl;
        display_adj(adj->next,i += 1, state);
    }
}

void display_ALL(N *states){
    if(states){

        cout << "---------------------------------------------------" << endl;
        cout << "State: " << states->state << endl;
        if(states->end)
            cout << "Is Final: True" << endl;
        else
            cout << "Is Final: False" << endl;

        cout << "Connections: " << endl;
        if(!states->adj){
            cout << "No entries." << endl;
        }
        else{
            display_adj(states->adj, 1,states->state);
        }

        display_ALL(states->next);
    }
    else
        cout<<"---------------------------------------------------"<<endl;
         
}

void display_final_States(N *states){
    if(states){
        if(!states->end){
            display_final_States(states->next);
        }
        else{
            cout << "---------------------------------------------------" << endl;
            cout << "State: " << states->state << endl;
            if(states->end)
                cout << "Is Final: True" << endl;
            else
                cout << "Is Final: False" << endl;
            
            cout << "Connections: " << endl;
            if(!states->adj){
                cout << "No entries." << endl;
            }
            else{
                display_adj(states->adj, 1,states->state);
            }

            display_final_States(states->next);            
        }

    }
    else
        cout<<"---------------------------------------------------"<<endl;
         
}
bool node_final(N *states, string state){
    if(states){
        if(states->state == state){
            states->end = true;
            return true;            
        }
        else
            return node_final(states->next,state);
    }
    
    return false;
}

bool node_exist(N *states, string state){
    if(states){
        if(states->state == state)
            return true;
        else
            return node_exist(states->next,state);
    }
    
    return false;
}

N *node_search(N *states, string state){
    if(states){
        if(states->state == state)
            return states;
        else
            return node_search(states->next,state);
    }
    return NULL;
}

bool insert_state(N **states,string state,bool f){
    if(!*states){
        N *new_node = new N();
        if(!new_node){
            cout<<"New_Node_creation: FAIL"<<endl;
            return false;
        }   
        
        new_node->state = state;    
        if(!f){
            cout << "Is final state?" << endl;
            new_node->end = YNopt();            
        }
        else
            new_node->end = false;

        new_node->adj = NULL;
        new_node->next = NULL;
        *states = new_node;
        return true;  
    }
    else
        return (insert_state(&(*states)->next, state,f));
}

void go_end(A **aux, A* new_adj){
    if(!*aux)
        *aux = new_adj;
    else 
        go_end (&(*aux)->next, new_adj);
}

bool connec_exist(A*aux, N*node)
{
    if(aux)
    {
        if(aux->node == node)
            return true;
        else
            return connec_exist(aux->next, node);
    }
    else
        return false;
}

bool insert_adj(N **states){
    if(!*states)
        return false;

            char value;
            string input;

            N *aux,*aux2;
            aux = NULL;
            aux2 = NULL;

            A *new_adj = new A();
            if(!new_adj){    
                cout<<"New_edge_creation: FAIL"<<endl;
                return false;
            }
            display_ALL(*states);
            cout<<"Enter the first node\n"<<endl;
            validateInput(&input);
            aux = node_search(*states, input);
            if(!aux){
                cout<<"inexistent node"<<endl;
                return false;  
            }
            system("cls");
            display_ALL(*states);
            cout<<"Enter the second node\n"<<endl;
            validateInput(&input);
            aux2 = node_search(*states, input);
            if(!aux2){
                cout<<"inexistent node"<<endl;
                return false;  
            }
            if(connec_exist(aux->adj, aux2))
            {
                cout<<"The connection already exist"<<endl;
                return false;
            }
                
            cout<<"Enter edge value\n"<<endl;
            validateInput(&value);

            new_adj->next = NULL;
            new_adj->node = aux2;
            new_adj->value = value;
            go_end(&aux->adj, new_adj);

            return true;
}
bool insert_adjF(N **states,string node1, string node2,char value){
    if(!*states)
        return false;

            N *aux,*aux2;
            aux = NULL;
            aux2 = NULL;

            A *new_adj = new A();
            if(!new_adj){    
                cout<<"New_edge_creation: FAIL"<<endl;
                return false;
            }
            aux = node_search(*states, node1);
            if(!aux){
                cout<<"inexistent node"<<endl;
                return false;  
            }
            aux2 = node_search(*states, node2);
            if(!aux2){
                cout<<"inexistent node"<<endl;
                return false;  
            }
            if(connec_exist(aux->adj, aux2))
            {
                cout<<"The connection already exist"<<endl;
                return false;
            }
                
            new_adj->next = NULL;
            new_adj->node = aux2;
            new_adj->value = value;
            go_end(&aux->adj, new_adj);

            return true;
}
#endif
