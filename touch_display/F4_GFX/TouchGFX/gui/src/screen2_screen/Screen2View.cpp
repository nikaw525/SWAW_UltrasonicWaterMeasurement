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

int Screen2View::find(touchgfx::Unicode::UnicodeChar buffer[], int size, touchgfx::Unicode::UnicodeChar object)
{
	int idx;
	for(idx = 0; idx < size; idx++)
	{
		if(object == buffer[idx]){
			return idx;
		}
	}
	return -1;
}

void Screen2View::updateTxt(int newValue)
{
	int idx;

	if(newValue >= 0)
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
			presenter->wysokosc_value = (presenter->wysokosc_value * 10) + newValue;
			Unicode::snprintf(value_wysokoscBuffer, 10, "%d", presenter->wysokosc_value);
			value_wysokosc.setWildcard(value_wysokoscBuffer);
			value_wysokosc.resizeToCurrentText();
			value_wysokosc.invalidate();
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

	else
	{
		if(1 == presenter->data_destination[0])
		{
			idx = find(value_wagaBuffer, 10, '\0');

			presenter->waga_value = (presenter->waga_value / 10 );
			value_wagaBuffer[idx - 1] = ' ';
			value_wagaBuffer[idx] = ' ';

			value_waga.setWildcard(value_wagaBuffer);
			value_waga.resizeToCurrentText();
			value_waga.invalidate();

			value_wagaBuffer[idx - 1] = '\0';
			value_wagaBuffer[idx] = '\0';
		}

		if(1 == presenter->data_destination[1])
		{
			idx = find(value_wysokoscBuffer, 10, '\0');

			presenter->wysokosc_value = (presenter->wysokosc_value / 10 );
			value_wysokoscBuffer[idx - 1] = ' ';
			value_wysokoscBuffer[idx] = ' ';

			value_wysokosc.setWildcard(value_wysokoscBuffer);
			value_wysokosc.resizeToCurrentText();
			value_wysokosc.invalidate();

			value_wysokoscBuffer[idx - 1] = '\0';
			value_wysokoscBuffer[idx] = '\0';
		}

		if(1 == presenter->data_destination[2])
		{
			idx = find(value_pojemnoscBuffer, 10, '\0');

			presenter->pojemnosc_value = (presenter->pojemnosc_value / 10 );
			value_pojemnoscBuffer[idx - 1] = ' ';
			value_pojemnoscBuffer[idx] = ' ';

			value_pojemnosc.setWildcard(value_pojemnoscBuffer);
			value_pojemnosc.resizeToCurrentText();
			value_pojemnosc.invalidate();

			value_pojemnoscBuffer[idx - 1] = '\0';
			value_pojemnoscBuffer[idx] = '\0';
		}
	}

}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


