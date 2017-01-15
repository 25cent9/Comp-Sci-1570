/*
  Programmer: Innocent Niyibizi
  File: functions.h
  Date: 11/1/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for function protoypes
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <fstream>
#include "struct.h"
using namespace std;
/*
  Description: Function that will gather phrases from the file
  Pre:         Filename must be in current directory
  Post:        Candidate's phrases array is updated
*/
void getSent(candidate&, string);

/*
  Description: Function that will gather the interjection from the file
  Pre:         Filename must be in current directory
  Post:        Candidate's interjection is updated
*/
void getInterj(candidate&, string);

/*
  Description: Function that will generate a random number
  Pre:         Both ints must be greater than 0
  Post:        A random number between the two values is returned
*/
int randomNum(const int, const int);

/*
  Description: Function where all functions relating to candidate will
               be called
  Pre:         Candidate must be intialized
  Post:        Candidate's information is updated
*/
void getCanidateInfo(candidate&, const string, const string, int &);

/*
  Description: Function that will clear anything that needs to be cleared
  Pre:         Candidate must be intialized, int > 0
  Post:        All values will be defaulted back to a space
*/
void clearClown(candidate&, const int);

/*
  Description: Function that will generate the answer for the candidate
  Pre:         Candidate must be intialized
  Post:        The candidate's phrase is generated
*/
void getWords(candidate&, const int);

/*
  Description: Function used to find the starting point of the
               next sentence
  Pre:         None
  Post:        The starting index for the next phrase is returned
*/
int findSectionIndex(const int, const int, const candidate);

/*
  Description: Function that will calculate the score of the answer
  Pre:         None
  Post:        The current score and candidate's overall score is saved
*/
int calculateScore(const candidate);

/*
  Description: Function that will search the array of characters for the
               given point values and generate the appropriate score
  Pre:         None
  Post:        Score is updated
*/
void search(const char[], const char[], const int,
int &, const int);

/*
  Description: Function that will determine the chance of the given situation
  Pre:         None
  Post:        A number is passed back indicating the mutliplier value
*/
int chance(const string);

/*
  Description: Function that will pick the end punctuation
  Pre:         None
  Post:        Punctuation is returned based on the random number
*/
char getPuncuation();

/*
  Description: Function that will prompt the user for questions
  Pre:         candidate must be intialized
  Post:        Question is taken in from user and stored for scoring
*/
void prompt(candidate &);

/*
  Description: Function that will randomly get a prefix
  Pre:         candidate must be intialized
  Post:        The interjection is added to the start of the answer
*/
void getPrefix(candidate&, string);
#endif
