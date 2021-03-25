#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::swButtonHwLedToggle(){model->toggleHwLed();}
void Screen3Presenter::swButtonSwLedToggle(){view.toggleSwLed();}
void Screen3Presenter::userButtonPressed(){view.toggleSwLed();}
