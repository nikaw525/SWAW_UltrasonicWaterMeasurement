#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateWaterTxt(void);
    virtual void updateBottle(void);
    virtual void updateBattery(void);
protected:
    int woda;
    int pojemnosc;
    float wynik;
    float perc;
    float volt;
    int percent;

};

#endif // SCREEN3VIEW_HPP
