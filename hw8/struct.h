/*
  Programmer: Innocent Niyibizi
  File: struct.h
  Date: 11/1/16
  Class: 1570 - H
  Instuctor: Jarus
  Description: Header file for function protoypes
*/
#ifndef STRUCT_H
#define STRUCT_H
#include "constants.h"
//Struct for the candidate
struct candidate
{
    char sentences[MAX_SENT_LENGTH];
    char interjections[MAX_SENT_LENGTH];
    char answer[MAX_SENT_LENGTH];
    long score;
    char phrases[MAX_PHRASE][MAX_SENT_LENGTH];
    char question[MAX_SENT_LENGTH];
    char prefix[MAX_SENT_LENGTH];
};

#endif
