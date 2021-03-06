/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN3VIEWBASE_HPP
#define SCREEN3VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/progress_indicators/ImageProgress.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/Color.hpp>

class Screen3ViewBase : public touchgfx::View<Screen3Presenter>
{
public:
    Screen3ViewBase();
    virtual ~Screen3ViewBase() {}
    virtual void setupScreen();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::ButtonWithLabel button_reset;
    touchgfx::TextAreaWithOneWildcard Ilosc_wody;
    touchgfx::TextArea textArea2;
    touchgfx::ImageProgress bottle_1;
    touchgfx::TextAreaWithOneWildcard wynik_perc;
    touchgfx::TextAreaWithOneWildcard battery_percent;
    touchgfx::TextAreaWithOneWildcard battery_voltage;
    touchgfx::Image image1;
    touchgfx::TextAreaWithOneWildcard wynik_ml;
    touchgfx::ModalWindow Are_you_sure_window;
    touchgfx::ButtonWithLabel button_yes_reset;
    touchgfx::TextArea textArea1;
    touchgfx::ButtonWithLabel button_no_reset;

    /*
     * Wildcard Buffers
     */
    static const uint16_t ILOSC_WODY_SIZE = 10;
    touchgfx::Unicode::UnicodeChar Ilosc_wodyBuffer[ILOSC_WODY_SIZE];
    static const uint16_t WYNIK_PERC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar wynik_percBuffer[WYNIK_PERC_SIZE];
    static const uint16_t BATTERY_PERCENT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar battery_percentBuffer[BATTERY_PERCENT_SIZE];
    static const uint16_t BATTERY_VOLTAGE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar battery_voltageBuffer[BATTERY_VOLTAGE_SIZE];
    static const uint16_t WYNIK_ML_SIZE = 20;
    touchgfx::Unicode::UnicodeChar wynik_mlBuffer[WYNIK_ML_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen3ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN3VIEWBASE_HPP
