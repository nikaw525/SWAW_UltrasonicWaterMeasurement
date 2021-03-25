#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stdint.h"

Model::Model() : modelListener(0)

, tickCounter(0), scanJunctionTemp(false)

{

}


extern "C" {
	extern void TOGGLE_LED1(void);
	extern uint32_t userButtonPressed;
}


void Model::tick()
{

#ifndef SIMULATOR
	if (userButtonPressed == 1)
	{
		userButtonPressed = 0;
		modelListener->userButtonPressed();
	}
#endif /*SIMULATOR*/

	 tickCounter++;
	    if (((tickCounter % 20) == 0) && (scanJunctionTemp))
	    {
	      if (modelListener != 0)
	      {
	        modelListener->newJunctionTempValue(getTempValue());
	      }
	    }


}


void Model::toggleHwLed() {
	#ifndef SIMULATOR
		TOGGLE_LED1();
	#endif /*SIMULATOR*/
}


void Model::setScanJunctionTemp(bool scanEnabled)
{
     scanJunctionTemp = scanEnabled;
}

extern "C" {
     extern uint32_t TEMP_SENSOR_GetValue(void);
}


int Model::getTempValue()
{
#ifndef SIMULATOR
     return TEMP_SENSOR_GetValue();
#else
     return 25;
#endif
}

