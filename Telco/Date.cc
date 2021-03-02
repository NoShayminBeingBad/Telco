#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date(){
  
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

void Date::print(){
  cout<<year<<"-"<<setw(2)<<setfill('0')<<month<<"-"<<setw(2)<<day;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

bool Date::greaterThan(Date *d){
  if (year > d->year){
    return true;
  }else if (year < d->year){
    return false;
  }
  if (month > d->month){
    return true;
  }else if (month < d->month){
    return false;
  }
  if (day > d->day){
    return true;
  }
  return false;
}

bool Date::equals(Date *d){
  if (d->year == year){
    if (d-> month == month){
      if (d->day == day){
        return true;
      }
    }
  }
  return false;
}
