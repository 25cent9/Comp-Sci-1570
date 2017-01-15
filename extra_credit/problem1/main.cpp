/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 12/7/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to find the sum of all even Fibonacci numbers
*/

#include <iostream>
using namespace std;
const int MAX = 4000000;
/*
  Description: Function to find the the value of two numbers added together
  Pre:         num1 += num2
  Post:        Both numbers passed through are modified and the sum is returned
*/
int fibon(int&, int&);
int main()
{
  //Declaring variables
  int num1 = 0; //First number
  int num2 = 1; //Second number
  int tempNum = 0;  //Temporary Fibonacci number
  int sum = 0; //Number to hold the sum of the Fibonacci numbers

  //Loop to run until the value of the Fibonacci number is greater
  //than 4 million
  do
  {
    tempNum=fibon(num1, num2);  //Setting tempNum equal to the value returned
    //Checking to see if tempNum is a multiple of 2 and is less than or equal
    //to the max number
    if(tempNum%2==0 && tempNum<=MAX)
    {
      cout<<"Temp number: "<<tempNum<<endl;
      sum+=tempNum; //Incrementing sum with the value of the temp number
    }
  }while(tempNum<=MAX);
  //Printing the sum of the Fibonacci numbers
  cout<<"Sum: "<<sum<<endl;
  cout<<endl;
  return 0;
}

//Fibonacci Function
int fibon(int& num1, int& num2)
{
  int newNum = 0; //Int to hold value of summed numbers
  newNum = num1+num2; //Setting new num equal to firt and second num
  num1=num2;  //Setting first nmber equal to second numer
  num2=newNum; //Setting second number equal to new number
  return newNum;  //Returning new number
}
