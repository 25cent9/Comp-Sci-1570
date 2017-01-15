/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 11/1/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to calculate score of a presidential debate
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "functions.h"
#include "struct.h"
#include "constants.h"
using namespace std;

int main()
{

  candidate candidateOne;
  candidate candidateTwo;
  int score = 0;
  //Loop to run until all questions have been asked
  for(int i = 0; i<DEBATE_QUESTIOINS; i++)
  {
    score = 0;
    prompt(candidateOne); //Prompting for user input
    //Calling function to get the candidate's appropriate text
    getCanidateInfo(candidateOne, SENT_ONE_PATH, INTJ_ONE_PATH, score);
    cout<<candidateOne.answer<<endl;  //Displaying the answer that was generated
    cout<<"\tScore: "<<score<<endl;  //Displaying the score
    clearClown(candidateOne, MAX_SENT_LENGTH);  //Clearing any necessary values
    prompt(candidateTwo);
    getCanidateInfo(candidateTwo, SENT_TWO_PATH, INTJ_TWO_PATH, score);
    cout<<candidateTwo.answer<<endl;
    cout<<"\tScore: "<<score<<endl;
    clearClown(candidateTwo, MAX_SENT_LENGTH);
  }
  //Displaying the final results and winner
  cout<<"Final Score:"<<endl;
  cout<<"Candidate 1: "<<candidateOne.score<<endl;
  cout<<"Candidate 2: "<<candidateTwo.score<<endl;
  cout<<"Winner:"<<((candidateOne.score>candidateTwo.score)?"Candidate One!":
                    "Candidate Two!")<<endl;
  return 0;
}
