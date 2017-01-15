/*
  Programmer: Innocent Niyibizi
  File: hw5.cpp
  Date: 9/28/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Create program to display carbon footprint of user
*/
#include "constants.h"
#include "functions.h"  //Including functions.h which has all of the functions
//Functions.h includes constants.h
//Constants.h holds all of the constants of the program
using namespace std;

int main()
{
  //Declaring variables for use in main
  float food = 0.0, pigs = 0.0;
  int trans = 0, burnsNum = 0;  
  //Char to hold the user's selection
  char selection = 0;
  //Bool to hold if the survery is completed
  bool compute = false;
  //Bools to hold if each option was chosen
  bool optOne = false, optTwo = false, optThree = false, optFour = false;
  greeting(); //Callig the greeting function
  do
  {
    printMenu(optOne, optTwo, optThree, optFour);
    cout<<"Please make a selection: ";
    cin>>selection;
    
    //Switch statement for the user's selection
    //The corresponding option is checked to see if it is complete
    //If the option is complete then the program breaks out of switch
    //If it is not complete then the appropriate function is called
    //The bool for the option is changed to true
    switch(selection)
    {
      case '1':
        if(optOne)
        {
          cout<<"Option has already been completed!"<<endl;
          break;
        }
        food = foodConsump();
        optOne = true;
        break;
      case '2':
        if(optTwo)
        {
          cout<<"Option has already been completed!"<<endl;
          break;
        }
        trans = publicTrans();
        optTwo = true;
        break;
      case '3':
        if(optThree)
        {
          cout<<"Option has already been completed!"<<endl;
          break;
        }
        burnsNum = burnTest();
        optThree = true;
        break;
      case '4':
        //Checking to see if option one was done
        if(!optOne)
        {
          cout<<"Please do option one first"<<endl;
          break;  //Breaking out of switch
        }
        else
        {
          pigs = pigsEaten(food); 
          optFour = true;
        }
        break;
      case '5':
        //Calling compute check fucntion
        compute = computeCheck(optOne, optTwo, optThree, optFour);
        if(compute)
        {
          //Calling the modify values function
          trans = modifyValues(TRANSIT_MULT, TRANSIT_ADD , trans);
          food = modifyValues(WASTE_FOOD_MULT , WASTE_FOOD_ADD ,food);
          cout<<"Your GUILT value is: "
                  <<calcGuilt(food, trans, burnsNum , pigs)
                  <<". Yippie *sarcasm*"<<endl;
        }
        //Breaking out of the loop if compute is false
        else if(!compute)
        {
          break;
        }
        break;
      default:
        cout<<"No such option is avaliable!! Try again";
        break;
    }
  }while(!compute);
  goodBye();
  return 0;
}
