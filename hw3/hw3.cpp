/*
  Programmer: Innocent Niyibizi
  File: hw3.cpp
  Date: 9/13/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Gather user input to generate a jazz tune
*/

#include <iostream>
using namespace std;
const short MAX_VAL = 100; //The max value user can enter
const short MIN_VAL = 10;  //The lowest nnumber the user can enter
const string USER = "Lisa"; //The current user of the program, default is lisa
const int DIVISOR = 7;     //Value to be used with the mod operator
const int EVEN_DIVISOR = 2; //Value to be used with even mod operator

//Consts for notes
const string NOTE_ONE = "wah\n"; //Value of the A note
const string NOTE_TWO = "bleep\n"; //Value of the Bb note
const string NOTE_THREE = "do-wah\n"; //Value of the C++ note
const string NOTE_FOUR = "ding\n"; //Value of the D- note
const string NOTE_FIVE = "honk\n"; //Value of the E# note
const string NOTE_SIX = "wapp\n";  //Value of the Fb note
const string NOTE_SEVEN = "DOH!\n"; //Value of the H note

//Consts for note places 
//Notes places start with the value of zero and increase by one
const int FIRST = 0;
const int SECOND =1;
const int THIRD = 2;
const int FOURTH = 3;
const int FIFTH = 4;
const int SIXTH = 5;
const int SEVENTH = 6;
 
int main()
{
  //Declaring variables
  string tune = ""; //String that will hold the value of the tune
  int elChupCount = 0; //Int to hold count for El Chupacabra
  int buckToothCount = 0; //Int to hold count for Buck Tooth Slug
  int freakyFishCount = 0; //Int to hold count for freaky fish
  int threeLegSnakeCount = 0; //Int to hold count for 3-legged snake
  int trashBearCount = 0; //Int to hold count for trash bear
  int hansCount = 0; //Int to hold count for Hans
  int cletusCount = 0; //Int to hold count for Cletus
  int inspirationNum = 0;
  int noteNum = 0;
  bool is_even = 0;
  //Greeting
  cout<<"Hello "<<USER<<"! Welcome to the Jazz Machine!"<<endl;
  
  do  //Loop to validate user input
  {
    cout<<"Please enter an inspiration nunmber from 10-100: ";
    cin>>inspirationNum;
    
    //If statement to display the correct error message
    if(inspirationNum < MIN_VAL)
    {
      cout<<"Sorry, "<<inspirationNum<<" is too Ralph Wiggumian!"<<endl;
    }
    else if(inspirationNum > MAX_VAL)
    {
      cout<<"Sorry, "<<inspirationNum<<" is too John Coltranian!"<<endl;
    }
  }while((inspirationNum < MIN_VAL) || (inspirationNum > MAX_VAL));
  
  //Loop to run as long as the inspirtation number is not one
  while(inspirationNum != 1)
  {
    //Figuring out what the note is
    noteNum = inspirationNum % DIVISOR;
    //Checking to see if inspiration num is even
    is_even = inspirationNum % EVEN_DIVISOR;
    
    //If statements to check which note will be outputted
    //noteNum is found by finding the remainder of inpirtation number and 7  
    //For each condition, the appropriate sound is added to tune
    //Once the sound is added to the tune the animal count is incremented by 1
    if(noteNum== FIRST)
    {
      tune += NOTE_ONE;
      elChupCount++;
    }
    else if(noteNum == SECOND)
    {
      tune += NOTE_TWO;
      buckToothCount++;
    }
    else if(noteNum == THIRD)
    {
      tune += NOTE_THREE;
      freakyFishCount++;
    }  
    else if(noteNum == FOURTH)
    {
      tune += NOTE_FOUR;
      threeLegSnakeCount++;
    }
    else if(noteNum == FIFTH)
    {
      tune += NOTE_FIVE;
      trashBearCount++;
    }
    else if(noteNum == SIXTH)
    {
      tune += NOTE_SIX;
      hansCount++;
    }
    else if(noteNum == SEVENTH)
    {
      tune += NOTE_SEVEN;
      cletusCount++;
    }
    
    //Checking to see if current inpiration numbe is even
    //If it is even then it will be divided by 2
    //If it is not then the value will be multiplied by three and added one
    if(is_even == 0)
    {
      inspirationNum /= EVEN_DIVISOR;
    }
    else
    {
      inspirationNum = (3*inspirationNum+1);
    }
    
  }
  
  //Displaying the tune
  cout<<"The tune is: \n";
  cout<<tune<<endl;
  
  //Displaying the amount of snacks each animal gets
  cout<<"Snax:\n";
  cout<<"El Chupacabra: "<<elChupCount<<" snax(s)"<<endl;
  cout<<"BuckToothedSlug: "<<buckToothCount<<" snax(s)"<<endl;
  cout<<"Freaky Fish: "<<freakyFishCount<<" snax(s)"<<endl;
  cout<<"3-Legged Snakes: "<<threeLegSnakeCount<<" snax(s)"<<endl;
  cout<<"Trash Bears: "<<trashBearCount<<" snax(s)"<<endl;
  cout<<"Hans: "<<hansCount<<" snax(s)"<<endl;
  cout<<"Cletus: "<<cletusCount<<" snax(s)"<<endl;
  cout<<"I hope you enjoyed the Jazz!! Have a great day!\n";
    
  return 0;
}
