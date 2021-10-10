# Finite Automata
Management of a finite automata in c++
This program can be use using an archive named "data.txt" or you can modify the name inside the main.cpp and add your own .txt.  
Also you can run the program without the file and put all manually.
## File parameters
The first paragraph must be an integer that indicates the number of states of the automata.  
The second are the names of each state.  
The third are the final states of the automata.  
And from the fourth paragraph down are the conecctions between states. 

### File format example 
7  
0,1,2,3,4,5,6  
6  
0,1,h  
1,2,e  
2,3,l  
3,4,l  
4,5,o  
5,6,;  
