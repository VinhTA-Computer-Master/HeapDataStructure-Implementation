/*
  Name: Vinh TA
  Project 1: Heap Data Structure
  File: util.cpp
*/

#pragma once 
#include "util.h"
#include <string>
#include <cstdlib>

using namespace std;

int util::getCap(string input){  // get capacity from input string
  int j=0;
  for(unsigned i=2; i<input.length(); i++){
    input[j] = input[i];
    j++;
  }
  input[j++] = 'a';
  int ret = atoi(input.c_str());
  
  return ret;
}


int util::getKey(string input){  // get key value from input string
  int j=0;
  for(unsigned i=4; i<input.length(); i++){
    input[j] = input[i];
    j++;
  }
  input[j++] = 'a';
  int ret = atoi(input.c_str());

  return ret;
}


int util::getV(string input){  // get decreasing value from input string
  int j=0;
  for(unsigned i=6; i<input.length(); i++){
    input[j] = input[i];
    j++;
  }
  input[j++] = 'a';
  int ret = atoi(input.c_str());

  return ret;
}


int util::getIndex(string input){  // get index from input string
  int j=0;
  for(unsigned i=4; i<input.length(); i++){
    input[j] = input[i];
    j++;
  }
  int ret = atoi(input.c_str());

  return ret;

}
