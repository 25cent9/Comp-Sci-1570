/*
  Programmer: Innocent Niyibizi
  Filename: hw2.cpp
  Date: 9/8/16
  Purpose: Create program to gather input and make calculations
*/
#include <iostream>
using namespace std;
const int LIFE = 11;
const float GAL_WATER = 7.48; 
const int GAL_FOOD = 2;
const float HEIGHT_FACTOR = 0.67;
const float WIDTH_FACTOR = 0.25;
const int GAL_FISH = 25;
int main()
{
 //Declaring variables
 int length = 0, numFish = 0, width = 0, height = 0;
 bool freakyFish = 0;
 float tankVolume = 0.0, waterVolume = 0.0, waste = 0.0;
 cout<<"Welcome to the Fish Tank Computer!"<<endl; //Greeting

 //Gathering input from the user
 cout<<"Please enter the following info: \n";
 cout<<"Length of tank(in feet): ";
 cin>>length;
 cout<<"Any freaky fish(1 - yes, 0 - no): ";
 cin>>freakyFish;

 //Calculations
 width = length*WIDTH_FACTOR;
 height = length*HEIGHT_FACTOR;

 tankVolume = width*length*height*GAL_WATER;
 waterVolume = tankVolume - (GAL_FOOD*freakyFish);

 numFish = static_cast<int>(waterVolume/GAL_FISH);
 waste = LIFE;
 waste /= height*12;

 //Displaying the output
 cout<<"The following are your tank dimensions:\n "<<endl;
 cout<<"Length: "<<length<<" ft"<<endl;
 cout<<"Width: "<<width<<" ft"<<endl;
 cout<<"Height: "<<height<<" ft"<<endl;
 cout<<"Tank voloume: "<<tankVolume<<" gals"<<endl;
 cout<<"Water volume: "<<waterVolume<<" gals"<<endl;
 cout<<"Waste: "<<waste<<" rads"<<endl;

 //Displaying the number of fish and salutaion
 cout<<"Your tank will be able to hold "<<numFish<<" fishies...";
 cout<<"Have a nice day!\n"<<endl;

 return 0;
}
