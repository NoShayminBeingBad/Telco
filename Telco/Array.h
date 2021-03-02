#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR 64

#include "Call.h"

/*
PURPOSE:    To store an array of calls
NOTES:      the max amount of any array is 64
            Another constructor can be used if given an already existing Array,
            it will copy the same Call instances to its own array
            cleanup() is used in place of a dtor
*/

class Array
{
  public:
    Array();
    Array(Array&);
    bool add(Call*);
    bool add(Array&);
    int getSize();
    Call* get(int);
    void print();
    void cleanup();

  private:
    Call* elements[MAX_ARR];
    int   size;
};

#endif
