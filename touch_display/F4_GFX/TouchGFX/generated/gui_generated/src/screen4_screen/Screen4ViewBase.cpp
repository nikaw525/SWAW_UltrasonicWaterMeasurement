/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

Screen4ViewBase::Screen4ViewBase() :
    buttonCallback(this, &Screen4ViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    box1_1.setPosition(0, 200, 480, 72);
    box1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 210, 0));

    box1.setPosition(0, 0, 480, 200);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 35, 75));

    go_slide_1.setXY(355, 206);
    go_slide_1.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_HOME_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_HOME_32_ID));
    go_slide_1.setIconXY(15, 16);
    go_slide_1.setAction(buttonCallback);

    go_slide_5.setXY(415, 206);
    go_slide_5.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_NEXT_ARROW_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_NEXT_ARROW_32_ID));
    go_slide_5.setIconXY(22, 15);
    go_slide_5.setAction(buttonCallback);

    go_slide_3.setXY(295, 206);
    go_slide_3.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_BACK_ARROW_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_BACK_ARROW_32_ID));
    go_slide_3.setIconXY(22, 15);
    go_slide_3.setAction(buttonCallback);

    temperatureBar.setXY(100, 62);
    temperatureBar.setProgressIndicatorPosition(19, 27, 150, 18);
    temperatureBar.setRange(0, 100);
    temperatureBar.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    temperatureBar.setBackground(touchgfx::Bitmap(BITMAP_HOR_THERM_BG_SCALE_ID));
    temperatureBar.setBitmap(BITMAP_HOR_THERM_PROGRESS_ID);
    temperatureBar.setValue(59);
    temperatureBar.setAnchorAtZero(true);

    add(__background);
    add(box1_1);
    add(box1);
    add(go_slide_1);
    add(go_slide_5);
    add(go_slide_3);
    add(temperatureBar);
}

void Screen4ViewBase::setupScreen()
{

}

void Screen4ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &go_slide_1)
    {
        //go_slide_1
        //When go_slide_1 clicked change screen to Screen1
        //Go to Screen1 with screen transition towards West
        application().gotoScreen1ScreenCoverTransitionWest();
    }
    else if (&src == &go_slide_5)
    {
        //go_slide_5
        //When go_slide_5 clicked change screen to Screen5
        //Go to Screen5 with screen transition towards East
        application().gotoScreen5ScreenCoverTransitionEast();
    }
    else if (&src == &go_slide_3)
    {
        //go_slide_3
        //When go_slide_3 clicked change screen to Screen3
        //Go to Screen3 with screen transition towards West
        application().gotoScreen3ScreenCoverTransitionWest();
    }
}
