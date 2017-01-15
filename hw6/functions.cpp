/*
  Programmer: Innocent Niyibizi
  File: functions.cpp
  Date: 10/8/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: cpp file for each function in program
*/

#include "functions.h"
#include "constants.h"
#include <cstdlib>
#include <ctime>

void greeting()
{
  cout<<"Hello! Welcome to Roots 'n Stuff!"<<endl;
  return;
}

void printMenu(int inventory[])
{
  cout<<"Roots 'n Stuff \n";
  //Ternary operators to determine which version of the item to display
  cout<<(inventory[0]>0?ITEM1:ITEM1_GONE)<<endl
      <<(inventory[1]>0?ITEM2:ITEM2_GONE)<<endl
      <<(inventory[2]>0?ITEM3:ITEM3_GONE)<<endl
      <<(inventory[3]>0?ITEM4:ITEM4_GONE)<<endl
      <<(inventory[4]>0?ITEM5:ITEM5_GONE)<<endl
      <<"6. Quit"<<endl;
  return;
}

void itemSelection(int inventory[], const int USER_CHOICE, float& subTot)
{

  int user_amnt = 0;
  int machine_amnt = 0 ;
  if(inventory[USER_CHOICE-1] < MIN_CHOICE)
  {
   cout<<"Can't you read! I don't have anymore!"<<endl;
   return;
  }
  cout<<"Enter the amount you would like: ";
  cin>>user_amnt;
  machine_amnt = machinePick(MIN_CHOICE,user_amnt*USER_AMNT_FACTOR);
  compare(user_amnt, machine_amnt);
  if(inventory[USER_CHOICE-1]<machine_amnt)
  {
    cout<<"Sorry but there are only "<<inventory[USER_CHOICE-1]<<" left. \n"
          " Only part of your order will be filled."<<endl;
    user_amnt = inventory[machine_amnt-1];
  }

  inventory[USER_CHOICE-1]-=machine_amnt;
  subTot += PRICES[USER_CHOICE-1]*machine_amnt;
  return;
}

int rangeCheck(int num, const int MIN, const int MAX)
{
  //Bool to check if num is within range of min and max
  bool valid = (num > MIN || num < MAX);
  //Loop to run until the value of num is in the range
  do
  {
    if(num < MIN)
    {
      cout<<"Error! Too low. Please select a larger number: ";
      cin>>num;
    }
    else if(num > MAX)
    {
      cout<<"Error! Too high. Please select a smaller number: ";
      cin>>num;
    }
  }while(!valid);
  //Returning num after it is valid
  return num;
}

int machinePick(const int from, const int to)
{
  //Setting a static bool value to determine if function is running for the
  //first time
  //If it is then rand will be seeded
  static bool first = true;
  if(first)
    srand(time(NULL));
  first = false;
  //Creating a int to hold the value of the randomly generated number
  int machine = rand()%(to-from+1)+from;
  return machine;
}

void compare(const int user, const int machine)
{
  //Comparing the user's value to the machines value to display the approriate
  //error message and value
  if(user == machine)
    cout<<"I can do that"<<endl;
  else if(machine < user)
    cout<<"That's waayyy too much for you. You want "<<machine<<endl;
  else if(machine >  user)
    cout<<"Naw naw naw, you need "<<machine<<endl;

  return;
}

void calcSubtotal(float& subtot)
{
  //Checking to see which tax value will be added to the subtotal
  if(subtot < SUBMIN)
    subtot+=(subtot*LOW_AMNT_TAX);
  else if(subtot > SUBMIN && subtot < SUBMAX)
    subtot+=(subtot*MID_AMNT_TAX);
  else if(subtot > SUBMAX)
    subtot+=(subtot*HIGH_AMNT_TAX);

  return;
}

float calculateChange(const float total)
{
  float amount_tendered = 0;
  //Loop to run until user inputs value greater than the toatl
  do
  {
   cout<<"Please enter the amount you wish to pay with: $";
   cin>>amount_tendered;
   if(amount_tendered < total)
   {
     cout<<"Why are you so cheap!?"<<endl;
   }
 }while(amount_tendered < total);
 return amount_tendered-total;  //Returning the change
}

void signOff()
{
  cout<<"Bye now. Make sure to recycle!"<<endl;
  return;
}
