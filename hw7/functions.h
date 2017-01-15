/*
  Programmer: Innocent Niyibizi
  File: functions.h
  Date: 10/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file to hold the function prototypes
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"
/*
  Description: Fucntion that will choose a random number
  Pre:         Both values must be greater than 0
  Post:        A random number between the two values is returned
*/
int randomNumber(int,int);

/*
  Description: Fucntion that will place values in array
  Pre:         Array must be initialized
  Post:        The array will have values placed into it
*/
void initializeArray(offender[], const int);

/*
  Description: Overloaded fucntion that will place values in array
  Pre:         Array must be initialized
  Post:        The array will have values placed into it
*/
void initializeArray(sector[], const int);

/*
  Description: Fucntion that will print the values in array
  Pre:         Array must be initialized and filled with data
  Post:        The array will be printed to the screen
*/
void printDatabase(const sector[], const int);

/*
  Description: Overloaded fucntion that will print the values in array
  Pre:         Array must be initialized and filled with data
  Post:        The array will be printed to the screen
*/
void printDatabase(const offender[], const int);

/*
  Description: Function that will find least number of offenders who
               contribute at least 50% of toal waste
  Pre:         Array must have values
  Post:        An integer is returned indicating the amount of people
               who are reposnibile
*/
int findGuiltiestOffenders(const sector[], const int);

/*
  Description: Function that will print the information of the sectors
  Pre:         Array must be initialized
  Post:        Information of each sector is printed
*/
void printSectors(const sector[], const int);

/*
  Description: Function that will find the most likely offender
  Pre:         Array must be initialized
  Post:        An int will be returned that indicates the index of the offder
*/
int findOffender(const sector[], const int, const int);

/*
  Description: Function that will range check the numbers passed through
  Pre:         None
  Post:        New value
*/
void rangeCheck(int&, int, int);

/*
  Description: Overloaded operator that will compare two sectors
  Pre:         Both sectors must have values
  Post:        A true or fale value is returned
*/
bool operator<(const sector, const sector);

/*
  Description: Overloaded operator that will compare two offenders
  Pre:         Both sectors must have values
  Post:        A true or fale value is returned
*/
bool operator<(const offender, const offender);
#endif
