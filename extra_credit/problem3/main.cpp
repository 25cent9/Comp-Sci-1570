/*
  Programmer: Innocent Niyibizi
  File: problem.cpp
  Date: 12/8/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Program to find the largest product of adjacent numbers
*/
#include<iostream>
#include<string>
using namespace std;
const short NUMS = 13;  //Constant to hold the number of adjacent values to find

int main()
{

  short index = 0;  //Short to hold the index to start counting

  //String to hold the 1000 digit number
  //Didn't indent cause stupid character limit
string s="73167176531330624919225119674426574742355349194934969835203127745063"
"262395783180169848018694788518438586156078911294949545950173795833195285320880"
"551112540698747158523863050715693290963295227443043557668966489504452445231617"
"318564030987111217223831136222989342338030813533627661428280644448664523874930"
"358907296290491560440772390713810515859307960866701724271218839987979087922749"
"219016997208880937766572733300105336788122023542180975125454059475224352584907"
"711670556013604839586446706324415722155397536978179778461740649551492908625693"
"219784686224828397224137565705605749026140797296865241453510047482166370484403"
"199890008895243450658541227588666881164271714799244429282308634656748139191231"
"628245861786645835912456652947654568284891288314260769004224219022671055626321"
"111109370544217506941658960408071984038509624554443629812309878799272442849091"
"888458015616609791913387549920052406368991256071760605886116467109405077541002"
"25698315520005593572972571636269561882670428252483600823257530420752963450";

  //unsigned because 9^13 is higher than the max a signed int can store
  //Integer to hold the max number produced
  unsigned int max = 0;

  //Loop to run through the entire digit string
  for (unsigned int i = 0; i < s.length()-NUMS; i++)
  {
    //unsigned because 9^13 is higher than the max a signed int can store
    //Variable to hold the product of the
    unsigned int product = 1;

    //Loop for the number of max numbers
    for (int j = 0; j < NUMS; j++)
    {
      //Multiplying the product by itself and the value of the current index
      //plus the current number in numbers
      //Subtracting 48 so that it matches the ASCII integer value
      //character value of 0 is 48
      product *= s[i + j] - 48;
    }
    //If product greater than max than index is equal to the current index
    //The value of max is set equal to the value of product
    if (product > max)
    {
      index = i;
      max = product;
    }
  }
  //Outputting the results
  cout << "The max number is " << max << " when " << s.substr(index, NUMS)
       << " are multiplied together at index " << index << endl;
  return 0;
}
