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

const float COOL = 0.08;
const float GONE = 0.25;
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

    /*
		Description: Function to move the activist normally
		Pre:	       None
		Post:	       Activist is moved to relative location of polluter
	  */
    void normalMove(Town& town, const int polluterX, const int polluterY);

    /*
		Description: Overloaded += operator
		Pre:	       Root effect must be able to add to the toxicity of activist
		Post:	       Value of root's effect is added to the current value of
                  activist's toxicity
	  */
    Activist& operator+=(Root& rhs);

    /*
    Description: Function to modify activist values
    Pre:	       None
    Post:	       Bools of activist are read and approriate changes are made
    */
    void modifyActivist(const int cLoss, const int wLoss);

    //Chaning all bool values of activist to false
    void clearTurn(){m_wallHit = false; m_copHit = false; m_rootEat = false;
                     m_exitTown = false; m_success = false;}
    //Getters and setters
    float getToxicity() const;  //Getting toxicity
    int getDignity() const;   //Getting dignity
    string getName() const;     //Getting name
    void setToxicity(float t);  //Setting toxicity to value passed through
    void setDignity(float d);   //Setting dignity to value passed through
    string getState(){return m_state;}  //Getting the current state of activist
    int getX(){return m_xLocation;}   //Getting x location
    int getY(){return m_yLocation;}   //Getting y location
    void setCop(bool input){m_copHit = input;}  //Setting value of cop bool
    void setWall(bool input){m_wallHit = input;}  //Setting value of wall bool
    void setRoot(bool input){m_rootEat = input;}  //Setting value of root bool
    void setSuccess(bool input){m_success = input;} //Setting vlaue of success
    bool getWall(){return m_wallHit;} //Getting value of wall bool
    bool getCop(){return m_copHit;}   //Getting value of cop bool
    bool getRoot(){return m_rootEat;} //Getting value root bool
    bool getExits(){return m_exitTown;} //Getting value of exit bool
    bool getSuccess(){return m_success;}  //Getting value of success bool

  private:
    //Member variables
    float m_toxicity; //Toxicity
    int m_dignity;  //Dignity
    int m_xLocation;  //x location
    int m_yLocation;  //y location
    char m_symbol;      //Symbol for the activist
    string m_name;      //Name
    string m_state;     //Current state of the activist

    void setState(string input){m_state = input;}
    //Bools for activist
    bool m_wallHit;     //wall hit
    bool m_copHit;      //Cop hit
    bool m_rootEat;     //Root eaten
    bool m_exitTown;    //Activist exited the town
    bool m_success;     //Activist successfully catches polluter
};
#endif
