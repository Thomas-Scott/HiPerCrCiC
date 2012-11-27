#ifndef _Global_State_h_
#define _Global_State_h_
#include "EventDispatcher.h"
class GlobalState
{
  public:
    static bool forceRedraw;
    static EventDispatcher * eventDisp;
    static int winWidth;
    static int winHeight;
};

#endif // _Global_State_h_