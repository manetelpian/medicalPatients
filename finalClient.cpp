//=========================================================
// Name: Mane Telpian
// File: client file for final project (finalClient.cpp)
//=========================================================
// PURPOSE: This program tests the hash table for medical patients for CS 311 Final Project
// Algorithm: The program begins by reading in the patient's medical info from a text file (patients.txt)
// Then it displays a menu for the user to choose from different options of finding petient's medical info, displaying the entire table, or quitting the program
// If the user wishes to find a patient's medical info, they must enter their medical patient number
// If such patient does not exist the rpgram will let the user know
// The program keeps going until the user wishes to quit
#include "htable.h"
#include <fstream>
#include <iostream> 
using namespace std;
int main()
{
  htable patientInfo; //declare object

  // read in patient info from patients.txt file and fill up table
  ifstream fin;
  fin.open("patients.txt"); //open patients.txt file                                                                                        
  el_t patient;
  string name,last,diag,med,ins;
  int num,m,d;
  long phoneNum,y;
  while(fin>>name>>last>>phoneNum>>diag>>med>>ins>>m>>d>>y>>num)
    {
      patientInfo.add(el_t(name,last,phoneNum,diag,med,ins,m,d,y,num)); //adds patient element to table
    }
  fin.close(); //close patients.txt file   

  bool stop=false; //if user wants to stop program
  int choice;

  //display menu for user
  while(stop==false)
    {
      do{
	cout<<"*****************************"<<endl;
	cout <<"* Patient Medical Info Menu *"<<endl;
	cout<<"* 1) Search for a patient.  *"<<endl;
	cout<<"* 2) Display all patients.  *"<<endl;
	cout<<"* 3) Quit program.          *"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"Choose what you would like to do =>";
	cin>>choice;
	if(choice<1 || choice>3) //if user enter invalid choice
	  cout<<"Invalid choice. Try again (1-3)"<<endl;
      }while(choice!=1 && choice!=2 && choice!=3);
      if(choice==1)
	{
	  int searchKey; // this is the unique medical number used to find patient
	  cout<<endl;                                                  
	  cout<<"Enter the patient's medical number =>";
	  cin>>searchKey;
	  el_t E=patientInfo.find(searchKey);
	  el_t blank;
	  if(E==blank) //if patient not found in table
	    cout<<"Patient number " <<searchKey<<" does not exits in the records."<<endl;
	  else //display patinet's medical info
	    {
	      cout<<"Found patient number "<< searchKey<<endl;
	      cout<<"Here is their medical information: "<<E<<endl;
	    }
	  cout<<endl;
	}
      else if(choice==2)
	patientInfo.displayTable();
      else 
	stop=true;
    }
  cout<<"Ending program. Thank you!"<<endl;
} //end of program
