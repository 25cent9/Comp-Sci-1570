#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
  Programmer: Innocent Niyibizi
  File: constants.h
  Date: 10/3/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for the constants in the program
*/
#include <string>
using namespace std;

const int MAX_LBS = 100;  //Max value of pounds of wasted food
const int MIN_LBS = 0;    //Min value of pounds of wasted food
const int MIN_MILE = 1;   //Min value of public transit miles
const int MAX_MILE = 250; //Max value of public transit miles
const int MIN_AGE = 1;    //Min value of age
const int MAX_AGE = 100;  //Max value of age
const int MIN_PIG = 1;    //Min value od pigs
const int MAX_PIG = 10;   //Max value of pigs
const int CURR_DECONTSRUCT = 570; //Value of current destruction value
const int DECONSTRUCT_DIVISOR = 2;//Value of current destruction value divisor
const float WASTE_FOOD_MULT = 1.5;  //Multiplier for wasted food
const int WASTE_FOOD_ADD = 6;       //Offset for wasted food
const int TRANSIT_MULT = -2;        //Multiplier for transit value
const int TRANSIT_ADD = 1;          //Offset value for the transit ammount
//Constants for the menu items 
//Each menu item has a constant for avaliable and completed 
const string MENU_1 = "1. Wasteful (food) Consumption\n";
const string MENU_1_COMP= "1. Wasteful (food) Consumption (Completed)\n";
const string MENU_2 = "2. Public Transit Usage\n";
const string MENU_2_COMP = "2. Public Transit Usage (Completed)\n";
const string MENU_3 = "3. Industrial Complicity\n";
const string MENU_3_COMP = "3. Industrial Complicity (Completed)\n";
const string MENU_4 = "4. Farm-related Methane\n";
const string MENU_4_COMP = "4. Farm-related Methane (Completed)\n";
#endif