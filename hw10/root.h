/*
  Programmer: Innocent Niyibizi
  File: root.h
  Date: 11/27/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for the root class
*/
#ifndef ROOT_H
#define ROOT_H
#include <string>
using namespace std;
/*
 *Description: Root class
 */
const int MAX_NEGINTERVAL = -1; //Max value of negative interval
const int MIN_NEGINTERVAL = -10;  //Min value for negative interval
const int MAX_POSINTERVAL = 10; //Max value for positive interval
const int MIN_POSINTERVAL = 5;  //Min value for positive interval
const int MAX_RANDNUM = 1;  //Max random number
const int MIN_RANDNUM = -1; //Min random number
const int POS_DIVISOR = 100;  //Value of positve divisor
const int NEG_DIVISOR = 1000; //Value of negative divisor
const string POS_NAME = "Truffle";  //Name for positve value
const string NEG_NAME = "Square"; //Name for negative value
const int MAX_ROOTS = 50; //Max number of roots
class Root
{
  public:
    //Overloaded default constructor
    Root();

    //Getting name of root
    string getName(){return m_name;}

    //Getting effect of root
    float getEffect(){return m_effect;}
  private:
    string m_name;  //Name
    float m_effect; //Effect
};


#endif
