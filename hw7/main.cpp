/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 10/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to help Lisa and Cheif Wiggum find the criminals
*/
#include <iostream>
using namespace std;
#include "structs.h"
#include "constants.h"
#include "functions.h"
#include "templates.hpp"
int main()
{
  int user_input = 0; //Variable for user input
  sector sectors[DATABASE_SIZE];  //Wiggum's database
  offender offenders[DATABASE_SIZE];  //Lisa's database

  //Initializing and soriting each database
  initializeArray(sectors, DATABASE_SIZE);
  sortArray(sectors, DATABASE_SIZE);
  initializeArray(offenders, DATABASE_SIZE);
  sortArray(offenders, DATABASE_SIZE);

  //Printing out each database
  cout<<"----Wiggum's Database----"<<endl;
  printDatabase(sectors, DATABASE_SIZE);
  cout<<endl;
  cout<<"----Lisa's Database----"<<endl;
  printDatabase(offenders, DATABASE_SIZE);
  cout<<endl;
  //Printing the top offenders
  cout<<"----Top Guiltiest----"<<endl;
  for(int i =0; i<TOP_OFFENDERS_NUM; i++)
  {
    cout<<offenders[i].name<<", guilt = "<<offenders[i].guilt<<endl;
  }
  cout<<endl;
  //Printing the least number of offender for 50% of the trash
  cout<<"---Biggest Contributions---"<<endl;
  printDatabase(offenders, findGuiltiestOffenders(sectors,DATABASE_SIZE));
  cout<<endl;
  printSectors(sectors, DATABASE_SIZE);
  do
  {
    cout<<"Please enter the weight of a pile [25-500],"
          " a ranking of pile [1-15], or '0' to quit: ";
    cin>>user_input;
    if(user_input != 0 && user_input<=HIGHSECTOR)
      rangeCheck(user_input,LOWRANK, HIGHRANK);
    if(user_input<=HIGHRANK && user_input >= LOWRANK)
      cout<<"\nOffender: "<<offenders[user_input-1].name<<endl;
    else if(user_input > HIGHRANK)
      cout<<"\nOffender: "
          <<offenders[findOffender(sectors,DATABASE_SIZE, user_input)].name
          <<endl;
  }while(user_input != 0);
  return 0;
}
