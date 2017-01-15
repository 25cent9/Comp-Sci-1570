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

using namespace std;

//Overloaded constructor
Activist::Activist(string name, char symbol)
{
  //Setting values equal to their respective values
  m_symbol = symbol;
  m_name = name;
  m_toxicity = 0.5;
  m_dignity = 100;
  m_state = "Normal";
  m_xLocation = -1;
  m_yLocation = -1;
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
  bool valid = true;  //Bool to check if location is valid
  short x=0, y=0; //Variables to hold test x and y variables
  do
  {
    //Setting the x and y value equal to half of the town size
    x = town.getSize()/2;
    y = town.getSize()/2;
    //Testing to see if the locatio is a
    valid = town.modifyTownCheck(x,y);
  }while(!valid);
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
  bool valid = true;  //Bool to check if location is valid
  short x=0,y=0;  //Variables to hold test x and y variables
  do
  {
    //Setting temp x and y equal to the x and y of the activist
    x=m_xLocation;
    y=m_yLocation;

    //Clearing the current location of the activist
    town.modifyTown(x, y, ' ');
    //Switch to randomly generate a direction to travel
    switch (rand()%3+1)
    {
      case 0:
        y--;
        break;
      case 1:
        y++;
        break;
      case 2:
        x--;
        break;
      case 3:
        x++;
        break;
    }
    //Checking to see if the move is valid
    valid = town.modifyTownCheck(x, y);
  }while(!valid);
  //Modifying the town with the activist's new coordinates
  town.modifyTown(x, y, m_symbol);
  //Setting x and y value of the activist to the valid ones generated
  m_xLocation = x;
  m_yLocation = y;
  return;
}

//Getter to get the name of the activist
string Activist::getName() const
{
  return m_name;
}

//Getter to get the dignity of the activist
short Activist::getDigity() const
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
