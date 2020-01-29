// ==================================================================                                                                   
// File: el_t implementation file (elem.cpp)       
// Name: Mane Telpian                                                                         
// ================================================================== 

#include "elem.h"

//PURPOSE: to create blank or 0 el_t objects
el_t::el_t()
{
  name=" ";
  lastName=" ";
  number=0;
  diagnosis=" ";
  medication=" ";
  insurance=" ";
  month=0;
  day=0;
  year=0;
  patientNum=0;
}

//PURPOSE: to create an intialized el_t object
el_t::el_t(string n,string l,long num,string d,string m,string i,int mon,int da,long yr,int p)
{
  name=n;
  lastName=l;
  number=num;
  diagnosis=d;
  medication=m;
  insurance=i;
  month=mon;
  day=da;
  year=yr;
  patientNum=p;
}
  
// PURPOSE: overload == for search based on all of the el_t info
// PARAMETER: element to be compared
bool el_t::operator==(el_t OtherOne)
{
  if(name==OtherOne.name)
    return true;
  else if(lastName==OtherOne.lastName)
    return true;
  else if(number==OtherOne.number)
    return true;
  else if(diagnosis==OtherOne.diagnosis)
    return true;
  else if(medication==OtherOne.medication)
    return true;
  else if(insurance==OtherOne.insurance)
    return true;
  else if(month==OtherOne.month)
    return true;
  else if(day==OtherOne.day)
    return true;
  else if(year==OtherOne.year)
    return true;
  else if(patientNum==OtherOne.patientNum)
    return true;

  return false; 
}

// PURPOSE: overload != for search based on all of the el_t info
// PARAMETER: element to be compared
bool el_t::operator!=(el_t OtherOne)
{
  if(name!=OtherOne.name)
    return false;
  else if(lastName!=OtherOne.lastName)
    return false;
  else if(number!=OtherOne.number)
    return false;
  else if(diagnosis!=OtherOne.diagnosis)
    return false;
  else if(medication!=OtherOne.medication)
    return false;
  else if(insurance!=OtherOne.insurance)
    return false;
  else if(month!=OtherOne.month)
    return true;
  else if(day!=OtherOne.day)
    return true;
  else if(year!=OtherOne.year)
    return true;
  else if(patientNum!=OtherOne.patientNum)
    return false;

  return true;
}

// PURPOSE: overload cout for el_t object
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os<<E.name<<" "<<E.lastName<<","<<E.number<<","<<E.diagnosis<<","<<E.medication<<","<<E.insurance<<","<<E.month<<"/"<<E.day<<"/"<<E.year<<","<<E.patientNum<<" ";
    return os;
}  
