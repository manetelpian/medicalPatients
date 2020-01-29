// ============================================
// Name: Mane Telpian
// File Type: implementation (htable.cpp)
// =============================================

using namespace std;
#include <iostream>
#include <fstream>
#include <math.h>
#include "htable.h"

//PURPOSE:htable constructor
htable::htable()
{}

//PURPOSE:htable destructor
htable::~htable()
{}

//PURPOSE: a simple hash function that uses key%TSIZE to turn key into slot number 
//PARAMETER:passes the key
int htable::hash(int key)
{
  int temp=pow(((key*3)+5),3);
  return temp % TSIZE;
}

//PURPOSE: adds the element to the table and returns the slot number
//PARAMETER: passes the element to be added
int htable::add(el_t element)
{
 
  int slot = hash(element.patientNum);  // hash with the patientNum part
  table[slot].addRear(element);
  return slot;
}

//PURPOSE: finds the element using the skey and returns the found element itself or a blank element -- there is no cout in here
//PARAMETER: passes the skey used to find the element
el_t htable::find(int skey)
{
  el_t E;//blank element; 
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.patientNum=skey; // initialize selement with just the skey
 E=table[slot].search2(selement);// call slist's search2 with selement which returns the found element 
 return E;// return the found element from here (it could be blank)
}

//PURPOSE:displays the entire table with slot numbers
//PARAMETER:none
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll();//calls slist's displayAll
    }
}

//PURPOSE: reads from text file (patients.txt) to fill up the table
//PARAMETER: none
/*void htable::filetoTable()
{
  ifstream fin;
  fin.open("patients.txt"); //open patients.txt file

  el_t patient;
  while(fin>>patient.name)
    {
      fin>>patient.lastName>>patient.number>>patient.diagnosis>>patient.medication>>patient.insurance>>patient.patientNum;
      add(patient);
      count++;
    }
  fin.close(); //close patients.txt file
  }*/
