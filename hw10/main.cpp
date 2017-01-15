/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 11/27/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to simulate an activist chasing a polluter
*/
#include "functions.h"
#include "activist.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
  int gridSize, numRoots, numCops, numDays,
        bumpLoss, copLoss;
  float avgToxicity = 0, exits = 0, success = 0, death = 0, whackedOut = 0;
  fstream in;
  Activist simulation;
  in.open("config.dat");
  in>>gridSize;
  in>>numRoots;
  in>>numCops;
  in>>numDays;
  in>>bumpLoss;
  in>>copLoss;
  in.close();
  for(int i = 0; i<numDays; i++)
  {
    simulation=simulate(gridSize, numRoots, numCops, bumpLoss, copLoss, i);
    collectStats(simulation, avgToxicity, exits, success, death, whackedOut);
  }
  reportStats(avgToxicity, exits, success, death, whackedOut, numDays);
  return 0;
}
