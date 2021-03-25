#include <gui/screen5_screen/Screen5View.hpp>

Screen5View::Screen5View()
{

}

void Screen5View::setupScreen()
{
    Screen5ViewBase::setupScreen();
}

void Screen5View::tearDownScreen()
{
    Screen5ViewBase::tearDownScreen();
}


void Screen5View::handleTickEvent()
{
    tickCounter++;
    if (tickCounter % 60 == 0)
    {
        if (++digitalSeconds >= 60)
        {
            digitalSeconds = 0;
            if (++digitalMinutes >= 60)
            {
                digitalMinutes = 0;
                if (++digitalHours >= 24)
                {
                    digitalHours = 0;
                }
            }
        }
        if (++analogSeconds >= 60)
        {
            analogSeconds = 0;
            if (++analogMinutes >= 60)
            {
                analogMinutes = 0;
                if (++analogHours >= 24)
                {
                    analogHours = 0;
                }
            }
        }
        digitalClock.setTime24Hour(digitalHours, digitalMinutes, digitalSeconds);
        analogClock.setTime24Hour(analogHours, analogMinutes, analogSeconds);
    }
}
