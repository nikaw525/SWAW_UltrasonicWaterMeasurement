#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}


void Screen3View::toggleSwLed()
{
	if (SwLedOn.isVisible())
	{
		SwLedOn.setVisible(false);
		SwLedOff.setVisible(true);
	} else  {
		SwLedOn.setVisible(true);
		SwLedOff.setVisible(false);
	}
	SwLedOn.invalidate();
	SwLedOff.invalidate();
}
