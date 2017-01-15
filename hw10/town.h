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
#include "root.h"
using namespace std;

//Constants
const int MAX_SIZE = 25;
const char WALL = 'W';
const char EXIT = 'E';
const int EXIT_DIVISOR = 2;
/*
  Description: Town class
*/
class Town
{
  public:
    /*
  		Description: Overloaded town constructor
  		Pre:	       None
  		Post:	       Town array is given the dimensions of the passed int
	  */
    Town(int size);

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
    int getSize() const;

    /*
  		Description: Function to modify the town grid
  		Pre:	       None
  		Post:	       The symbol passed through will be placed in the provided
                    x and y location
	  */
    void modifyTown(const int x, const int y, const char symbol);

    /*
  		Description: Function to verify location of x and y variables
  		Pre:	       None
  		Post:	       The x and y values passed through are tested to see if
                    there is an obstacle in the current position
                    If there is then false is returned else true is returned
	  */
    bool modifyTownCheck(const int x, const int y, const char symb);

    /*
  		Description: Function to place symbols passed through in town
  		Pre:	       None
  		Post:	       Depending on number passed through, the symbol passed
                    will be placed randomly in town that many times
	  */
    void placeObjects(int num, char symbol);

    //Setting bools for any hit value to false to reset
    void clearTurn(){m_activistCopHit = false; m_activistRoot = false;
       m_activistWallHit=false; m_activistExit=false;}

    //Returning value of polluter stopped bool
    bool getCaught(){return m_polluterStopped;}
    //Returning value of activist cop hit bool
    bool getCopHit(){return m_activistCopHit;}
    //Returning value of activist wall hit bool
    bool getWallHit(){return m_activistWallHit;}
    //Returning value of activist root eaten bool
    bool getRoot(){return m_activistRoot;}
    //Returning value of activist exit bool
    bool getExit(){return m_activistExit;}
  private:
    //Member variables
    char m_town[MAX_SIZE][MAX_SIZE];  //Toen 2-d array
    int m_actualSize; //Actual size of the town
    void clear(const int gridSize); //Clearing the town
    void build(const int gridSize); //Building the town
    bool m_polluterStopped; //Bool to see if polluter was stopped by cop
    bool m_activistCopHit;  //Bool to see if activist hit a cop
    bool m_activistWallHit; //Bool to see if activist bumped into a wall
    bool m_activistRoot;  //Bool to see if activist has eaten a root
    bool m_activistExit;  //Bool to see if activist has left the town
};
#endif
