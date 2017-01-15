/*
  Programmer: Innocent Niyibizi
  File: polluter.h
  Date: 11/13/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for the polluter class
*/
#ifndef POLLUTER_H
#define POLLUTER_H

#include <iostream>
#include <string>
using namespace std;
/*
 *Description: Polluter class
 */
class Polluter
{
  public:
    /*
  		Description: Overloaded polluter constructor
  		Pre:	       None
  		Post:	       Member variables are set to certain values.
                   If nothing is passed in arguments then default value used
	  */
    Polluter(string name="Polluter", char symbol = 'P');

    /*
		Description: Function to randomly place polluter
		Pre:	       None
		Post:	       Polluter is placed randomly in town bounds
	  */
    void placeMe(Town& town);

    /*
		Description: Function to randomly move the polluter
		Pre:	       None
		Post:	       Random number is gnerated from 1-4 which indicates which
                  direction to move the polluter
	  */
    void randMove(Town& town);
  private:
    //Member variables
    string m_name;
    short m_xLocation;
    short m_yLocation;
    char m_symbol;
};
#endif
