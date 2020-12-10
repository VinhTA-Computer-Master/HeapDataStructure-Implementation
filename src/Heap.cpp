/* 
   Name: Vinh TA
   Project 1: Heap Data Structure
   File: Heap.cpp
*/

#pragma once
#include "Heap.h"
#include <iostream>

using namespace std;

int parent(int i){
  return (i/2);
}

int left(int i){
  return (2*i);
}

int right(int i){
  return (2*i+1);
}

void Heap::MinHeapify(Heap heap,int i){
  int l = left(i);
  int r = right(i); 
  int smallest=0;
  if(l<=Heap::size && heap.H[l].key < heap.H[i].key)
    smallest = l;
  else
    smallest = i;
  if(r<=Heap::size && heap.H[r].key < heap.H[smallest].key)
    smallest = r;
  if(smallest != i){
    int temp = heap.H[i].key;
    heap.H[i].key = heap.H[smallest].key;
    heap.H[smallest].key = temp;
    Heap::MinHeapify(heap,smallest);
  }
}

Heap::Heap(int n){
  Heap::size = 0;
  Heap::capacity = n;
  Heap::H = new Element[n];
}

Heap Heap::Initialize(int n){
  Heap ret(n);
  return ret;
}

void Heap::BuildHeap(Heap heap, Element* A, int n){
  if(n > Heap::capacity){
    cout << "Sorry!!! It cannot be done. Please increase the capacity of heap first." << endl;
    return;
  }

  for(int i=1; i<=n; i++){
    Heap::size++;
    heap.H[i].key = A[i].key;
  }

  for(int i=n/2; i>0; i--){
    Heap::MinHeapify(heap,i);
  }
  return;
}


void Heap::Insert(Heap heap, int flag, int k){
  if(Heap::size >= Heap::capacity){
    Heap::capacity = Heap::capacity*2;
  }

  if(flag==2)
    Heap::printHeap(heap);
  

  Heap::size++;
  heap.H[size].key = k;
  int i=Heap::size;
  while(i>1 && heap.H[parent(i)].key > heap.H[i].key){
    int temp = heap.H[parent(i)].key;
    heap.H[parent(i)].key = heap.H[i].key;
    heap.H[i].key = temp;
    i=parent(i);
  }

  if(flag==2)
    Heap::printHeap(heap);

  return;
}

Element Heap::DeleteMin(Heap heap, int flag){
  if(heap.size <1){
    cout << "There are no elements in heap to delete." << endl;
    Element ret(999999);   // 999999 as personal reference for null pointer
    return ret;
  }

  if(flag==2)
    Heap::printHeap(heap);
  

  Element min = heap.H[1];
  heap.H[1] = heap.H[heap.size];
  Heap::size--;
  MinHeapify(heap,1);

  if(flag==2)
    Heap::printHeap(heap);
  
  return min;
}

void Heap::DecreaseKey(Heap heap, int flag, int index, int value){
  if(index > heap.size){
    cout << "There are only " << heap.size << " elements in the heap. Hence this operation cannot be completed." << endl;
    return;
  }

  if(value >= heap.H[index].key){
    cout << "Decreasing value cannot be larger than current value." << endl;
    return;
  }

  if(flag ==2)
    Heap::printHeap(heap);
  

  heap.H[index].key = value;
  while(index>1 && heap.H[parent(index)].key > heap.H[index].key){
    int temp = heap.H[parent(index)].key;
    heap.H[parent(index)].key = heap.H[index].key;
    heap.H[index].key = temp;
    index=parent(index);
  }

  if(flag ==2)
    Heap::printHeap(heap);
  
  return;
}

void Heap::printHeap(Heap heap){
  cout << "The capacity is " << Heap::capacity << ".\nSize is " << Heap::size << endl;
  for(int i=1; i<=Heap::size; i++){
    cout << heap.H[i].key << endl;
  }
  return;
}
