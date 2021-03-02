#ifndef CALL_H
#define CALL_H

#include "Time.h"
#include "Date.h"

/*
PURPOSE:    To hold information about a call
NOTES:      src  is the source of the call in a string and dest is
            the destination of the call
            duration is total time in minutes
*/

class Call {

  public:
    Call(string, string, int, int, int, int, int, int);
    ~Call();
    bool greaterThan(Call*);
    string getSrc();
    string getDest();
    void print();

  private:
    string src;
    string dest;
    int duration;
    Date *date;
    Time *time;

};


#endif
