#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"


/*
PURPOSE:    Keep track of calls in a tellephone company
USUAGE:     A menu is loaded when program is started, enter the numbers of
            what option you want to access the data
AUTHOR:     Raymond Ma
REVISIONS:
*/

int main(){
  cout<<unitbuf;

  Control* control = new Control();
  control->launch();

  delete control;

  return 0;
}
