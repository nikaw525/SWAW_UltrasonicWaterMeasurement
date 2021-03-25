#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

Screen4Presenter::Screen4Presenter(Screen4View& v)
    : view(v)
{

}

void Screen4Presenter::activate()
{

	 model->setScanJunctionTemp(true);


}

void Screen4Presenter::deactivate()
{

}


void Screen4Presenter::newJunctionTempValue(int value)
{
    view.setJunctionTempValue(value);
}
