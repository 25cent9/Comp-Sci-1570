/*
  Programmer: Innocent Niyibizi
  File: town.cpp
  Date: 11/14/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Cpp file for the town class
*/

#include "town.h"
#include <iostream>
#include <fstream>

using namespace std;

//Overloaded constructor to set the size of the town
//Clear the town
//Build the town
Town::Town(const short size)
{
  //Setting valus of the actual size equal to the passed size
  m_actualSize = size;
  clear(size);
  build(size);
}

//Clearing the town
void Town::clear(const short gridSize)
{
  for(short i = 0; i<gridSize; i++)
  {
    for(short j = 0; j<gridSize; j++)
    {
      m_town[i][j]=' ';
    }
  }
  return;
}

//Building the town
void Town::build(const short gridSize)
{
  for(short i = 0; i<gridSize; i++)
  {
    for(short j = 0; j<gridSize; j++)
    {
      if(i==0 || i==gridSize-1)
      {
        if(j==(gridSize/EXIT_DIVISOR))
          m_town[i][j]=EXIT;
        else
          m_town[i][j]=WALL;
      }
      else
      {
        if(i==(gridSize/EXIT_DIVISOR) && (j==0 || j==gridSize-1))
          m_town[i][j]=EXIT;
        else if(j==0 || j==gridSize-1)
          m_town[i][j]=WALL;
        else
          m_town[i][j] = ' ';
      }
    }
  }
  return;
}

//Overloaded insertion operator
ostream& operator<<(ostream& out, const Town& town)
{
  short size = town.getSize();
  for(short i = 0; i<size; i++)
  {
    out<<endl;
    for(short j = 0; j<size; j++)
    {
      out<<town.m_town[i][j];
    }
  }
  return out;
}

//Accessor to get the actual size of the array
short Town::getSize() const
{
  return m_actualSize;
}

//Function to check if location passed throuh is valid
bool Town::modifyTownCheck(const short x, const short y)
{
  //if location is blank return true
  //else return false
  if(m_town[x][y]==' ')
    return true;
  else
    return false;
}

//Modifying the town
void Town::modifyTown(const short x, const short y, const char symbol)
{
  //Setting the location symbol equal to the one passed through
  m_town[x][y]=symbol;
  return;
}
