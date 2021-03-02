#ifndef TELCO_H
#define TELCO_H

#include "Subscriber.h"
#include "Call.h"

/*
PURPOSE:    To store information on a tellephone company
NOTES:      computeFreqCaller() prints out the subsriber with the most call
            outgoing, prints subs who calls a specified number if given a paremeter
            computeFreqCalled() prints out hte subscriber with the most incoming
            calls, prints subs who called them the most if given a parementer

*/

class Telco {

  public:
    Telco(string);
    ~Telco();
    void addSub(Subscriber*);
    void addCall(string, string, int, int, int, int, int, int);
    void computeFreqCaller(string);
    void computeFreqCalled(string);
    void print();


  private:
    string name;
    Array* calls;
    Subscriber* subs[MAX_ARR];
    int numSubs;

};


#endif
