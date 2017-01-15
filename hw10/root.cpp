/*
  Programmer: Innocent Niyibizi
  File: root.cpp
  Date: 11/27/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Cpp file for the root class
*/

#include <iostream>
#include <string>
#include "root.h"
#include "functions.h"

using namespace std;

//Overoaded default constructor for root
Root::Root()
{
  m_effect = 0;
  int type = randomNum(MAX_RANDNUM, MIN_RANDNUM);
  int tempNum = 0;
  //Getting a new random number until it is not 0
  while(type == 0)
  {
    type = randomNum(MAX_RANDNUM, MIN_RANDNUM);
  }

  //switch for the type of root passed trough
  //Base on the type a random is generated from the approriate interval
  //and divided by the approriate divisor
  switch (type)
  {
    case -1:
      m_name = NEG_NAME;
      tempNum = randomNum(MAX_NEGINTERVAL, MIN_NEGINTERVAL);
      m_effect = static_cast<float>(tempNum)/NEG_DIVISOR;
      break;
    case 1:
      m_name = POS_NAME;
      tempNum = randomNum(MAX_POSINTERVAL, MIN_POSINTERVAL);
      m_effect = static_cast<float>(tempNum)/POS_DIVISOR;
      break;
  }
}
