#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{
	data_destination[0] = 0;
	data_destination[1] = 0;
	data_destination[2] = 0;
	waga_value = 0;
	wzrost_value = 0;
	pojemnosc_value = 0;
}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::NumberButtonClicked(int number)
{

	view.updateTxt(number);

}
void Screen2Presenter::DestinationButtonClicked(int number)
{
	if(1 == data_destination[number])
	{
		data_destination[number] = 0;
	}
	else
	{
		data_destination[number] = 1;
		data_destination[(number+1)%3] = 0;
		data_destination[(number+2)%3] = 0;
	}
}
