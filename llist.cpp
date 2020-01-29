// ====================================================
//Your name: Mane Telpian
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() // Constructor: initializes front and Rear to NULL, and Count to 0
{ 
  Front=NULL;
  Rear=NULL;
  Count=0;
  //  cout << "... in llist constructor..." << endl; 
}

llist::~llist() // Destructor: while list is not empty, calls deleteFront repeatedly to delete all nodes
{ 
  el_t temp; // temporary variable for holding deleted nodes
  while(!isEmpty())
    {
      deleteFront(temp);
    }
  //cout << ".... in llist destructor..." << endl; 
}

// PURPOSE: returns true if Front and Rear are both pointing to NULL and Count is 0
// PARAMETER: None
bool llist::isEmpty() 
{
  if((Front==NULL)&&(Rear==NULL)&&(Count==0)) // checks all 3 data members
    return true;
  else 
    return false;
}

// PURPOSE: displays each element of the list starting from Front, enclosed in []
// PARAMETER: None
void llist::displayAll() 
{ 
  if(isEmpty()) // special case: if the list is empty, lets the user know
    cout << "[ empty ]"<<endl;
  else // regular case: displays list horizontally
    {
      Node *P; // temporary Node pointer used to traverse through list and display each element
      P=Front;
      cout <<"[ ";
      while(P!=NULL)
	{
	  cout << P->Elem<< " ";
	  P=P->Next;
	}
      cout <<"]"<<endl;
    }
}
  
// PURPOSE: Adds a new node at the rear of the list and puts NewNum in Elem field of this new node
// PARAMETER: NewNum - pass the element being added to the rear of the list
void llist::addRear(el_t NewNum) 
{
  if(isEmpty()) // special case: if this is the very first node, create a new node and make Front and Rear point to it. Put NewNum in the Elem field. Count is updated.
    {
      Front=new Node;
      Front-> Elem=NewNum;
      Rear=Front;
      Rear->Next=NULL;
      Count++;
    } 
  else // regular case: add a new node at the Rear and put NewNum in the elem field of this new node. Count is updated.
    {
      Rear->Next=new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
} 

// PURPOSE: Adds a new node at the front of the list and puts NewNum in Elem field of this new node
// PARAMETER: NewNum - pass the element being added to the front of the list
void llist::addFront(el_t NewNum) 
{
  if(isEmpty())// special case: if this is the very first node, create a new node and make Front and Rear point to it. Put NewNum in the Elem field. Count is updated.
    {
      Front=new Node;
      Front-> Elem=NewNum;
      Rear=Front;
      Rear->Next=NULL;
      Count++;
    } 
  else // regular case: add a new node at the front and puts NewNum in the Elem field of this new node. Count is updated. 
    {
      Node *Q=new Node;
      Q->Elem=NewNum;
      Q->Next=Front;
      Front=Q;
      Count++;
    }
} 

// PURPOSE: Removes the front node and gives back the front node element 
// PARAMETER: OldNum (pass by reference) - variable to receive the deleted front node element 
void llist::deleteFront(el_t& OldNum) 
{
  if(isEmpty()) // error case: If list is empty, throws an exception
    throw Underflow();
  else if(Count==1) // special case: if this is going to make the list empty, give back the front node element through OldNum (by ref) and also remove the front node. Count is updated. Set Front and Rear to NULL
    {
      OldNum = Front->Elem;
      delete Front;
      Front=NULL;
      Rear=NULL;
      Count--;
    }
  else // regular case: give back the front node element through OldNum (by ref) and also remove the front node. Count is updated.
    {
      OldNum = Front->Elem;
      Node *Second; // know the Second node
      Second = Front->Next;
      delete Front;
      Front = Second; // Front moves down
      Count--;
    }	      
} 

// PURPOSE: Removes the rear node and gives back the rear node element
// PARAMETER: OldNum (pass by reference) - variable to receive the deleted rear node element
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty()) // error case: If list is empty, throws an exception
    throw Underflow();
  else if(Count==1) // special case: if this is going to make the list empty, give back the rear node element through OldNum (by ref) and also remove the rear node. Count is updated. Set Front and Rear to NULL 
    {
      OldNum = Rear->Elem;
      delete Rear;
      Front=NULL;
      Rear=NULL;
      Count--;
    }
  else // regular case: give back the rear node element through OldNum (by ref) and also remove the rear node. Count is updated. 
    {
      OldNum = Rear->Elem;
      Node *P; // know the previous(P) node
      P=Front;
      while(P->Next!=Rear)
	P=P->Next;
      delete Rear;
      Rear=P; // Rear moves up
      Rear->Next=NULL;
      Count--;
    }
} 

// PURPOSE: Utility Function to move a local pointer to the Ith node
// PARAMETER: I variable to receive the desired node position; temp is (pass by ref) pointer that points to I-1th node
void llist::moveTo(int I, Node*& temp)
{
  temp = Front;
  for (int j = 1; j<I-1;j++)// moves temp I-1 times 
    temp = temp->Next;
}

// PURPOSE: deletes the Ith node. Count is updated.
// PARAMETER: I receives the desired node position;OldNum (pass by reference) - variable to receive the deleted node element
void llist::deleteIth(int I, el_t& OldNum) 
{
  if(I>Count || I<1) // error case: if it is an illegal value, throw an exception
    throw OutOfRange(); 
  else if(I==1) // special case: if the position is the first node(front)
    deleteFront(OldNum);
  else if(I==Count) // special case: if the position is the last node(rear)
    deleteRear(OldNum);
  else // regular case: will delete the Ith node 
    {
      Node* P;
      moveTo(I,P); // move P to I-1th node
      Node* Q;
      Q=P->Next;
      OldNum=Q->Elem;
      P->Next=Q->Next;
      delete Q;
      Count--;
    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

// PURPOSE: inserts right before the Ith node. Count is updated.
// PARAMETER: I receives the desired node position; newNum - passes the element to be added to Ith Node
void llist::insertIth(int I, el_t newNum) 
{
  if(I>Count+1 || I<1) // error case: if it is an illegal value, throw an exception
    throw OutOfRange();
  else if(I==1) // special case: if the position is the first node(front)
    addFront(newNum);
  else if(I==Count+1) // special case: special case: if the position is the last node(rear)
    addRear(newNum);
  else // regular case: inserts right before the Ith node
    {    
      Node* P;
      moveTo(I,P);//move to i-1th node
      Node* Q =new Node;
      Q->Elem=newNum;
      Q->Next=P->Next;
      P->Next=Q->Next;
      P->Next=Q;     
      Count++;
    } 
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

// PURPOSE: copy constructor for pass by value and return by value of a list
// PARAMETER: passes Original to constructor (by ref)
llist::llist(const llist& Original) 
{
  //  this->'s data members need to be initialized here first
  Front = NULL; Rear = NULL; Count = 0;
  //  this-> object has to be built up by allocating new cells
  //  and copying the values from Original into each cell as we did with 
  //  operator= above. To do this,
  //     copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
  Node* P;  // local pointer for OtherOne                                                                                             
  P = Original.Front;
  while (P != NULL)  // a loop which repeats until you reach the end of Original.                                                  
    {
      this->addRear(P->Elem);    //P’s element is added to this->                                               
      P = P->Next;              // Go to the next node in Original.                                                     
    }         
    //  Nothing to return because this is a constructor. 
} 

// PURPOSE: overloading of = for allowing the client to use = for linked list objects
// PARAMETER: passes object OtherOne (by ref) to be copied
llist& llist::operator=(const llist& OtherOne) 
{
  el_t x;
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (! this->isEmpty() )
	this->deleteRear(x);  
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne   
	} 
    }// end of if              
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.
 
} 
