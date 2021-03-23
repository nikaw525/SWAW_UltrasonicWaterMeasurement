#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void AlphaChange(int value)
    {
        touchGFX_logo.setAlpha(value);
        touchGFX_logo.invalidate();
    }

    virtual void XChange(int value)
    {
        touchGFX_logo.setX(value);
        box1.invalidate();
    }

    virtual void YChange(int value)
    {
        touchGFX_logo.setY(value);
        box1.invalidate();
    }
protected:
};

#endif // SCREEN2VIEW_HPP
