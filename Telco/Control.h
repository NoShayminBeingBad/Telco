#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"

/*
PURPOSE:    Connects the main data to View so the user can access the data
NOTES:      Given class

*/

class Control
{
  public:
    void launch();

  private:
    void initData(Telco*);
    void initSubscribers(Telco*);
    void initCalls(Telco*);

};

#endif
