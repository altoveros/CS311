//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Ian Altoveros
//Complier:  G++
//File type: Implementation File
//===========================================================



using namespace std;
#include <iostream>
#include "queue.h"  

// CONSTRUCTOR 
queue::queue()
{
  count = 0; // Set initial count of stack to 0 (as nothing is in it)
  front = 0; // Front starts at position 0
  rear = -1; // Rear must initially follow behind front, so place at -1
}

//DESTRUCTOR
queue::~queue(){}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(queue::getSize() == 0)
    return true;
  
  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(queue::getSize() == MAX_SIZE)
    return true;
  
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if(queue::isFull() == true)
    throw queue::Overflow();

  else
    {
      rear = (rear + 1) % MAX_SIZE;
      el[rear] = newElem;
      count++;
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
  if(queue::isEmpty() == true)
    throw queue::Underflow();

  else
    {
      removedElem = el[front];
      front = (front + 1) % MAX_SIZE;
      count--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
  if(queue::isEmpty() == true)
    throw queue::Underflow();
  
  else
    {
      theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
  if(queue::isEmpty() == true)
    cout << "[ empty ] " << endl;

  else
    {
      cout << "[";
      
      for(int i = front; i <= rear; i++)
	{
	  cout << " " << el[i];
	}
      
      cout << " ]";
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{
  if(queue::isEmpty() == true)
    throw queue::Underflow();
  
  else if(queue::getSize() == 1)
    return;

  else if(queue::getSize() > 1)
    {
      string Holder;
      queue::remove(Holder); // Removes front element and passes it to a dummy variable via reference.
      queue::add(Holder); // Adds the element to the rear of the queue.
    }
}





