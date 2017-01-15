/*
  Programmer: Innocent Niyibizi
  File: template.hpp
  Date: 10/17/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Hpp file to hold the sorting template
*/
#ifndef TEMPLATES_H
#define TEMPLATES_H

template<typename T>
void sortArray(T array[], const int size)
{
  T ele;  //Variable to hold the current value of array
  int j;  //Holds the index when sorting
  for(int i=1; i<size; i++)
  {
    ele = array[i]; //Setting ele equal to the current array element
    for(j = i-1; j>=0 && array[j]<ele; j--)
    {
      array[j+1] = array[j];  //Moving value of array element
    }
    array[j+1] = ele;
  }
  return;
}

#endif
