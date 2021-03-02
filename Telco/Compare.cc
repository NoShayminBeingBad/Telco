#include <iostream>
using namespace std;

#include "Compare.h"

Compare::Compare(){
  numNum = 0;
}

void Compare::add(string add){
  for (int i = 0; i < numNum; i++){
    if (!num[i].compare(add)){
      numCount[i]++;
      return;
    }
  }
  if (numNum <= MAX_ARR){
    numCount[numNum] = 0;
    num[numNum] = add;
    numNum++;
  }
}

string Compare::getNum(int i){
  return num[i];
}

int Compare::getCount(int i ){
  return numCount[i];
}

int Compare::getSize(){
  return numNum;
}

int Compare::getHighest(){
  int high = 0;
  for (int i = 0; i < numNum; i++){
    high = numCount[i] > high ? numCount[i] : high;
  }
  return high;
}
