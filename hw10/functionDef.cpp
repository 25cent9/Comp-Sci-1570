/*
  Programmer: Innocent Niyibizi
  File: functionDef.cpp
  Date: 11/27/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Definition file for functions
*/
#include "town.h"
#include "polluter.h"
#include "activist.h"
#include "root.h"
#include "functions.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>

//Random number generator
int randomNum(const int max, const int min)
{
  static bool first = true;
   if ( first )
   {
      srand(time(NULL)); //seeding for the first time only
      first = false;
   }
   return (rand()%(max-min+1))+min;
}

//Function to simulate a day for the activist.
//Returns an activist
Activist simulate(const int size, int rootNum, const int numCops,
   const int bumpLoss, const int copLoss, const int dayCount)
{
  //Declaring a new instance of each type
  Town springfield(size);
  Activist lisa("Lisa");
  Polluter homer("Homer", 'H');

  //Placing the polluter and the activist in the town
  lisa.placeMeInMiddle(springfield);
  homer.placeMe(springfield);
  Root roots[MAX_ROOTS];  //Declaring an array of roots
  //Plcaing symbols of root and cop around town
  springfield.placeObjects(rootNum, 'R');
  springfield.placeObjects(numCops, 'C');

  //Bool to check if the activist is still active
  bool active = (lisa.getState()!="Gone" && lisa.getDignity()>0
  && !lisa.getExits() && !lisa.getSuccess());
  while(active)
  {
    //Clearing all of the boolean values of the town and activist for turn
    lisa.clearTurn();
    springfield.clearTurn();

    //Randomly moving the polluter if the value of the caught bool is false
    if(springfield.getCaught()==false)
      homer.randMove(springfield);

    //Determining how to move the polluter based on the current state
    //Normal = normal movement
    //Cool = Random movement
    if(lisa.getState()=="Normal")
    {
      lisa.normalMove(springfield, homer.getX(), homer.getY());
    }
    else if(lisa.getState()=="Cool")
    {
      lisa.randMove(springfield);
    }

    //Calling the function to modify the values of the activist
    lisa.modifyActivist(copLoss, bumpLoss);
    //Adding to the value of the activist's toxicity based on the current
    //value of the roots array
    if(lisa.getRoot())
    {
      lisa+=roots[rootNum-1];
      rootNum--;
    }
    //Displaying the town only if the day is the first
    if(dayCount < 1)
    {
      cout<<springfield<<endl;
      usleep(300004);
    }
    //Checking to see if the location of the polluter and activist are the same
    //Resulting in a success for the activist
    if(lisa.getX()==homer.getX() && lisa.getY()==homer.getY())
    {
      homer.setStatus(true);
      lisa.setSuccess(true);
    }
    //Changing value of active to match that of the given variabless
    active = (lisa.getState()!="Gone" && lisa.getDignity()>0
    && !lisa.getExits() && !lisa.getSuccess());
  }
  return lisa; //Returning the activist to collect stats
}

//Function to collect stats
void collectStats(Activist& activist, float& tox, float& exits,
  float& success, float& death, float& whack)
{
  //Incrementing the value of tox by the value of the toxicity from activist
  tox+=activist.getToxicity();

  //Determining which value to increment based on success or not
  if(activist.getSuccess())
    success++;  //If successfully caught
  else if(activist.getDignity()<=0)
    death++;  //If dignity reaches a value less than 0
  else if(activist.getExits())
    exits++;  //If activist exits the town
  else if(activist.getState()=="Gone")
    whack++;  //If state of activist is gone

  return;
}

//Function to report the stats from the simulation
void reportStats( float tox, float exits,
  float success, float death, float whack, int numDays)
{
  //Displaying the percentage values from all of the variables passed
  cout<<"Percentage of exits: "<<(exits/numDays)*PERCENTAGE<<"%"<<endl;
  cout<<"Percentage of gone state: "<<(whack/numDays)*PERCENTAGE<<"%"<<endl;
  cout<<"Percentage of success: "<<(success/numDays)*PERCENTAGE<<"%"<<endl;
  cout<<"Percentage of death: "<<(death/numDays)*PERCENTAGE<<"%"<<endl;
  cout<<"Average toxicity: "<<(tox/numDays)<<endl;
  return;
}
