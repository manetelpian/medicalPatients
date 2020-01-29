// ====================================================
//Your name: Mane Telpian
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

//  Make sure llist constructor and destructors have couts in them

// do not change this one
// PURPOSE: slist constructor
slist::slist()
{
  // cout << "in slist constructor"<< endl;
}


// positions always start at 1
// PURPOSE: searches through the list to see if any node contains Key
// PARAMETER: passes key element which will be searched for
int slist::search(el_t key)
{
  int position=1; // poisition >=1 
  Node *P; //temp Node pointer used to traverse through list
  P=Front;
  while(P!=NULL)
    {
      if(P->Elem==key)
	return position;
      else
	{
	  P=P->Next;
	  position++;
	}
    }
  return 0; // return 0 if element is not found
}

// PURPOSE: go to Ith node and replace the element there with new Elem
// if I was an illegal value, throw an exception (OutOfRange)
// PARAMETER: passes the new element that will replace the old, and the position of where to replace
void slist::replace(el_t element, int pos)
{
  if(pos<1 || pos>Count)// throw OutOfRange for bad pos
    throw OutOfRange();
  else
    {
      Node *P; // temp variable to traverse through list until reached to desired position
      P=Front;
      for(int i=1;i<pos;i++)
	P=P->Next;
      P->Elem=element;
    }
}

// PURPOSE: compares two slist objects to see if they look the same
// PARAMETER: passes object OtherOne (by ref) to be compared
bool slist::operator==(const slist& OtherOne)
{
  if(this->Count != OtherOne.Count)// if not the same length, return false
    return false;
  else
    {
      Node *P; // temp variables P and Q used to traverse through two slist objects to compare elements
      Node *Q;
      Q=this->Front;
      P=OtherOne.Front;
  // if the same lengths, 
  //check each node to see if the elements are the same 
  while(P!=NULL && Q!=NULL)
    {
      if(P->Elem != Q->Elem)
	return false;
      else
	{
	  P=P->Next;
	  Q=Q->Next;
	}
    }
  return true;
    }
}

// PURPOSE: search through list to see if any node contains the key, if yes return element, if not return blank element
// PARAMETER: passes the key to be found
el_t slist::search2(el_t key)
{
  Node *P; //temp Node pointer used to traverse through list               
  P=Front;
  while(P!=NULL)
    {
      if(P->Elem==key)
        return P->Elem;
      else
          P=P->Next;
    }
  el_t blank;
  return blank; // return blank if element is not found                  
}
