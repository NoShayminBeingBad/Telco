#include <iostream>
using namespace std;
#include <string>

#include "Telco.h"
#include "Compare.h"
#include "Subscriber.h"

Telco::Telco(string n){
  name = n;
  calls = new Array();
  numSubs = 0;
}

Telco::~Telco(){
  for (int i = 0; i < numSubs; i++){
    delete subs[i];
  }
  calls->cleanup();
  delete calls;
}

void Telco::addSub(Subscriber *sub){
  subs[numSubs] = sub;
  numSubs++;
}

void Telco::addCall(string srcNum, string destNum, int year, int month, int day, int hour, int mins, int duration){
  int added = 0;
  for (int i = 0; i < numSubs; i++){
    if (!(subs[i]->getNum().compare(srcNum))){
      subs[i]->addOutgoing(new Call(srcNum, destNum, year, month, day, hour, mins, duration));
      added++;
    }
    if (!(subs[i]->getNum().compare(destNum))){
      subs[i]->addIncoming(new Call(srcNum, destNum, year, month, day, hour, mins, duration));
      added++;
    }
    if (added >= 2){
      break;
    }
  }
  calls->add(new Call(srcNum, destNum, year, month, day, hour, mins, duration));
}

void Telco::computeFreqCaller(string destNum){
  //Adds all calls from calls to Compare to count each number, checks who has the highest occuences and then prints them out
  if (!destNum.compare("all")){
    Compare *comp = new Compare();
    for (int j = 0; j < calls->getSize(); j++){
      comp->add(calls->get(j)->getSrc());
    }
    int highest = comp->getHighest();
    for (int j = 0; j < comp->getSize(); j++){
      if (comp->getCount(j) == highest){
        for (int k = 0; k < numSubs; k++){
          if (!(subs[k]->getNum().compare(comp->getNum(j)))){
            cout<<"==> Most frequent caller to all: ";
            subs[k]->printOut();
            break;
          }
        }
      }
    }
    delete comp;
    return;
  }else {
    for (int i = 0; i < numSubs; i++){
      if (!(subs[i]->getNum().compare(destNum))){
        Array *calls = subs[i]->getInCalls();
        Compare *comp = new Compare();
        for (int j = 0; j < calls->getSize(); j++){
          comp->add(calls->get(j)->getSrc());
        }
        int highest = comp->getHighest();
        for (int j = 0; j < comp->getSize(); j++){
          if (comp->getCount(j) == highest){
            for (int k = 0; k < numSubs; k++){
              if (!(subs[k]->getNum().compare(comp->getNum(j)))){
                cout<<"==> Most frequent caller to "<<destNum<<": ";
                subs[k]->printOut(destNum);
                break;
              }
            }
          }
        }
        delete comp;
        return;
      }
    }
    cout<<"ERROR: Could not find subscriber"<<endl;
  }
}

void Telco::computeFreqCalled(string srcNum){
  //Adds all calls from calls to Compare to count each number, checks who has the highest occuences and then prints them out
  if (!srcNum.compare("all")){
    Compare *comp = new Compare();
    for (int j = 0; j < calls->getSize(); j++){
      comp->add(calls->get(j)->getDest());
    }
    int highest = comp->getHighest();
    for (int j = 0; j < comp->getSize(); j++){
      if (comp->getCount(j) == highest){
        for (int k = 0; k < numSubs; k++){
          if (!(subs[k]->getNum().compare(comp->getNum(j)))){
            cout<<"==> Most frequent called to all: ";
            subs[k]->printIn();
            break;
          }
        }
      }
    }
    delete comp;
    return;
  }else {
    for (int i = 0; i < numSubs; i++){
      if (!(subs[i]->getNum().compare(srcNum))){
        Array *calls = subs[i]->getOutCalls();
        Compare *comp = new Compare();
        for (int j = 0; j < calls->getSize(); j++){
          comp->add(calls->get(j)->getDest());
        }
        int highest = comp->getHighest();
        for (int j = 0; j < comp->getSize(); j++){
          if (comp->getCount(j) == highest){
            for (int k = 0; k < numSubs; k++){
              if (!(subs[k]->getNum().compare(comp->getNum(j)))){
                cout<<"==> Most frequent called to "<<srcNum<<": ";
                subs[k]->printIn(srcNum);
                break;
              }
            }
          }
        }
        delete comp;
        return;
      }
    }
  }
  cout<<"ERROR: Could not find subscriber"<<endl;
}

void Telco::print(){
  cout<<endl<<name<<endl<<endl;
  for (int i = 0; i < numSubs; i++){
    subs[i]->print();
  }
}
