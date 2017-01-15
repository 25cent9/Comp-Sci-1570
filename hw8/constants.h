/*
  Programmer: Innocent Niyibizi
  File: constants.h
  Date: 11/3/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for constants
*/
#ifndef CONSTANTS_H
#define CONSTANTS_H

using namespace std;
//Constnats for the file paths
const string SENT_ONE_PATH = "candidate1_sentences.dat";
const string INTJ_ONE_PATH = "candidate1_interjections.dat";
const string SENT_TWO_PATH = "candidate2_sentences.dat";
const string INTJ_TWO_PATH = "candidate2_interjections.dat";
const string PREFIX_PATH = "prefix_expressions.dat";
//Constnats for the
const int MAX_SENT_LENGTH = 1001;
const int DEBATE_QUESTIOINS = 8;
const int MIN_PHRASE = 2;
const int MAX_PHRASE = 4;
const int MAX_SENT_CHAR = 20;

//Constnats for array counts
const int PUNCTUATION_COUNT = 3;
const int ONEPOINT_COUNT = 10;
const int TWOPOINT_COUNT = 2;
const int THREEPOINT_COUNT = 4;
const int FOURPOINT_COUNT = 5;
const int FIVEPOINT_COUNT = 1;
const int EIGHTPOINT_COUNT = 2;
const int TENPOINT_COUNT = 2;

//Constnats for the chance percentage values
const int PERIOD_CHANCE = 40;
const int QUESTION_CHANCE = 30;
const int EXCLAMATION_CHANCE = 20;
const int TRIPLE_CHAR_CHANCE = 2;
const int DOUBLE_LETTER_CHANCE =2;
const int DOUBLE_WORD_CHANCE = 5;
const int TRIPLE_WORD_CHANCE = 2;
const int INTERJECTION_CHANCE = 1;
//Constnats for scoring arrays
const char PUNCTUATION[3] = {'.','!','?'};
const char ONEPOINT[10] = {'e','a','i','o','n','r','t','l','s','u'};
const char TWOPOINT[2] = {'d','g'};
const char THREEPOINT[4] = {'b','c','m','p'};
const char FOURPOINT[5] = {'f','h','v','w','y'};
const char FIVEPOINT[1] = {'k'};
const char EIGHTPOINT[2] = {'j','x'};
const char TENPOINT[2] = {'q','z'};

#endif
