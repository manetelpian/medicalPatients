// =======================================================
// Your name: Mane Telpian
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
//typedef char el_t;
#include "elem.h"
//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // utility function to move to a specified node position (moves to I-1th)
 void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // PURPOSE: returns true if Front and Rear are both pointing to NULL and count is 0
  bool isEmpty();
    
  // PURPOSE: displays each element of the list starting from Front, enclosed in [] followed by endl
  // special case: if the list is empty displays [ empty ]
  void displayAll();

  // PURPOSE: Adds a new node at the front of the list and puts NewNum in Elem field of this new node                                        
  // PARAMETER: NewNum - pass the element being added to the front of the list
  void addFront(el_t);
    
  // PURPOSE: Adds a new node at the rear of the list and puts NewNum in Elem field of this new node                                                                                     
 // PARAMETER: NewNum - pass the element being added to the rear of the list
  void addRear(el_t);

  // PURPOSE: Removes the front node and gives back the front node element                             
  // PARAMETER: OldNum (pass by reference) - variable to receive the deleted front node element 
  void deleteFront(el_t&);
    
  // PURPOSE: Removes the rear node and gives back the rear node element
  // PARAMETER: OldNum (pass by reference) - variable to receive the deleted rear node element 
  void deleteRear(el_t&);
    
  // PURPOSE: deletes the Ith node. Count is updated.                                                                                 
  // PARAMETER: I receives the desired node position;OldNum (pass by reference) - variable to receive the deleted node element 
  void deleteIth(int, el_t&);  // calls moveTo

  // PURPOSE: inserts right before the Ith node. Count is updated.                                               
  // PARAMETER: I receives the desired node position; newNum - passes the element to be added to Ith Node 
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
