/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Screen2ViewBase::Screen2ViewBase() :
    buttonCallback(this, &Screen2ViewBase::buttonCallbackHandler)
{

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(162, 180, 201));

    textArea1.setXY(47, 9);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID8));

    button_ok.setXY(285, 189);
    button_ok.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_ok.setLabelText(touchgfx::TypedText(T_SINGLEUSEID9));
    button_ok.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_ok.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_ok.setAction(buttonCallback);

    button_1.setXY(285, 129);
    button_1.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID10));
    button_1.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_1.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_1.setAction(buttonCallback);

    button_2.setXY(344, 129);
    button_2.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_2.setLabelText(touchgfx::TypedText(T_SINGLEUSEID11));
    button_2.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_2.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_2.setAction(buttonCallback);

    button_3.setXY(404, 129);
    button_3.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_3.setLabelText(touchgfx::TypedText(T_SINGLEUSEID12));
    button_3.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_3.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_3.setAction(buttonCallback);

    button_4.setXY(285, 69);
    button_4.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_4.setLabelText(touchgfx::TypedText(T_SINGLEUSEID13));
    button_4.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_4.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_4.setAction(buttonCallback);

    button_5.setXY(344, 69);
    button_5.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_5.setLabelText(touchgfx::TypedText(T_SINGLEUSEID14));
    button_5.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_5.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_5.setAction(buttonCallback);

    button_6.setXY(405, 69);
    button_6.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_6.setLabelText(touchgfx::TypedText(T_SINGLEUSEID15));
    button_6.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_6.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_6.setAction(buttonCallback);

    button_7.setXY(284, 9);
    button_7.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_7.setLabelText(touchgfx::TypedText(T_SINGLEUSEID16));
    button_7.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_7.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_7.setAction(buttonCallback);

    button_8.setXY(345, 9);
    button_8.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_8.setLabelText(touchgfx::TypedText(T_SINGLEUSEID17));
    button_8.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_8.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_8.setAction(buttonCallback);

    button_9.setXY(405, 9);
    button_9.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_9.setLabelText(touchgfx::TypedText(T_SINGLEUSEID18));
    button_9.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_9.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_9.setAction(buttonCallback);

    button_0.setXY(345, 189);
    button_0.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    button_0.setLabelText(touchgfx::TypedText(T_SINGLEUSEID19));
    button_0.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_0.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    button_0.setAction(buttonCallback);

    pojemnosc_box.setPosition(174, 162, 104, 55);
    pojemnosc_box.setColor(touchgfx::Color::getColorFrom24BitRGB(162, 180, 201));
    pojemnosc_box.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(162, 180, 201));
    pojemnosc_box.setBorderSize(5);

    waga_box.setPosition(174, 57, 104, 55);
    waga_box.setColor(touchgfx::Color::getColorFrom24BitRGB(162, 180, 201));
    waga_box.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(162, 180, 201));
    waga_box.setBorderSize(5);

    value_waga.setXY(184, 70);
    value_waga.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    value_waga.setLinespacing(0);
    Unicode::snprintf(value_wagaBuffer, VALUE_WAGA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID28).getText());
    value_waga.setWildcard(value_wagaBuffer);
    value_waga.resizeToCurrentText();
    value_waga.setTypedText(touchgfx::TypedText(T_SINGLEUSEID27));

    value_pojemnosc.setXY(184, 136);
    value_pojemnosc.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    value_pojemnosc.setLinespacing(0);
    Unicode::snprintf(value_pojemnoscBuffer, VALUE_POJEMNOSC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID34).getText());
    value_pojemnosc.setWildcard(value_pojemnoscBuffer);
    value_pojemnosc.resizeToCurrentText();
    value_pojemnosc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID33));

    Button_waga.setXY(4, 52);
    Button_waga.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    Button_waga.setLabelText(touchgfx::TypedText(T_SINGLEUSEID35));
    Button_waga.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_waga.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_waga.setAction(buttonCallback);

    Button_pojemnosc.setXY(4, 117);
    Button_pojemnosc.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    Button_pojemnosc.setLabelText(touchgfx::TypedText(T_SINGLEUSEID37));
    Button_pojemnosc.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_pojemnosc.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_pojemnosc.setAction(buttonCallback);

    textArea2.setXY(242, 69);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID38));

    textArea2_1_1.setXY(240, 137);
    textArea2_1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2_1_1.setLinespacing(0);
    textArea2_1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID42));

    button_clear.setXY(405, 189);
    button_clear.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_BACK_ARROW_32_ID));
    button_clear.setIconXY(21, 14);
    button_clear.setAction(buttonCallback);

    Button_wysokosc.setXY(4, 189);
    Button_wysokosc.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    Button_wysokosc.setLabelText(touchgfx::TypedText(T_SINGLEUSEID49));
    Button_wysokosc.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_wysokosc.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Button_wysokosc.setAction(buttonCallback);

    value_wysokosc.setXY(184, 205);
    value_wysokosc.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    value_wysokosc.setLinespacing(0);
    Unicode::snprintf(value_wysokoscBuffer, VALUE_WYSOKOSC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID51).getText());
    value_wysokosc.setWildcard(value_wysokoscBuffer);
    value_wysokosc.resizeToCurrentText();
    value_wysokosc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID50));

    textArea2_1_1_1.setXY(242, 205);
    textArea2_1_1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2_1_1_1.setLinespacing(0);
    textArea2_1_1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID52));

    add(box1);
    add(textArea1);
    add(button_ok);
    add(button_1);
    add(button_2);
    add(button_3);
    add(button_4);
    add(button_5);
    add(button_6);
    add(button_7);
    add(button_8);
    add(button_9);
    add(button_0);
    add(pojemnosc_box);
    add(waga_box);
    add(value_waga);
    add(value_pojemnosc);
    add(Button_waga);
    add(Button_pojemnosc);
    add(textArea2);
    add(textArea2_1_1);
    add(button_clear);
    add(Button_wysokosc);
    add(value_wysokosc);
    add(textArea2_1_1_1);
}

void Screen2ViewBase::setupScreen()
{

}

void Screen2ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button_ok)
    {
        //Button_ok
        //When button_ok clicked change screen to Screen3
        //Go to Screen3 with screen transition towards East
        application().gotoScreen3ScreenCoverTransitionEast();

        //Button_ok_cpp_code
        //When button_ok clicked execute C++ code
        //Execute C++ code
        presenter->saveWaga();
        presenter->savePojemnosc();
        presenter->saveWysokosc();
    }
    else if (&src == &button_1)
    {
        //Button_1
        //When button_1 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(1);
    }
    else if (&src == &button_2)
    {
        //Button_2
        //When button_2 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(2);
    }
    else if (&src == &button_3)
    {
        //Button_3
        //When button_3 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(3);
    }
    else if (&src == &button_4)
    {
        //Button_4
        //When button_4 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(4);
    }
    else if (&src == &button_5)
    {
        //Button_5
        //When button_5 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(5);
    }
    else if (&src == &button_6)
    {
        //Button_6
        //When button_6 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(6);
    }
    else if (&src == &button_7)
    {
        //button_7
        //When button_7 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(7);
    }
    else if (&src == &button_8)
    {
        //Button_8
        //When button_8 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(8);
    }
    else if (&src == &button_9)
    {
        //Button_9
        //When button_9 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(9);
    }
    else if (&src == &button_0)
    {
        //Button_0
        //When button_0 clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(0);
    }
    else if (&src == &Button_waga)
    {
        //waga_button
        //When Button_waga clicked execute C++ code
        //Execute C++ code
        presenter->DestinationButtonClicked(0);
    }
    else if (&src == &Button_pojemnosc)
    {
        //pojemnosc_button
        //When Button_pojemnosc clicked execute C++ code
        //Execute C++ code
        presenter->DestinationButtonClicked(2);
    }
    else if (&src == &button_clear)
    {
        //button_clear
        //When button_clear clicked execute C++ code
        //Execute C++ code
        presenter->NumberButtonClicked(-1);
    }
    else if (&src == &Button_wysokosc)
    {
        //Button_wysokosc
        //When Button_wysokosc clicked execute C++ code
        //Execute C++ code
        presenter->DestinationButtonClicked(1);
    }
}
