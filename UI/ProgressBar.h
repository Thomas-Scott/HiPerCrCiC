// Michael Taufen 2012
#ifndef _Progress_Bar_h_
#define _Progress_Bar_h_

#include "View.h"

class ProgressBar : public View
{
  private:
    float _percentComplete; // the percentage completion, as a decimal value
    CGColor * _foregroundColor; // foreground color
  public:
    ProgressBar(CGRect const& rect, CGColor const& foreground, CGColor const& background);
    virtual ~ProgressBar();

    float getPercentComplete(){return _percentComplete;}
    void setPercentComplete(float val){_percentComplete = val;}

    virtual void draw();
};

#endif //_Progress_Bar_h_