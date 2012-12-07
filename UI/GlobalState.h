#ifndef _Global_State_h_
#define _Global_State_h_
#include "EventDispatcher.h"
#include "TabBarController.h"
#include "../core/JobManager.h"
#include <vector>
class GlobalState
{
public:
  static bool forceRedraw;
  static EventDispatcher * eventDisp;
  static TabBarController * tabInterfaceController;
  static JobManager * jobManager;
  static int winWidth;
  static int winHeight;
};

#endif // _Global_State_h_