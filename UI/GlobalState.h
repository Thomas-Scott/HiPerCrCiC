#ifndef _Global_State_h_
#define _Global_State_h_
#include "EventDispatcher.h"
#include "TabBarController.h"
#include <vector>
#include <pthread.h>
class GlobalState
{
  public:
    static bool forceRedraw;
    static EventDispatcher * eventDisp;
    static TabBarController * tabInterfaceController;
    static int winWidth;
    static int winHeight;
    static vector<pthread_t*> threads;
};

#endif // _Global_State_h_