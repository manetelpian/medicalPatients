// ------------------------------------------------

#include "slist.h"

const int TSIZE = 71;  // 37 slots ; a prime number 

class htable
{
 private:
 slist table[TSIZE]; // each node of slist is el_t 
                          // as defined in elem.h
 int hash(int);  // private hash function
 int count;
 public:
  htable();
  ~htable();

  int add(el_t);  // adds an element to the table and returns slot#
  el_t find(int); // finds an element based on key and returns it
  void displayTable(); // displays the table with slot#s
  //  void filetoTable();
};
