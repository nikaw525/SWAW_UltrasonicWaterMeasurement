#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::OkButtonClicked()
{
	view.updateWaterTxt();
	view.updateBottle(10);
	view.updateBattery(7.99);
}

void Screen3Presenter::setNewBatteryValue(unsigned int val)
{
	//view.updateBattery(val);
}

void Screen3Presenter::deactivate()
{

}

