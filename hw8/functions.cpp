/*
  Programmer: Innocent Niyibizi
  File: functions.cpp
  Date: 11/1/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Function definition File
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "functions.h"
#include "struct.h"
#include <string.h>
using namespace std;

void prompt(candidate & clown)
{
  static int num = 1;
  char question[MAX_SENT_LENGTH];
  cout<<"Candidate "<<num<<": ";
  cin.getline(question, MAX_SENT_LENGTH);
  strcpy(clown.question, question);
  num = num==1?2:1;
  return;
}

void getPrefix(candidate & clown, string filename)
{
  char temp[MAX_SENT_LENGTH];
  fstream in;
  int count = 0;
  in.open(filename.c_str());
  while(!in.eof())
  {
    count++;
    in.getline(temp, MAX_SENT_LENGTH);
  }
  int randomPre = randomNum(count, 1);
  in.close();
  in.open(filename.c_str());
  for(int i = 0; i<randomPre; i++)
  {
    in.getline(temp, MAX_SENT_LENGTH);
  }
  strcpy(clown.answer, temp);
  return;
}

void getSent(candidate &clown, string filename)
{
  char temp[MAX_SENT_LENGTH];
  fstream in;
  int randomPhraseNum = randomNum(MAX_PHRASE, MIN_PHRASE);
  int randomSent = 0;
  //Loop to run 2, 3, or 4 times depending on the random number
  for(int i=0; i<randomPhraseNum; i++)
  {
    in.open(filename.c_str());
    int fileLength = 0;
    in>>fileLength;
    //Getting a random number for the random sentence
    randomSent = randomNum(fileLength, 1);
    for (int j = 0; j <randomSent; j++)
    {
      in.getline(temp, MAX_SENT_LENGTH);  //Temporaily holding the sentence
    }
    //Copying the value of temp into the candidate's phrases array
    strcpy(clown.phrases[i], temp);
    in.close();
  }
  //Calling the getWords function to make the answer
  getWords(clown, randomPhraseNum);
  return;
}

void getInterj(candidate &clown, string filename)
{

  fstream in;
  in.open(filename.c_str());
  int fileLength = 0;
  in>>fileLength;
  int randomSent = randomNum(fileLength, 1);
  for(int i=1; i<randomSent; i++)
  {
    in.getline(clown.interjections,MAX_SENT_LENGTH);
  }
  in.close();
  return;
}

void getCanidateInfo(candidate& clown, const string sent, const string interj,
int & roundScore)
{
  int charCount = 0;
  int i = 0;
  if(randomNum(1,0))
    getPrefix(clown, PREFIX_PATH);
  getInterj(clown, interj); //Calling the interjection function
  getSent(clown, sent);
  //Countingt the amount of characters that are in the given question
  while(clown.question[i]!='\0')
  {
    charCount++;
    i++;
  }
  roundScore = calculateScore(clown)/charCount; //Finding the round score
  //Incrementing the candidate's score by the round score
  clown.score+=roundScore;
  return;
}

int randomNum(const int max, const int min)
{
  static bool first = true;
   if ( first )
   {
      srand(time(NULL)); //seeding for the first time only
      first = false;
   }
   return (rand()%(max-min+1))+min;
}

void clearClown(candidate& clown, const int sentLength)
{
  memset(clown.sentences, ' ', sentLength);
  clown.sentences[0]='\0';
  //Loop to go thoruh and set each value in words array to a blank string
  for(int i = 0; i<MAX_PHRASE; i++)
  {
    strcpy(clown.phrases[i], " ");  //Setting each value to a space
  }
  return;
}

void getWords(candidate& clown, const int phraseCount)
{
  int wordNums[MAX_PHRASE] = {1,1,1,1}; //Array to hold words in sentence
  int sentSizes[MAX_PHRASE] = {1,1,1,1};  //Array to hold words per section
  //Loop to run for the amount of sentences that are present
  for(int i=0; i<phraseCount; i++)
  {
    int j = 0;
    //Loop to run until the char is the null character
    while(clown.phrases[i][j] != '\0')
    {
      if(isspace(clown.phrases[i][j]))
      {
        wordNums[i]++;  //Incrementing the word count if space is present
      }
      j++;
    }
    //Setting sentence size bases on words and the number of sentences
    sentSizes[i] = wordNums[i]/phraseCount;
  }
  string temp = ""; //Temp string to hold value of word
  //Loop to construct the word
  for(int i=0; i<phraseCount; i++)
  {
    int spaceCount = 0;
    int index = 0;
    //If i is greater than 0 then a the index of the next sentence is found
    if(i>0)
    {
      index = findSectionIndex(sentSizes[i], i, clown);
      temp+=clown.interjections;
    }
    for(int j=index; j<MAX_SENT_LENGTH && spaceCount!=sentSizes[i]; j++)
    {
      if(isspace(clown.phrases[i][j]))
      {
        spaceCount++; //Incrementing space count
        temp+=clown.phrases[i][j];  //Adding current char temp string
      }
      else
        temp+=clown.phrases[i][j];
    }
  }
  temp+=getPuncuation();  //Getting random puncutaion
  strcat(clown.answer, temp.c_str()); //Concatnating the answer with the temp

  return;
}

int findSectionIndex(const int size, const int section, const candidate clown)
{
  int search = ((section+1)*size)-size; //Number of spaces to look for
  int spaces = 0;
  int i;
  //Running until the search value is found
  for(i=0; i<MAX_SENT_LENGTH && spaces!= search; i++)
  {
    if(isspace(clown.phrases[section][i]))
      spaces++;
  }
  return i;
}

int calculateScore(const candidate clown)
{
  int score = 0;
  char sentence[MAX_SENT_LENGTH];
  //Copying the candidate's answer into sentence
  strcpy(sentence, clown.answer);
  //Calling the search function for each point value
  search(sentence, ONEPOINT, 1, score, ONEPOINT_COUNT);
  search(sentence, TWOPOINT, 2, score, TWOPOINT_COUNT);
  search(sentence, THREEPOINT, 3, score, THREEPOINT_COUNT);
  search(sentence, FOURPOINT, 4, score, FOURPOINT_COUNT);
  search(sentence, FIVEPOINT, 5, score, FIVEPOINT_COUNT);
  search(sentence, EIGHTPOINT, 8, score, EIGHTPOINT_COUNT);
  search(sentence, TENPOINT, 10, score, TENPOINT_COUNT);
  return score;
}

void search(const char sentence[], const char characters[], const int pointValue,
int & score, const int arrLength)
{
  int i = 0;
  int wordScore = 0;
  int tempScore = 0;
  int multiplier = 1;
  while(sentence[i]!='\0')
  {
    for(int j=0; j<arrLength; j++)
    {
      if(tolower(sentence[i])==characters[j])
      {
        multiplier=chance("Char");
        if(multiplier>1)
          wordScore+=(multiplier*pointValue);
        else
          wordScore+=pointValue;
      }
      else if(isspace(sentence[i]))
      {
        wordScore*=chance("Word");
        tempScore+=wordScore;
      }
    }
    i++;
  }
  score+=tempScore;
  return;
}

int chance(const string type)
{
  int multiplier = 0;
  int percent = randomNum(100, 1);
  if(type=="Char")
  {
    switch (percent)
    {
      case TRIPLE_CHAR_CHANCE:
        multiplier=3;
        break;
      case DOUBLE_WORD_CHANCE:
        multiplier = 2;
        break;
      default:
        multiplier = 1;
        break;
    }
  }
  else
  {
    switch (percent)
    {
      case TRIPLE_WORD_CHANCE:
        multiplier=3;
        break;
      case DOUBLE_WORD_CHANCE:
        multiplier = 2;
        break;
      default:
        multiplier = 1;
        break;
    }
  }
  multiplier = 1;
  return multiplier;
}

char getPuncuation()
{
  int percent = randomNum(100,1);
  char punct = ' ';
  switch (percent)
  {
    case PERIOD_CHANCE:
      punct = '.';
      break;
    case QUESTION_CHANCE:
      punct = '?';
      break;
    case EXCLAMATION_CHANCE:
      punct = '!';
      break;
    default:
      punct='.';
      break;
  }
  return punct;
}
