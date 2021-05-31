#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stdint.h"

Model::Model() : modelListener(0), waga(0), pojemnosc(0)

{

}

extern "C" {

}


int Model::getWaga()
{
	return waga;
}

int Model::getPojemnosc()
{
	return pojemnosc;
}


