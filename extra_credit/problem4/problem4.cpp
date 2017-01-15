/*
  Programmer: Innocent Niyibizi
  File: main.cpp
  Date: 12/7/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to find the sum of all even Fibonacci numbers
*/
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

/*
  Description: Function to convert integer to string
  Pre:         None
  Post:        A string of the number passed through is returned
*/
string stringify(int num);

/*
  Description: Function to reverse string passed through
  Pre:         None
  Post:        A reversed version of the string passed through is returned
*/
string rev(string num);

int main()
{
	//Declaring varables
	short palin=100, drome, endp, endd;
	int palindrome, largest;

	do //Loop to run through while palin is less than 999
	{
		drome=100;	//Resetting drome back to 100 for each run through
		do //Loop to run through while drome is less than 999
		{
			palindrome=(palin*drome);	//Setting palindrome to palin*drome
			//If palindrome is equal to the reversed version of palindrome
			//largest is set to the value of palindrome
			//Setting endp and endd equal to the approriate values
			if(stringify(palindrome)==rev(stringify(palindrome))&&palindrome>largest)
			{
			  largest=palindrome;
			  endp=palin;
			  endd=drome;
		    }
		    drome++;	//Incrementing drome
		}while(drome<999);
		palin++;	//Incrementing palin
	}while(palin<999);
	//Outputting the numbers that multiply to the palindrome
	cout<<endp<<" * "<<endd<<" = "<<largest<<endl;
	return 0;
}

//Function to convert an integer to a string
string stringify(int num)
{
	stringstream out;	//Creating stringstram called out
	out<<num;	//Placing the nunmber into out
	return out.str();	//Returning the string version of the number
}

//Function to reverse the string passed
string rev(string num)
{
	char temp[7]={};	//Character array to hold the value of the string
	strcpy(temp,num.c_str());	//Copying the number into the character array
	string out="";	//Creating new string to hold the reverse value of the number
	int i=strlen(temp)-1;	//Setting the counter equal to the index of the last character
	//Loop that will run until the last character
	while(i>=0)
	{
		out+=temp[i];	//Adding the current value of the temp array to the output string
		i--;	//Decrementing
	}
	//cout<<num<<" "<<out<<endl;;
	return out;	//Returning out
}
