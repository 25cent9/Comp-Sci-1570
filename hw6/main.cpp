/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 10/8/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Recreate homework four to use functions and random
*/
#include "functions.h"
#include "constants.h"
#include <iostream>

using namespace std;

int main()
{
  int inventory[5] = {5,12,12,12,12}; //Array for the inventory
  int user_choice = 0;
  int machine_choice = 0 ;
  float subTotal = 0.0;
  bool quit = false;
  string user_name = " ";

  //Commands to set number of decimal places to 2
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  //Greeeting
  greeting();

  //Loop to valdate user name
  //Runs until the user inputs a valid name
  do
  {
    cout<<"Please enter your name: ";
    cin>>user_name;
  }while(user_name == " ");

  do
  {
    //Printing the menu
    printMenu(inventory);
    cout<<user_name<<", please enter your selection: ";
    cin>>user_choice;
    user_choice=rangeCheck(user_choice, MIN_CHOICE, MAX_CHOICE);
    machine_choice=machinePick(MIN_CHOICE,MACHINE_MAX);
    //Switch statement to determine what to do with machine's choice
    switch (machine_choice)
    {
      case 6:
      quit = true;  //Setting quit to true if value is 6
      break;
      case 7:
        cout<<"That selection is not avaliable. Try again!"<<endl;
        break;
      default:
      //Default actions taking place when value is not 6 or 7
        if(user_choice == machine_choice)
        {
          //Displaying agreement message if both values match
          cout<<COMP_AGREE<<endl;
        }
        else
        {
            //Printing out the approriate message and root
            cout<<SAYINGS[machine_choice-1]<<item_names[machine_choice-1]<<endl;
        }
        //Calling item selection to get the amount of item wanted
        itemSelection(inventory, machine_choice, subTotal);
        break;
    }
  }while(!quit);
  //Calculating the subtotal
  subTotal += ROUND_AMT;
  calcSubtotal(subTotal);
  cout<<"Subtotal: "<<subTotal<<endl;
  cout<<"Change: $"<<calculateChange(subTotal)<<endl;
  //Calling signOff function
  signOff();

  return 0;
}
