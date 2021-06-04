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
    virtual void updateBottle(float);
    virtual void updateBattery(float);
protected:
    float woda;
    float pojemnosc;
    float wynik;
    float battery_perc;
    float volt;
    float water_percent;
    float wysokosc_max;

};

#endif // SCREEN3VIEW_HPP
