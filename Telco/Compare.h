#ifndef COMPARE_H
#define COMPARE_H

#define MAX_ARR 64
using namespace std;

/*
PURPOSE:    An array based class that is used to count how many times a number
            appears
NOTES:      getNum returns the phone number and getCount returns the amount of
            times the number at index i has been inputed into the array

*/

class Compare {

  public:
    Compare();
    void add(string);
    string getNum(int);
    int getCount(int);
    int getSize();
    int getHighest();

  private:
    string num[MAX_ARR];
    int numCount[MAX_ARR];
    int numNum;

};

#endif
