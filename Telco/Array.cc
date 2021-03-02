#include <iostream>
using namespace std;

#include "Array.h"

Array::Array()
{
  size = 0;
}

Array::Array(Array& a){
  size = 0;
  for (int i = 0; i < a.size; i++){
    add(a.elements[i]);
  }
}

void Array::cleanup()
{
  for (int i=0; i<size; ++i)
    delete elements[i];
}

bool Array::add(Call* c)
{
  if (size >= MAX_ARR)
    return false;

  int i;
  for (i = 0; i < size; i++){
    if (!c->greaterThan(elements[i])){
      break;
    }
  }

  for (int j = size; j > i; j--){
    elements[j] = elements[j-1];
  }

  elements[i] = c;

  size++;

  return true;
}

bool Array::add(Array& arr){

  for (int i = 0; i < arr.size; i++){
    if (size == MAX_ARR){
      return false;
    }
    add(arr.elements[i]);
  }

  return true;
}

int Array::getSize(){
  return size;
}

Call* Array::get(int i){
  if (i <= size){
    return elements[i];
  }
  return NULL;
}

void Array::print()
{
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}
