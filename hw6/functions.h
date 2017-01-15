#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/*
  Programmer: Innocent Niyibizi
  File: functions.h
  Date: 10/8/16
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
  Description:  Printing the menu items based on how many are left
  Pre:          None
  Post:         Prints the menu
*/
void printMenu(int[]);

/*
  Description:  Function that will select the item and quantitiy
  Pre:          Item selection from user must be between 1 and 6
  Post:         Processes the selection for the user
*/
void itemSelection(int[], int, float&);

/*
  Description:  Function range check the given integer
  Pre:          None
  Post:         A valid integer is returned
*/
int rangeCheck(int, int, int);

/*
  Description:  Function that will have the computer pick a random number
                between two numbers
  Pre:          Must be within the range
  Post:         A valid integer is returned
*/
int machinePick(int, int);

/*
  Description:  Function that will compare the user's amount and the computer's
  Pre:          Must be positive
  Post:         Values are compared and accoriding ouput is displayed
*/
void compare(int, int);

/*
  Description:  Function that will calculate the subtotal accoridingly
  Pre:          Must be greater than 0
  Post:         Subtotal is given the approriate tax amount and then rounded
*/
void calcSubtotal(float&);

/*
  Description:  Function that will calculate the change
  Pre:          Must be greater than 0
  Post:         Change is returned
*/
float calculateChange(float);

/*
  Description:  Sees the user off
  Pre:          None
  Post:         A goodbye message is displayed
*/
void signOff();
#endif
