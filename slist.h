 //=================================================
// Name: Mane Telpian
// File: slist.h header file 
//=================================================

#include <iostream>
#include "llist.h" // for includes

class slist:public llist 
{
 public:
  
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

  // PURPOSE: searches through the list to see if any node contains Key                  
  // PARAMETER: passes key element which will be searched for
  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.

  //PURPOSE: searches through list to see if any node contains the element, if so returns element, if not returns blank
  //PARAMETER: passes elemnt to be found
  el_t search2(el_t);

  // PURPOSE: go to Ith node and replace the element there with new Elem                                                                                                              
  // if I was an illegal value, throw an exception (OutOfRange) 
  // PARAMETER: passes the new element that will replace the old, and the position of where to replace 
  void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    

  // PURPOSE: compares two slist objects to see if they look the same           
  // PARAMETER: passes object OtherOne (by ref) to be compared 
  bool operator==(const slist&);
    // checks to see if the two lists look the same
};
