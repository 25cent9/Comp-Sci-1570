#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
  Programmer: Innocent Niyibizi
  File: functions.h
  Date: 10/3/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for each function in program
*/

#include <iostream>
using namespace std;

//Protoypes for each function
/*
  Description:  Greets the user
  Pre:          None
  Post:         Prints greeting
*/
void greeting();

/*
  Description: Function to print the menu on the screen
  Pre:         None
  Post:        Prints menu
*/
void printMenu(bool , bool , bool , bool );

/*
  Description:  See the user off
  Pre:          None
  Post:         Prints goodbye message
*/
void goodBye();

/*
  Description: Gets the poundage of wasted food 
  Pre:         None
  Post:        Returns the input that the user entered as a float
*/
float foodConsump();

/*
  Description: Gets distance traveled on public transit from user
  Pre:         None
  Post:        Returns an int of the distance traveled on public transit
*/
int publicTrans();

/*
  Description:  Finds whether or not the users is related to Mr. Burns
  Pre:          None
  Post:         Retuns the currrent deconstructor if it is Mr. Burns,
                returns the current deconstructor divided by the 
                divisor if the user is related to Mr. Burns, or 
                returns the users age
*/
int burnTest();

/*
  Description:  Gets the amount of pigs eaten from the user
  Pre:          None
  Post:         Returns a float by using provided equation
*/
float pigsEaten(float);

/*
  Description:  Used to check if the user is ready to compute GUILT
  Pre:          None
  Post:         Returns a bool based on the condition of all four bools
*/
bool computeCheck(bool first, bool second, bool third, bool fourth);

/*
  Description: Calculates the guilt factor
  Pre:         None
  Post:        Returns the modified number                
*/
float modifyValues(float MULT, int ADD, float value);

/*
  Description:   Calculates the final GUILT value
  Pre:           All values from the 4 options are passed through
  Post:          GUILT value is returned to the main function
*/
float calcGuilt(float , int , int , float );
#endif