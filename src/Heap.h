/* 
   Name: Vinh TA
   Project 1: Heap Data Structure
   File: Heap.h
*/

#pragma once

class Element{
 public:
  int key;
  Element(void){
    key = 0;
  }
  Element(int k){
    key = k;
  }
};

class Heap{
 private:
  void MinHeapify(Heap,int);
  
 public:
  int capacity;
  int size;

  Element* H;

  Heap(int);
  Heap Initialize(int);
  void BuildHeap(Heap, Element*, int);
  void Insert(Heap, int, int);
  Element DeleteMin(Heap, int);
  void DecreaseKey(Heap, int, int, int);
  void printHeap(Heap);
};
