//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Ian Altoveros
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Checks if Linked List is Empty
  bool isEmpty();
    
  //Displays the entire linked list
  void displayAll();

  //Adds to the front of the Linked List
  void addFront(el_t);
    
  //Adds to the rear of the Linked List
  void addRear(el_t);

  //Deletes front of Linked List
  void deleteFront(el_t&);
    
  //Deletes rear of Linked List
  void deleteRear(el_t&);
    
  //Delete Ith element of Linked List
  void deleteIth(int, el_t&);

  //Adds int before Ith element into Linked List
  void addbeforeIth(int, el_t);
    
};
