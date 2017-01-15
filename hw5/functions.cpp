/*
  Programmer: Innocent Niyibizi
  File: functions.cpp
  Date: 10/3/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: cpp file for each function in program
*/

#include "functions.h"
#include "constants.h"

void greeting()
{
  cout<<"Hello!! Welcome to the Carbon Foorprint Survey "<<endl;
  return;
}

void printMenu(bool optOne, bool optTwo, bool optThree, bool optFour)
{
  cout<<"Carbon Foorprint Survey\n"
      <<"------------------------------------\n"
      <<(!optOne?MENU_1:MENU_1_COMP)
      <<(!optTwo?MENU_2:MENU_2_COMP)
      <<(!optThree?MENU_3:MENU_3_COMP)
      <<(!optFour?MENU_4:MENU_4_COMP)
      <<"5. Computer GUILT value\n";
      return;
}

float foodConsump()
{
  float num = 0.0;  //Float to hold the lbs of wasted food
  //For loop to run while valis is not true
  for(bool valid = false; !valid;)
  {
    cout<<"Please enter the lbs of food you waste: (0-100): ";
    cin>>num;
    //Checking num to see if it is over the max or less than the min 
    if(num<MIN_LBS)
    {
      cout<<"Error!! Too low"<<endl;
    }
    else if(num>MAX_LBS)
    {
      cout<<"Error!! Too high."<<endl;
    }
    else
    {
      valid = true;
    }
  }
  return num; //Returning num back to the main function
}

int publicTrans()
{
  char choice = ' ';
  int miles = 0;
  bool valid = false;
  cout<<"Do you use public transit? [Y/N]: ";
  cin>>choice;
  //Loop to run until the user puts in a y or n
  do
  {
    switch(choice)
    {
      case 'Y':
      case 'y':
        valid = true;
        cout<<"Please enter the amount of miles traveled [1-250]: ";
        //Loop to run until miles is greater than min and higher than max
        do
        {
          cin>>miles;
          if(miles<MIN_MILE)
          {
            cout<<"Error! Too low. Enter a higher number: ";
          }
          else if(miles>MAX_MILE)
          {
            cout<<"Error! Too high. Enter a lower number: ";
          }
        }while(miles<MIN_MILE || miles>MAX_MILE);
        break;
      case 'N':
      case 'n':
        return 0;
        break;
      default:
        cout<<"Please enter Y or N: ";
        cin>>choice;
        break;
    }
  }while(!valid);
  return miles;
}

int burnTest()
{
  char choice = ' ';
  int age = 0;
  bool valid = false;
  cout<<"Are you Mr. Burns? [Y/N]: ";
  cin>>choice;
  //Loop to run until the user puts in a y or n
  do
  {
    //If statement to see if the user is Mr. Burns
    if(choice == 'Y' || choice == 'y')
    {
      return CURR_DECONTSRUCT;  //Returning the 
    }
    else if(choice == 'N' || choice == 'n')
    {
      //Asking the user if they are related to Mr. Burns
      //Only happens when the users selects no to being Mr. Burns
      cout<<"Are you related to Mr. Burns [Y/N]: ";
      cin>>choice;
      //Switch for the user's choice
      switch(choice)
      {
        case 'Y':
        case 'y':
        //Returning the current destruction coefficient divided by the divisor
          return (CURR_DECONTSRUCT/DECONSTRUCT_DIVISOR);
          break;
        case 'N':
        case 'n':
          //Asking for user's age if they are not related to Mr. Burns
          valid = true;
          cout<<"Please enter your age: ";
          cin>>age;
          //Loop to run while age is less than min and more than max
          while(age > MAX_AGE || age < MIN_AGE)
          {
            //Displaying error messages for each approriate error
            if(age > MAX_AGE)
            {
              cout<<"Your age is too large! \n Please enter a new age: ";
              cin>>age;
            }
            else if(age < MIN_AGE)
            {
              cout<<"Your age is too low! \n Please enter a new age: ";
              cin>>age;
            }
            else
            {
              cout<<"Invalid input! "
                  <<"Please try again: ";
              cin>>age;
            }  
          }
          break;
      }
    }
  }while(!valid);
  
  return age; //Returning age
}

float pigsEaten(float waste)
{
  int numPigs = 0;
  //Bool to hold if the user has inputted a c
  bool check = numPigs > MAX_PIG || numPigs < MIN_PIG;
  cout<<"Please enter the amount of whole pigs eaten by your father last week: "
      <<"["<<MIN_PIG<<"-"<<MAX_PIG<<"]";
  cin>>numPigs;
  //Runnig a loop to check if the input is within the range
  do
  {
   if(numPigs > MAX_PIG)
   {
     cout<<"Error! Please enter a lower amount of pigs eaten: ";
     cin>>numPigs;
   }
   else if(numPigs < MIN_PIG)
   {
     cout<<"Error! Please enter a higher number of pigs eaten: ";
     cin>>numPigs;
   }
  }while(!check);
  
  //Returning the result of the formula
  return waste*numPigs*numPigs+3*numPigs+5; 
}

bool computeCheck(bool first, bool second, bool third, bool fourth)
{
  //Checking to see if each option is complete
  //If not then a message informs the user that the option is not complete
  if(!first)
    cout<<"You must complete the first option"<<endl;
  if(!second)
    cout<<"You must complete the second option"<<endl;
  if(!third)
    cout<<"You must complete the third option"<<endl;
  if(!fourth)
    cout<<"You must complete the fourth option"<<endl;
  
  //Returning the value of the four bools
  return (first && second && third && fourth); 
}

float modifyValues(float MULT, int ADD, float value)
{
  return ((MULT*value)+ADD);
}

float calcGuilt(float food, int trans, int burns, float pigs)
{
  return (food+trans+burns+pigs);
}

void goodBye()
{
  cout<<"Have a wonderful day! Make sure to recycle!"<<endl;
}