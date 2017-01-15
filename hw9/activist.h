/*
  Programmer: Innocent Niyibizi
  File: activist.h
  Date: 11/13/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for the activist class
*/
#ifndef ACTIVIST_H
#define ACTIVIST_H
#include <iostream>
#include <fstream>
#include <string>
#include "town.h"

using namespace std;
/*
 *Description: Activitst class
 */
class Activist
{
  public:
    /*
  		Description: Overloaded activist constructor
  		Pre:	       None
  		Post:	       Member variables are set to certain values.
                   If nothing is passed in arguments then default value used
	  */
    Activist( string name="Activist", char symbol = 'A');

    /*
		Description: Function to randomly place activist
		Pre:	       None
		Post:	       Dimensions of town are calculated and activist is placed in
                  the exact center of the town
	  */
    void placeMeInMiddle(Town& town);

    /*
		Description: Function to randomly move the activist
		Pre:	       None
		Post:	       Random number is gnerated from 1-4 which indicates which
                  direction to move the activist
	  */
    void randMove(Town& town);

    /*
		Description: Overloaded << operator
		Pre:	       None
		Post:	       << is Overloaded to display the activist's information
	  */
    friend ostream& operator<<(ostream& out, const Activist& activist);

    //Getters and setters
    float getToxicity() const;
    short getDigity() const;
    string getName() const;
    void setToxicity(float t);
    void setDignity(float d);
  private:
    //Member variables
    float m_toxicity;
    short m_dignity;
    short m_xLocation;
    short m_yLocation;
    char m_symbol;
    string m_name;
    string m_state;
};
#endif
