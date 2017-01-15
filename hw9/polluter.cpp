/*
  Programmer: Innocent Niyibizi
  File: polluter.cpp
  Date: 11/14/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Cpp file for the polluter class
*/
#include "town.h"
#include "polluter.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Overloaded constructor
Polluter::Polluter(string name, char symbol)
{
  //Setting member variables equal to their respective values
  m_name = name;
  m_xLocation = -1;
  m_yLocation = -1;
  m_symbol = symbol;
}

//Function to place polluter in town randomly
void Polluter::placeMe(Town& town)
{
  bool valid = true;  //Bool to check if location is valid
  short dim = town.getSize(); //Getting the size of town
  //loop to run while location is invalid
  do
  {
    //randomly generating x and y values within the town boundaries
    m_xLocation = (rand()%dim+1)-1;
    m_yLocation = (rand()%dim+1)-1;
    //Checking if location is valid
    valid = town.modifyTownCheck(m_xLocation, m_yLocation);
  }while(!valid);
  //Modifying the location of the polluter
  town.modifyTown(m_xLocation, m_yLocation, m_symbol);
  return;
}

//Function to randomly move the polluter in one direction
void Polluter::randMove(Town& town)
{
  bool valid = true;
  valid = town.modifyTownCheck(m_xLocation, m_yLocation);
  short x=0,y=0;
  do
  {
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
}
