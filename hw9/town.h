/*
  Programmer: Innocent Niyibizi
  File: town.h
  Date: 11/13/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for the town class
*/
#ifndef TOWN_H
#define TOWN_H
#include <iostream>
#include <fstream>

using namespace std;

//Constants
const short MAX_SIZE = 25;
const char WALL = 'W';
const char EXIT = 'E';
const short EXIT_DIVISOR = 2;
/*
  Description: Town class
*/
class Town
{
  public:
    /*
  		Description: Overloaded town constructor
  		Pre:	       None
  		Post:	       Town array is given the dimensions of the passed short
	  */
    Town(const short size);

    /*
  		Description: Overloaded << operator
  		Pre:	       None
  		Post:	       Member variables are set to certain values.
                   If nothing is passed in arguments then default value used
	  */
    friend ostream& operator<<(ostream& out, const Town& town);

    /*
  		Description: Getter for the size member variable
  		Pre:	       None
  		Post:	       Returns the size member variable
	  */
    short getSize() const;

    /*
  		Description: Function to modify the town grid
  		Pre:	       None
  		Post:	       The symbol passed through will be placed in the provided
                    x and y location
	  */
    void modifyTown(const short x, const short y, const char symbol);

    /*
  		Description: Function to verify location of x and y variables
  		Pre:	       None
  		Post:	       The x and y values passed through are tested to see if
                    there is an obstacle in the current position
                    If there is then false is returned else true is returned
	  */
    bool modifyTownCheck(const short x, const short y);
  private:
    //Member variables
    char m_town[MAX_SIZE][MAX_SIZE];
    short m_actualSize;
    void clear(const short gridSize);
    void build(const short gridSize);
};
#endif
