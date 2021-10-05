
//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Ian Altoveros
//Complier:  G+;
//File type: client program
//===========================================================



using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"


//Purpose of the program: It is to create a sequence of strings from A B C
//Algorithm: 1. Make Queue hold A -> B -> C || 2. Remove Front to a placeholder || 3. Add A -> B -> C to the variable and place it to the back and repeat.
int main()
{
  queue stringQ; // Create object of queue class
  
  string A = "A"; // Initialize string of letter "A"
  string B = "B"; // Initialize string of letter "B"
  string C = "C"; // Initialize string of letter "C"
  
  string Holder; 

  
  stringQ.add(A);
  stringQ.add(B);
  stringQ.add(C);
    
  while(true) // Indefinite Loop
      {
      	try
	  {
	    stringQ.remove(Holder); // Remove front element and place it into a holding variable
	    cout << Holder << endl;
	    
	    stringQ.add(Holder + A); // Add 'A' to the variable and place into the rear of the queue.
	    stringQ.add(Holder + B); // Add 'B' to the variable and place into the rear of the queue.
	    stringQ.add(Holder + C); // Add 'C' to the variable and place into the rear of the queue.
	  }
	
	catch (queue::Overflow) // Overflow Exception Handle: (Thrown if queue if full)
	  {
	    cerr << "**OVERFLOW ERROR**" << endl;
	    exit(0);
	  }
	
	catch (queue::Underflow) // Underflow Exception Handle: (Thrown if queue is empty)
	  {
	    cerr << "**UNDERFLOW ERROR**" << endl;
	    exit(0);
	  }
      }
}

