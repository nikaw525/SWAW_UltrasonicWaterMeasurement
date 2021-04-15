#include <gui/screen2_screen/Screen2View.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

	 //updateTxt(180);
}

void Screen2View::updateTxt(int newValue)
{
	Unicode::snprintf(value_wagaBuffer, 10, "%d", newValue);
	value_waga.setWildcard(value_wagaBuffer);
	value_waga.resizeToCurrentText();
	value_waga.invalidate();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


