/*
  Programmer: Innocent Niyibizi
  File: functions.h
  Date: 11/27/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for functions and function constants
*/
#include <string>
#include "activist.h"
using namespace std;
const int PERCENTAGE = 100;
/*
  Description: Function to generate a random number
  Pre:	       None
  Post:	       Random between the given min and max is returned
*/
int randomNum(const int max, const int min);

/*
  Description: Function to simulate a day for the activist
  Pre:	       None
  Post:	       An activist is returned for data collecting
*/
Activist simulate(const int, int, const int, const int, const int, const int);

/*
  Description: Function to collect stats
  Pre:	       None
  Post:	       Values passed through by refernce are changed based on the
                passed activist
*/
void collectStats(Activist&, float&, float&, float&, float&, float&);

/*
  Description: Function to report the stats
  Pre:	       None
  Post:	       Stats are reported
*/
void reportStats(float, float, float, float, float, int);
