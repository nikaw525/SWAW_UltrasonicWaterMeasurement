#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::updateWaterTxt(void)
{
	pojemnosc = presenter->getPojemnosc();
	woda = 30*presenter->getWaga();
	Unicode::snprintf(Ilosc_wodyBuffer, 10, "%d", woda);
	Ilosc_wody.setWildcard(Ilosc_wodyBuffer);
	Ilosc_wody.resizeToCurrentText();
	Ilosc_wody.invalidate();
}

void Screen3View::updateBottle(void)
{
	int percent = 0;
	wynik = (float)woda/pojemnosc;
	if (wynik > 1)
	{
		percent = 100;
	}
	else
	{
		percent = wynik * 100;
	}

	Unicode::snprintf(wynik_txtBuffer, 20, "%d.%d", woda/pojemnosc, woda%pojemnosc);
	wynik_txt.setWildcard(wynik_txtBuffer);
	wynik_txt.resizeToCurrentText();
	wynik_txt.invalidate();

	bottle_1.setValue(percent);

}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
