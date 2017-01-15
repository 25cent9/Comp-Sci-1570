/*
  Programmer: Innocent Niyibizi
  File: town.cpp
  Date: 11/14/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Cpp file for the town class
*/

#include "town.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

//Overloaded constructor to set the size of the town
//Clear the town
//Build the town
Town::Town(int size)
{
  //Setting valus of the actual size equal to the passed size
  do
  {
    if(size>MAX_SIZE)
    {
      cout<<"Size is too large! Please enter a smaller size: ";
      cin>>size;
    }
  } while(size>MAX_SIZE);
  m_actualSize = size;
  m_polluterStopped = false;
  clear(size);
  build(size);
}

//Clearing the town
void Town::clear(const int gridSize)
{
  for(int i = 0; i<gridSize; i++)
  {
    for(int j = 0; j<gridSize; j++)
    {
      m_town[i][j]=' ';
    }
  }
  return;
}

//Building the town
void Town::build(const int gridSize)
{
  for(int i = 0; i<gridSize; i++)
  {
    for(int j = 0; j<gridSize; j++)
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
  int size = town.getSize();
  for(int i = 0; i<size; i++)
  {
    out<<endl;
    for(int j = 0; j<size; j++)
    {
      out<<town.m_town[i][j]<<' ';
    }
  }
  return out;
}

//Accessor to get the actual size of the array
int Town::getSize() const
{
  return m_actualSize;
}

//Function to check if location passed throuh is valid
bool Town::modifyTownCheck(const int x, const int y, const char symb)
{
  switch (symb)
  {
    case 'L':
    case 'A':
      if(m_town[x][y]=='W')
      {
        m_activistWallHit = true;
        return false;
      }
      else if(m_town[x][y]=='E')
      {
        m_activistExit = true;
        return true;
      }
      else if(m_town[x][y]!='W')
      {
        return true;
      }
      break;
    case 'H':
    case 'P':
      if(m_town[x][y]=='W')
      {
        return false;
      }
      else if(m_town[x][y]!='E')
      {
        return true;
      }
      break;
  }
  return false;
}

//Modifying the town
void Town::modifyTown(const int x, const int y, const char symbol)
{
  //Setting the location and symbol equal to the one passed through
  static char oldSymbol = ' ';
  static int oldX = -1, oldY = -1;
  static char newSymbol = ' ';
  //Chaning values of static variables if the symbol passed through is
  //one of the following
  if((m_town[x][y]=='R' || m_town[x][y]=='C') && symbol!=' ')
  {
    oldSymbol = m_town[x][y];
    oldX = x;
    oldY = y;
    newSymbol = symbol;
  }
  m_town[x][y]=symbol;  //Setting the current location equal to the symbol
  //Determining how to modify town based on symbol
  switch (symbol)
  {
    //Case for the activist
    case 'A':
    case 'L':
      //Indicating that activist hit a cop
      if(oldSymbol == 'C' && m_town[x][y]!=symbol)
      {
        m_activistCopHit = true;
      }
      //Setting cop back to orgianl location when activist leaves
      else if(oldSymbol == 'C' && m_town[oldX][oldY]==' ')
      {
        m_town[oldX][oldY]=oldSymbol;
        m_activistCopHit = true;
        oldSymbol=' ';
        oldX = -1;
        oldY = -1;
        newSymbol = ' ';
      }
      //Indicating that activist picked up a root
      else if(oldSymbol == 'R' && newSymbol!='H')
      {
        m_activistRoot = true;
        oldSymbol=' ';
        oldX = -1;
        oldY = -1;
        newSymbol = ' ';
      }
      break;
    //Case for the polluter
    case 'H':
    case 'P':
      //Stopping the polluter and setting value of location to the symbol
      if(oldSymbol == 'C')
      {
        m_polluterStopped = true;
        m_town[x][y] = symbol;
      }
      //Replacing the root to its original location
      else if(oldSymbol == 'R' && m_town[oldX][oldY]==' ' && symbol==newSymbol)
      {
        m_town[oldX][oldY]=oldSymbol;
        oldSymbol=' ';
        oldX = -1;
        oldY = -1;
        newSymbol = ' ';
      }
      break;
  }
  return;
}

//Function to place number of given objects in the town
void Town::placeObjects(int num, char symbol)
{
  int tempX = 0, tempY = 0; //Temporary x and y values
  bool valid = true;
  //Loop to run based on the number of symbols passed through
  for(int i=0; i<num; i++)
  {
    //Creating a new location and testing to see if it's clear
    //If it is clear then the symbol is placed there
    //Else it repeats
    do
    {
      tempX = randomNum(m_actualSize, 1);
      tempY = randomNum(m_actualSize, 1);
      if(m_town[tempX][tempY] != ' ')
      {
        valid = false;
      }
      else
      {
        valid = true;
        m_town[tempX][tempY] = symbol;
      }
    }while(valid==false);
  }
}
