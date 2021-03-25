#ifndef SCREEN5VIEW_HPP
#define SCREEN5VIEW_HPP

#include <gui_generated/screen5_screen/Screen5ViewBase.hpp>
#include <gui/screen5_screen/Screen5Presenter.hpp>

class Screen5View : public Screen5ViewBase
{
public:
    Screen5View();
    virtual ~Screen5View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

protected:

    int tickCounter;
    int analogHours;
    int analogMinutes;
    int analogSeconds;
    int digitalHours;
    int digitalMinutes;
    int digitalSeconds;


};

#endif // SCREEN5VIEW_HPP
