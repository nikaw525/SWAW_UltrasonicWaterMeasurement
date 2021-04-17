#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::updateWaterTxt(int newValue)
{
	Unicode::snprintf(Ilosc_wodyBuffer, 10, "%d", newValue);
	Ilosc_wody.setWildcard(Ilosc_wodyBuffer);
	Ilosc_wody.resizeToCurrentText();
	Ilosc_wody.invalidate();
}


void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
