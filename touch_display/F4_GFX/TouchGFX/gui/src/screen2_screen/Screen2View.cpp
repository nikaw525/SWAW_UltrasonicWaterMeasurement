#include <gui/screen2_screen/Screen2View.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::updateTxt(int newValue)
{

	if(1 == presenter->data_destination[0])
	{
		presenter->waga_value = (presenter->waga_value * 10) + newValue;
		Unicode::snprintf(value_wagaBuffer, 10, "%d", presenter->waga_value);
		value_waga.setWildcard(value_wagaBuffer);
		value_waga.resizeToCurrentText();
		value_waga.invalidate();
	}

	if(1 == presenter->data_destination[1])
	{
		presenter->wzrost_value = (presenter->wzrost_value * 10) + newValue;
		Unicode::snprintf(value_wzrostBuffer, 10, "%d", presenter->wzrost_value);
		value_wzrost.setWildcard(value_wzrostBuffer);
		value_wzrost.resizeToCurrentText();
		value_wzrost.invalidate();
	}

	if(1 == presenter->data_destination[2])
	{
		presenter->pojemnosc_value = (presenter->pojemnosc_value * 10) + newValue;
		Unicode::snprintf(value_pojemnoscBuffer, 10, "%d", presenter->pojemnosc_value);
		value_pojemnosc.setWildcard(value_pojemnoscBuffer);
		value_pojemnosc.resizeToCurrentText();
		value_pojemnosc.invalidate();
	}
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


