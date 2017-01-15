/*
  Programmer: Innocent Niyibizi
  File: hw4.cpp
  Date: 9/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Create program to simulate a vending machine
*/

#include <iostream>
using namespace std;

//Creating constants for the price of each root
const double ITEM1_PRICE = 4.50;  //Price of Ginko Root
const double ITEM2_PRICE = 1.23; //Price of Mandrake Root
const double ITEM3_PRICE = 2.39;  //Price of Ginseng Root
const double ITEM4_PRICE = 99.98;  //Price of Square Root
const double ITEM5_PRICE = 0.78;  //Price of Vitamin R Root
const float TAX = 0.16;            //Tax set at 16%
const int MIN_AMNT = 1;             //Lowest amount user can take
const float ROUND_AMT = 0.005;

int main()
{
  //Declaring variables
  string user_name = " "; //String for the users name
  string gink_string = " "; //Ginko root message value
  string mandrake_string = " "; //Mandrake root message value
  string ginseng_string = " ";  //Ginseng root message value
  string square_string = " ";   //Square root message value
  string r_string = " ";        //Vitamin R root message value
  
  double subTotal = 0.0;  //Double for the subtotal
  double amnt_paid = 0.0; //double fot the user inputted amount
  int gink_count = 5;     //Inventory for Ginko Root
  int mandrake_count = 4; //Inventory for Mandrake Root
  int ginseng_count = 9;  //Inventory for Ginseng root
  int square_count = 11;  //Inventory for Square Root
  int r_count = 8;        //Inventory for Vitamin R Root
  int selection_count;    //Holds the amount the items the user selected
  char user_input = ' ';  //Char to hold user input from menu
  bool quit;              //Bool to see if user wants to quit
  double change = 0.0;
  
  //Commands to set number of decimal places to 2
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  //Greeeting
  cout<<"Hello, Welcome to Roots 'n Stuff!"<<endl;
  
  //Loop to valdate user name
  //Runs until the user inputs a valid name
  do
  {
    cout<<"Please enter your name: ";
    cin>>user_name;
  }while(user_name == " ");
  
  //Loop to run as long as the bool "quit" is false
  do
  {
    quit = false; //Setting quit to false as default
    selection_count = 0;  //Setting the amount of selected item to 0
    
    //Ternary operators for each item
    //Each item will either a string based on the iventory count of that item
    gink_string = (gink_count>0)?"1. Ginko Root ($4.50) \n":
    "1. Ginko Root ($4.50) NO LONGER AVAILABLE \n";
    mandrake_string = (mandrake_count > 0)?"2. Mandrake Root ($1.23) \n":
    "2. Mandrake Root ($1.23) NO LONGER AVAILABLE \n";
    ginseng_string = (ginseng_count > 0)?"3. Ginseng Root ($2.39) \n":
    "3. Ginseng Root ($2.39) NO LONGER AVAILABLE \n";
    square_string = (square_count > 0)?"4. Square Root ($99.98) \n":
    "4. Square Root ($99.98) NO LONGER AVAILABLE \n";
    r_string = (r_count > 0)?"5. Vitamin R Root ($0.78) \n":
    "5. Vitamin R Root ($0.78) NO LONGER AVAILABLE \n";
    
    //Printing the menu
    cout<<"Roots 'n Stuff \n"
        <<"--------------- \n";
        cout<<gink_string
        <<mandrake_string
        <<ginseng_string
        <<square_string
        <<r_string
        <<"6. Quit"<<endl;
    cout<<user_name<<" please make a selection: ";
    cin>>user_input;
    
    //Switch to that uses user_input to determine the selection
    switch(user_input)
    {
      case '1':
        //Checking to see if the user picked the item that is not available
        if(gink_count <= MIN_AMNT)
        {
          cout<<user_name<<", can you not read? The item isn't avalible."
              <<endl;
          break;  //Leaving the switch after the error is displayed
        }
        
        //Loop that will run until the user inputs a number greater than 0
        do
        {
          cout<<user_name<<" please enter the amount you would like: ";
          cin>>selection_count;
          
          //Displaying an error if selection count is less than one 
          if(selection_count< MIN_AMNT)
          {
            cout<<"Too low!!"<<endl;
          }
        }while(selection_count < MIN_AMNT);
        
        //Checking to see if user amount is greater than the current count
        //If so then only part of the order will be filled
        if(selection_count>gink_count)
        {
          cout<<"Sorry, "<<user_name<<" but there is only "
              <<gink_count<<" Ginko Roots avalible."
              <<" Only part of your order will be filled. \n";
          selection_count = gink_count;
        }

        subTotal += (selection_count*ITEM1_PRICE);
        gink_count-=selection_count;
        break;
      case '2':
        //Checking to see if the user picked the item that is not available
        if(mandrake_count < MIN_AMNT)
        {
          cout<<user_name<<", can you not read? The item isn't avalible."
              <<endl;
          break;  //Leaving the switch after the error is displayed
        }
        
        //Loop that will run until the user inputs a number greater than 0
        do 
        {
          cout<<user_name<<" please enter the amount you would like: ";
          cin>>selection_count;
          
          //Displaying an error if selection count is less than one 
          if(selection_count< MIN_AMNT)
          {
            cout<<"Too low!!"<<endl;
          }
        }while(selection_count< MIN_AMNT);
        
        //Checking to see if user amount is greater than the current count
        //If so then only part of the order will be filled
        if(selection_count>mandrake_count)
        {
          cout<<"Sorry, "<<user_name<<" but there is only "
              <<mandrake_count<<" Mandrake Roots avalible."
              <<" Only part of your order will be filled. \n";
          selection_count = mandrake_count;
        }
        subTotal += (selection_count*ITEM2_PRICE);
        mandrake_count-=selection_count;
        break;
      case '3':
        //Checking to see if the user picked the item that is not available
        if(ginseng_count < MIN_AMNT)
        {
          cout<<user_name<<", can you not read? The item isn't avalible."
              <<endl;
          break;  //Leaving the switch after the error is displayed
        }
        
        //Loop that will run until the user inputs a number greater than 0
        do 
        {
          cout<<user_name<<" please enter the amount you would like: ";
          cin>>selection_count;
          
          //Displaying an error if selection count is less than one 
          if(selection_count< MIN_AMNT)
          {
            cout<<"Too low!!"<<endl;
          }
        }while(selection_count< MIN_AMNT);
        
        //Checking to see if user amount is greater than the current count
        //If so then only part of the order will be filled
        if(selection_count>ginseng_count)
        {
          cout<<"Sorry, "<<user_name<<" but there is only "
              <<ginseng_count<<" Ginseng Roots avalible."
              <<" Only part of your order will be filled. \n";
          selection_count = ginseng_count;
        }
        
        subTotal += (selection_count*ITEM3_PRICE);
        ginseng_count-=selection_count;
        break;
      case '4':
        //Checking to see if the user picked the item that is not available
        if(square_count < MIN_AMNT)
        {
          cout<<user_name<<", can you not read? The item isn't avalible."
              <<endl;
          break;  //Leaving the switch after the error is displayed
        }
        
        //Loop that will run until the user inputs a number greater than 0
        do
        {
          cout<<user_name<<", please enter the amount you would like: ";
          cin>>selection_count;
          
          //Displaying an error if selection count is less than one 
          if(selection_count< MIN_AMNT)
          {
            cout<<"Too low!!"<<endl;
          }
        }while(selection_count< MIN_AMNT);
        
        //Checking to see if user amount is greater than the current count
        //If so then only part of the order will be filled
        if(selection_count>square_count)
        {
          cout<<"Sorry, "<<user_name<<" but there is only "
              <<square_count<<" Square Roots avalible."
              <<" Only part of your order will be filled. \n";
          selection_count = square_count;
        }
        
        subTotal += (selection_count*ITEM4_PRICE);
        square_count-=selection_count;  
        break;
      case '5':
        //Checking to see if the user picked the item that is not available
        if(r_count < MIN_AMNT)
        {
          cout<<user_name<<", can you not read? The item isn't avalible."
              <<endl;
          break;  //Leaving the switch after the error is displayed
        }
        
        //Loop that will run until the user inputs a number greater than 0
        do
        {
          cout<<user_name<<" please enter the amount you would like: ";
          cin>>selection_count;
          
          //Displaying an error if selection count is less than one 
          if(selection_count< MIN_AMNT)
          {
            cout<<"Too low!!"<<endl;
          }
        }while(selection_count< MIN_AMNT);
        
        //Checking to see if user amount is greater than the current count
        //If so then only part of the order will be filled
        if(selection_count>r_count)
        {
          cout<<"Sorry, "<<user_name<<" but there is only "
              <<r_count<<" Vitamin R Roots avalible."
              <<" Only part of your order will be filled. \n";
          selection_count = r_count;
        }
        
        subTotal += (selection_count*ITEM5_PRICE);
        r_count-=selection_count;  
        break;
      case '6':
        quit = true;
        break;
      default: 
        cout<<"Sorry, that selection isn't avalible."<<endl;
        break;
    }
  }while(!quit);
  
  cout<<subTotal+(static_cast<int>(subTotal*TAX)+ROUND_AMT)<<endl;
  subTotal += (subTotal*TAX+ROUND_AMT);
  cout<<user_name<<", your total is $"<<subTotal;
  
  //Loop to run until the user puts in an amount more than the total
  do
  {
    cout<<"\nPlease enter the amount you wish to pay with: $";
    cin>>amnt_paid;
    if(amnt_paid < subTotal)
    {
      cout<<user_name<<", why are you so cheap!?";
    }
  }while(amnt_paid < subTotal);
  change = amnt_paid-subTotal;  //Calculating the change
  cout<<user_name<<", your change : $"<<change<<endl; //Displaying the change
  
  cout<<"Thank you "<<user_name<<"!! Have a nice day and go plant a tree!!"<<endl;
  return 0;
}
