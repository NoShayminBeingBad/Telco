#ifndef DATE_H
#define DATE_H

/*
PURPOSE:    To store data of a given data
NOTES:      setDate does error checking

*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
    bool greaterThan(Date*);
    bool equals(Date*);
    void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
};

#endif
