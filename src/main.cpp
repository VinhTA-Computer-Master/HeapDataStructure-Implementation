/*
  Name: Vinh TA
  Project 1: Heap Data Structure
  File: main.cpp
*/

#include "Heap.h"
#include "util.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main(int argv, char** argc){

  ifstream filein("HEAPinput.txt");  // input from file HEAPinput.txt
  if(filein.fail()){
    cout << "HEAPinput.txt not found!" << endl;
    return 0;
  }

  char c;  // letter command variable
  string input;  // input as string type from keyboard
  Heap h2 = h2.Initialize(0);  // heap data structure object
  Element* A;   // array inputted from HEAPinput.txt 
  int ini = 0;  // variable for determining whether initialized or not
  util util;  // instance of util class for used methods

    do{
    cout << "Input command: " << endl;
    getline(cin, input);
    c = tolower(input[0]);
    cout << "Command: " << input << endl;
    if(c == 'c'){  // initialization command
      int capacity = util.getCap(input);  // get capacity from util class
      h2 = h2.Initialize(capacity);
      ini = 1; // initialized
    } else if(c == 'r'){  // read from HEAPinput.txt command
      if(!ini){
	cout << "Sorry!!! It cannot be done. Please initialize the heap first" << endl;
	continue;
      }
      ifstream filein("HEAPinput.txt");  // reset reading
      int size=0;
      filein >> size;
      A = new Element[size];  // first number as size
      int fail =0;
      for(int i=1; i<=size; i++){
	filein >> A[i].key;
	if(filein.fail())
	  fail =1;
      }
      if(fail)
	cout << "Sorry!!! It cannot be done. The number of elements in file is less than as specified in the beginning of file" << endl;
      else
	h2.BuildHeap(h2,A,size);  // build heap from array A
    } else if(c == 'w'){  // write to screen command
      if(!ini){
	cout << "Sorry!!! It cannot be done. Please initialize the heap first" << endl;
	continue;
      }
      h2.printHeap(h2);

    } else if(c == 'i'){  // insert command

      if(!ini){
	cout << "Sorry!!! It cannot be done. Please initialize the heap first" << endl;
	continue;
      }

      int key = util.getKey(input);  // get key value from input string
      input[0] = input[2];
      int flag = atoi(input.c_str());  // get flag from input string

      if(flag == 1 || flag == 2){
	h2.Insert(h2, flag, key);
      } else{
	cout << "This is not a valid flag value. This operation cannot be completed." << endl;
	continue;
      }

    } else if(c == 'd'){  // delete minimum command
      
      if(!ini){
	cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it." << endl;
	continue;
      }

      input[0] = input[2];
      int flag = atoi(input.c_str());  // get flag from input string
      
      if(flag == 1 || flag == 2){
	Element del = h2.DeleteMin(h2, flag);
	if(del.key == 999999)
	  continue;
	cout << del.key << endl;
      } else{
	cout << "This is not a valid flag value. This operation cannot be completed." << endl;
	continue;
      }

    } else if(c == 'k'){  // decrease key command

      if(!ini){
	cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it." << endl;
	continue;
      }

      int v = util.getV(input);  // get decreasing value from util class
      int index = util.getIndex(input);  // get index from util class
      input[0] = input[2];
      int flag = atoi(input.c_str());  // extract flag from input string
      
      if(flag == 1 || flag == 2){
	h2.DecreaseKey(h2, flag, index, v);
      } else{
	cout << "This is not a valid flag value. This operation cannot be completed." << endl;
	continue;
      }
      
    } else if(c != 's'){
      cout << "Invalid inputs" << endl;
    }
  }while(c != 's');
    cout << "Program terminated" << endl;
} // end of program
