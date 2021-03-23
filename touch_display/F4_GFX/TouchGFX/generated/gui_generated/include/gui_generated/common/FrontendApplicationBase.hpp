/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Screen1
    void gotoScreen1ScreenNoTransition();

    void gotoScreen1ScreenCoverTransitionWest();

    // Screen2
    void gotoScreen2ScreenCoverTransitionEast();

    void gotoScreen2ScreenCoverTransitionWest();

    // Screen3
    void gotoScreen3ScreenCoverTransitionEast();

    void gotoScreen3ScreenCoverTransitionWest();

    // Screen4
    void gotoScreen4ScreenCoverTransitionEast();

    void gotoScreen4ScreenCoverTransitionWest();

    // Screen5
    void gotoScreen5ScreenCoverTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();

    void gotoScreen1ScreenCoverTransitionWestImpl();

    // Screen2
    void gotoScreen2ScreenCoverTransitionEastImpl();

    void gotoScreen2ScreenCoverTransitionWestImpl();

    // Screen3
    void gotoScreen3ScreenCoverTransitionEastImpl();

    void gotoScreen3ScreenCoverTransitionWestImpl();

    // Screen4
    void gotoScreen4ScreenCoverTransitionEastImpl();

    void gotoScreen4ScreenCoverTransitionWestImpl();

    // Screen5
    void gotoScreen5ScreenCoverTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
