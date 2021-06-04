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
	Unicode::snprintfFloat(Ilosc_wodyBuffer, 10, "%.2f", woda);
	Ilosc_wody.setWildcard(Ilosc_wodyBuffer);
	Ilosc_wody.resizeToCurrentText();
	Ilosc_wody.invalidate();
}

void Screen3View::updateBottle(float wysokosc_odczyt)
{
	wysokosc_max = presenter->getWysokosc();
	water_percent = ((wysokosc_max - wysokosc_odczyt)/wysokosc_max) * 100;
	wynik = ((wysokosc_max - wysokosc_odczyt)/wysokosc_max)*pojemnosc;


	Unicode::snprintfFloat(wynik_mlBuffer, 20, "%.2f", wynik);
	wynik_ml.setWildcard(wynik_mlBuffer);
	wynik_ml.resizeToCurrentText();
	wynik_ml.invalidate();

	Unicode::snprintfFloat(wynik_percBuffer, 20, "%.2f", water_percent);
	wynik_perc.setWildcard(wynik_percBuffer);
	wynik_perc.resizeToCurrentText();
	wynik_perc.invalidate();

	bottle_1.setValue(water_percent);
}

void Screen3View::updateBattery(float val)
{
	volt = val;
	if(volt <= 7)
	{
		battery_perc = 0;
	}
	else
	{
		battery_perc = ((volt - 7) * 100)/2;
	}

	Unicode::snprintfFloat(battery_percentBuffer, 10, "%.2f", battery_perc);
	battery_percent.setWildcard(battery_percentBuffer);
	battery_percent.resizeToCurrentText();
	battery_percent.invalidate();

	Unicode::snprintfFloat(battery_voltageBuffer, 10, "%.2f", volt);
	battery_voltage.setWildcard(battery_voltageBuffer);
	battery_voltage.resizeToCurrentText();
	battery_voltage.invalidate();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
