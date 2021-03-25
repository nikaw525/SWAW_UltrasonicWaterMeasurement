#include <gui/screen4_screen/Screen4View.hpp>

Screen4View::Screen4View()

: lastTempValue(0)


{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}



void Screen4View::setJunctionTempValue(int value)
{
     if (lastTempValue != value)
     {
          lastTempValue = value;
          temperatureBar.setValue(value);
          temperatureBar.invalidate();
     }
}
