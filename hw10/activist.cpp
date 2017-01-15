/*
  Programmer: Innocent Niyibizi
  File: activist.cpp
  Date: 11/14/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Cpp file for the activist class
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "activist.h"
#include "functions.h"
#include "root.h"
using namespace std;

//Overloaded constructor
Activist::Activist(string name, char symbol)
{
  //Setting values equal to their respective values
  m_symbol = symbol;
  m_name = name;
  m_toxicity = 0.05;
  m_dignity = 100;
  m_state = "Normal";
  m_xLocation = -1;
  m_yLocation = -1;

  m_wallHit = false;
  m_copHit = false;
  m_rootEat = false;
  m_exitTown = false;
  m_success = false;
}

//Overloading the << operator
ostream& operator<<(ostream& out,const Activist& activist)
{
  //Printing the characteristics of the activist
  out<<"Name: "<<activist.m_name<<endl;
  out<<"Symbol: "<<activist.m_symbol<<endl;
  out<<"Toxicity: "<<activist.m_toxicity<<endl;
  out<<"Dignity: "<<activist.m_dignity<<endl;
  out<<"State: "<<activist.m_state<<endl;
  return out;
}

//Function to place activist in the middle
void Activist::placeMeInMiddle(Town& town)
{
  int x=0, y=0; //Variables to hold test x and y variables
  x = town.getSize()/2;
  y = town.getSize()/2;

  //Setting the activist x and y location equal to the valid ones
  m_xLocation = x;
  m_yLocation = y;
  //Calling function to modify the town with location of the activist
  town.modifyTown(m_xLocation, m_yLocation, m_symbol);
  return;
}

//Function to randomly move the activist
void Activist::randMove(Town& town)
{
  bool valid = true;
  int x=0,y=0;
  int randnum = randomNum(4,1); //Random number between 1-4 is generated
  x=m_xLocation;
  y=m_yLocation;
  //Switch to randomly generate a direction to travel
  switch (randnum)
  {
    case 1:
      y--;
      break;
    case 2:
      y++;
      break;
    case 3:
      x--;
      break;
    case 4:
      x++;
      break;
  }
  //Checking to see if the move is valid
  valid = town.modifyTownCheck(x, y, m_symbol);
  if(valid)
  {
    //Placing a blank space in the old location of the activist
    town.modifyTown(m_xLocation, m_yLocation, ' ');
    //Placing the activist in the new location
    town.modifyTown(x, y, m_symbol);
    //Setting x and y value of the activist to the valid ones generated
    m_xLocation = x;
    m_yLocation = y;
  }
  //Setting the values of the activist's boolean values to the corresponding
  //town values
  m_rootEat = town.getRoot();
  m_wallHit = town.getWallHit();
  m_copHit = town.getCopHit();
  m_exitTown = town.getExit();
  return;

}

void Activist::normalMove(Town& town, const int polluterX,
                          const int polluterY)
{
  //Placing a blank space in the old location of the activist
  town.modifyTown(m_xLocation, m_yLocation, ' ');
  //Changing the location of the activist based on the x and y value of the
  //polluter
  if(m_xLocation > polluterX)
    m_xLocation--;
  else if(m_xLocation < polluterX)
    m_xLocation++;
  else if(m_yLocation > polluterY)
    m_yLocation--;
  else if(m_yLocation < polluterY)
    m_yLocation++;

  //Placing the activist in the new location
  town.modifyTown(m_xLocation, m_yLocation, m_symbol);

  //Setting the values of the activist's boolean values to the corresponding
  //town values
  m_rootEat = town.getRoot();
  m_wallHit = town.getWallHit();
  m_copHit = town.getCopHit();
}
//Getter to get the name of the activist
string Activist::getName() const
{
  return m_name;
}

//Getter to get the dignity of the activist
int Activist::getDignity() const
{
  return m_dignity;
}

//Getter to get the toxicity of the activist
float Activist::getToxicity() const
{
  return m_toxicity;
}

//Setter for the toxicity
void Activist::setToxicity(float t)
{
    m_toxicity = t;
}

//Setter for the dignity
void Activist::setDignity(float d)
{
  m_dignity = d;
}

//Overloading the += operator to add the value of the root to the activist
Activist& Activist::operator+=(Root& rhs)
{
  float toxicity = m_toxicity;
  toxicity+=rhs.getEffect();
  m_toxicity = toxicity;
  return *this;
}

//Function to modify the values of the activist
void Activist::modifyActivist(const int cLoss, const int wLoss)
{
    //Taking points off dignity if a wall was hit
  if(m_wallHit)
  {
    m_dignity-=wLoss;
  }
  else if(m_copHit) //Taking points off for running into a cop
  {
    m_dignity-=cLoss;
  }

  //Determining the state of the activist based on the toxicity
  if(getToxicity()<GONE && getToxicity()>=COOL)
  {
    setState("Cool");
  }
  else if(m_toxicity>=GONE)
  {
    setState("Gone");
  }
  else
  {
    setState("Normal");
  }

  return;
}
