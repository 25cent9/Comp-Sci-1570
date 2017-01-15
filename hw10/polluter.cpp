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
#include "functions.h"
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
  m_isCaught = false;
}

//Function to place polluter in town randomly
void Polluter::placeMe(Town& town)
{
  bool valid = true;  //Bool to check if location is valid
  int dim = town.getSize(); //Getting the size of town
  //loop to run while location is invalid
  do
  {
    //randomly generating x and y values within the town boundaries
    m_xLocation = (rand()%dim+1)-1;
    m_yLocation = (rand()%dim+1)-1;
    //Checking if location is valid
    valid = town.modifyTownCheck(m_xLocation, m_yLocation, m_symbol);
  }while(!valid);
  //Modifying the location of the polluter
  town.modifyTown(m_xLocation, m_yLocation, m_symbol);
  return;
}

//Function to randomly move the polluter in one direction
void Polluter::randMove(Town& town)
{
  bool valid = true;
  int x=0,y=0;
  int randnum = randomNum(4,1);
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
    town.modifyTown(m_xLocation, m_yLocation, ' ');
    town.modifyTown(x, y, m_symbol);
    //Setting x and y value of the activist to the valid ones generated
    m_xLocation = x;
    m_yLocation = y;
  }
  //Setting the got caught by cop value to that of the town
  m_isCaught = town.getCaught();
  return;
}
