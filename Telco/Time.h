#ifndef TIME_H
#define TIME_H

/*
PURPOSE:    Hold data on a specific time
NOTES:      Given

*/

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
