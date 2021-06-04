#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stdint.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

unsigned int counter = 0;

extern "C"
{
	xQueueHandle messageQ;
}
Model::Model() : modelListener(0), waga(0), pojemnosc(0)

{
	messageQ = xQueueGenericCreate(1, 1, 0);
}
void Model::tick()
{
	if(xQueueReceive(messageQ, &counter, 0) == pdTRUE)
	{
		modelListener->setNewBatteryValue(counter);
	}
}

int Model::getWaga()
{
	return waga;
}

int Model::getPojemnosc()
{
	return pojemnosc;
}
int Model::getWysokosc()
{
	return wysokosc;
}

