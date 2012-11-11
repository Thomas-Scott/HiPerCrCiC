#ifndef _ViewController_h_
#define _ViewController_h_

#include <string>
#include "View.h"
#include "CGClasses.h"
using namespace std;

class ViewController
{
private: // private variables

// Each ViewController gets a master view, the master view's bounds are equal to the screen in most cases, or will be set appropriately when required
View *_masterView;

public: // public variables

private: // private methods

public: // public methods
// Constructors and Destructor
ViewController();
ViewController(ViewController const& viewC);
virtual ~ViewController();
// Getters and Setters
View * getMasterView() const { return _masterView; } // returns a pointer to the master view of this view controller
void setMasterView(View const& view);

// Render Code
virtual void loadView(); //initializes all of the stuff in the masterView
virtual void update(); // updates any data and then calls the draw function
};
#endif // _ViewController_h_

