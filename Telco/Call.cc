#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Call.h"

Call::Call(string source, string des, int year, int month, int day, int starth, int startm, int durr){
  src = source;
  dest = des;
  duration = durr;
  date = new Date(day, month, year);
  time = new Time(starth, startm);
}

Call::~Call(){
  delete date;
  delete time;
}

bool Call::greaterThan(Call *c){
  if (!date->greaterThan(c->date)){
    if (date->equals(c->date)){
      return time->greaterThan(c->time);
    }else {
      return false;
    }
  }
  return true;
}

string Call::getSrc(){
  return src;
}

string Call::getDest(){
  return dest;
}

void Call::print(){
  date->print();
  cout<<" ";
  time->print();
  cout<<", " << setfill(' ')<<setw(3)<<duration<<" mins: From: "<<src<<" To: "<<dest<<endl;
}
