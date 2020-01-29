// ==================================================================  
// File: el_t header file (elem.h)
// Name: Mane Telpian
// ================================================================== 

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:
  string name;  // patient's name
  string lastName; // patient's last name
  long number; // patient's phone number
  string diagnosis; // patients's medical diagnosis
  string medication; // patient's prescribed medication
  string insurance; // patient's insurance provider
  int month;// patient's birth month
  int day;//patient's birth day
  long year;//patient's birth year
  int patientNum; // patient's unique medical number
 public:

  // PURPOSE: to create a blank el_t object
  el_t();

  // PURPOSE: to create an initialized el_t object
  el_t(string,string,long,string,string,string,int,int,long,int);

  // PURPOSE: overload == for search
  bool operator==(el_t); 

  // PURPOSE: overload != for search
  bool operator!=(el_t);

  // PURPOSE: this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);  
  
  // PURPOSE: client of this class is htable which needs access to the key part of el_t  
  friend class htable; 
};

