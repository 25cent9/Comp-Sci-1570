/*
  Programmer: Innocent Niyibizi
  File: structs.h
  Date: 10/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file to hold the structs
*/
#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
using namespace std;

struct sector
{
  int sectorNum;
  int lbsWaste;
};

struct offender
{
  string name;
  int guilt;
};

#endif
