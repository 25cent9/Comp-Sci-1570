/*
  Programmer: Innocent Niyibizi
  File: constants.h
  Date: 10/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file to hold the constants
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H
//Constant array of strings that has the names of the offenders
const string offenderNames[15] = {"Homer","Maggie","Bart","Moe","Barney",
                                  "Marge","Cletus","Snake","Mr. Burns",
                                  "Dr. Nick","Krusty the Clown",
                                  "Chief Wiggum","Ralph Wiggum",
                                  "Skinner","Lenny"};
const int LOWRANK = 1;            //Value of lowest rank
const int HIGHRANK = 15;          //Value of highest rank
const int LOWSECTOR = 1;          //Lowest sector number
const int HIGHSECTOR = 7;         //Highest sector number
const int LOWWEIGHT = 25;         //Lowest weight value
const int HIGHWEIGHT = 500;       //Highest weight value
const int LOWGUILT = 100;         //Lowest guilt value
const int HIGHGUILT = 10000;      //Highest guilt value
const int DATABASE_SIZE = 15;     //Size of each Database
const int TOP_OFFENDERS_NUM = 2;  //Number of top offenders
const int DIVISOR = 2;            //Divisor for finding least offendes

//Constants for each sector number
const int SECTOR_ONE = 0;
const int SECTOR_TWO = 1;
const int SECTOR_THREE = 2;
const int SECTOR_FOUR = 3;
const int SECTOR_FIVE = 4;
const int SECTOR_SIX = 5;
const int SECTOR_SEVEN = 6;
#endif
