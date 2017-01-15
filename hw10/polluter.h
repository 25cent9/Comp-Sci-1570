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

    //Accessor for the status variable to see if polluter was caught
    bool getStatus(){return m_isCaught;}

    //Accessors for both the x and y location of the polluter
    int getX(){return m_xLocation;}
    int getY(){return m_yLocation;}

    //Mutator for the caught bool
    //Sets caught bool equal to the variable passed in
    void setStatus(bool state){m_isCaught = state;}

  private:
    //Member variables
    string m_name;  //Name
    int m_xLocation;  //x location
    int m_yLocation;  //y location
    char m_symbol;      //Polluter symbol
    bool m_isCaught;    //caught bool
};
#endif
