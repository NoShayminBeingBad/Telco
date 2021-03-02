#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Array.h"

/*
PURPOSE:    To keep tack of a subscriber and their calls
NOTES:      printOut() prints all calls made by the sub, a specified number
            can be given if only a specific number called wants to be printed
            printIn() is the same as printOut() but prints all incoming calls
            and will output specific caller if given a paremeter

*/

class Subscriber {
  public:
    Subscriber(string);
    ~Subscriber();
    void addIncoming(Call*);
    void addOutgoing(Call*);
    string getNum();
    Array* getInCalls();
    Array* getOutCalls();
    void print();
    void printOut(string = "");
    void printIn(string = "");

  private:
    string phoneNum;
    Array* inCalls;
    Array* outCalls;
};

#endif
