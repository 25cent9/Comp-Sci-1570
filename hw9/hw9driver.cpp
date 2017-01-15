/*
   Programmer: Jennifer Leopold

   Date: November 8, 2016

   File: main.cpp

   Purpose: Program that tests classes for a town, an activist,
         and a polluter.

   To compile: fg++ main.cpp town.cpp
          activist.cpp polluter.cpp -o hw9

   To execute: ./hw9
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "town.h"
#include "activist.h"
#include "polluter.h"
using namespace std;

// # of random moves by the activist & polluter to test
const int NUM_RANDOM_MOVES = 4;

// Town's grid size
const short TOWN_SIZE = 7;


int main()
{
  cout << "\nTesting will now begin...\n";

  // Seed the random number generator
  srand(time(NULL));

  //*** Test construction of Town
  Town springfield(TOWN_SIZE);
  cout << "\nTown initially looks like this:\n";
  cout << springfield << endl;


  //*** Test construction and functionality of Activist & Town
  Activist lisa("Lisa");
  cout << "\nActivist initially looks like this:\n";
  cout << lisa << endl;

  lisa.placeMeInMiddle(springfield);
  cout << "\nAfter placing Activist in middle of town:\n";
  cout << springfield << endl;

  cout << "Here are " << NUM_RANDOM_MOVES
       << " moves by the Activist:\n";
  for (int i = 1; i <= NUM_RANDOM_MOVES; i++)
  {
    lisa.randMove(springfield);
    cout << springfield << endl;
  }

  //*** Test construction and functionality of Polluter & Town
  Polluter homer("Homer");
  homer.placeMe(springfield);
  cout << "Town after randomly placing a Polluter:\n";
  cout << springfield << endl;

  cout << "Here are " << NUM_RANDOM_MOVES
       << " moves by the Polluter:\n";
  for (int i = 1; i <= NUM_RANDOM_MOVES; i++)
  {
     homer.randMove(springfield);
     cout << springfield << endl;
  }
  
  cout << "That concludes our tests.\n";

  return 0;
}
