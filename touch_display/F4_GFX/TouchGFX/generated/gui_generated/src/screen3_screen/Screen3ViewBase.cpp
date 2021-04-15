/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Screen3ViewBase::Screen3ViewBase() :
    buttonCallback(this, &Screen3ViewBase::buttonCallbackHandler)
{

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(141, 178, 224));

    imageProgress1.setXY(23, 78);
    imageProgress1.setProgressIndicatorPosition(2, 2, 16, 180);
    imageProgress1.setRange(0, 100);
    imageProgress1.setDirection(touchgfx::AbstractDirectionProgress::DOWN);
    imageProgress1.setBackground(touchgfx::Bitmap(BITMAP_DARK_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_90_DEGREES_ID));
    imageProgress1.setBitmap(BITMAP_DARK_PROGRESSINDICATORS_FILL_TILING_PROGRESS_INDICATOR_FILL_STRIPED_NORMAL_VERTICAL_ID);
    imageProgress1.setValue(60);
    imageProgress1.setAnchorAtZero(false);

    button_reset.setXY(299, 202);
    button_reset.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    button_reset.setLabelText(touchgfx::TypedText(T_SINGLEUSEID22));
    button_reset.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_reset.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_reset.setAction(buttonCallback);

    imageProgress1_1.setXY(61, 78);
    imageProgress1_1.setProgressIndicatorPosition(2, 2, 16, 180);
    imageProgress1_1.setRange(0, 100);
    imageProgress1_1.setDirection(touchgfx::AbstractDirectionProgress::DOWN);
    imageProgress1_1.setBackground(touchgfx::Bitmap(BITMAP_DARK_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_90_DEGREES_ID));
    imageProgress1_1.setBitmap(BITMAP_DARK_PROGRESSINDICATORS_FILL_TILING_PROGRESS_INDICATOR_FILL_STRIPED_NORMAL_VERTICAL_ID);
    imageProgress1_1.setValue(60);
    imageProgress1_1.setAnchorAtZero(false);

    Are_you_sure_window.setBackground(touchgfx::BitmapId(BITMAP_DARK_BACKGROUNDS_MAIN_BG_320X240PX_ID), 80, 16);
    Are_you_sure_window.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    Are_you_sure_window.setShadeAlpha(152);
    Are_you_sure_window.hide();

    button_yes_reset.setXY(68, 156);
    button_yes_reset.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_yes_reset.setLabelText(touchgfx::TypedText(T_SINGLEUSEID23));
    button_yes_reset.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_yes_reset.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_yes_reset.setAction(buttonCallback);
    Are_you_sure_window.add(button_yes_reset);

    textArea1.setXY(48, 38);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID24));
    Are_you_sure_window.add(textArea1);

    button_no_reset.setXY(192, 156);
    button_no_reset.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_no_reset.setLabelText(touchgfx::TypedText(T_SINGLEUSEID25));
    button_no_reset.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_no_reset.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_no_reset.setAction(buttonCallback);
    Are_you_sure_window.add(button_no_reset);

    add(box1);
    add(imageProgress1);
    add(button_reset);
    add(imageProgress1_1);
    add(Are_you_sure_window);
}

void Screen3ViewBase::setupScreen()
{

}

void Screen3ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button_reset)
    {
        //Are_you_sure_window
        //When button_reset clicked show Are_you_sure_window
        //Show Are_you_sure_window
        Are_you_sure_window.setVisible(true);
        Are_you_sure_window.invalidate();
    }
    else if (&src == &button_yes_reset)
    {
        //Reset
        //When button_yes_reset clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenCoverTransitionEast();
    }
    else if (&src == &button_no_reset)
    {
        //Dont_reset
        //When button_no_reset clicked hide Are_you_sure_window
        //Hide Are_you_sure_window
        Are_you_sure_window.setVisible(false);
        Are_you_sure_window.invalidate();
    }
}
