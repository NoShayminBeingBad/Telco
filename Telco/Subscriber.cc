#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string pN){
  phoneNum = pN;
  inCalls = new Array();
  outCalls = new Array();
}

Subscriber::~Subscriber(){
  inCalls->cleanup();
  outCalls->cleanup();
  delete inCalls;
  delete outCalls;
}

void Subscriber::addIncoming(Call* c){
  inCalls->add(c);
}

void Subscriber::addOutgoing(Call* c){
  outCalls->add(c);
}

string Subscriber::getNum(){
  return phoneNum;
}

Array* Subscriber::getInCalls(){
  return inCalls;
}

Array* Subscriber::getOutCalls(){
  return outCalls;
}

void Subscriber::print(){
  Array* temp = new Array(*inCalls);
  temp->add(*outCalls);
  cout<<"Subscriber "<<phoneNum<<endl;
  temp->print();
  delete temp;
}

void Subscriber::printOut(string dest){
  cout<<phoneNum<<endl;
  if (!dest.compare("")){
    outCalls->print();
  }else {
    for (int i = 0; i < outCalls->getSize(); i++){
      if (!(outCalls->get(i)->getDest().compare(dest))){
        outCalls->get(i)->print();
      }
    }
  }
}

void Subscriber::printIn(string src){
  cout<<phoneNum<<endl;
  if (!src.compare("")){
    inCalls->print();
  }else {
    for (int i = 0; i < inCalls->getSize(); i++){
      if (!(inCalls->get(i)->getSrc().compare(src))) {
        inCalls->get(i)->print();
      }
    }
  }
}
