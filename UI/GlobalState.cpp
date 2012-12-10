// Michael Taufen 2012
#include "GlobalState.h"

bool GlobalState::forceRedraw = false;
EventDispatcher * GlobalState::eventDisp = 0;
TabBarController * GlobalState::tabInterfaceController = 0;
JobManager * GlobalState::jobManager = new JobManager();
int GlobalState::winWidth = 1;
int GlobalState::winHeight = 1;