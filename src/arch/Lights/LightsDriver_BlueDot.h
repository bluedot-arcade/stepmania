#ifndef LightsDriver_BlueDot_H
#define LightsDriver_BlueDot_H

#include "LightsDriver.h"
#include "bluedotio.hpp"

class LightsDriver_BlueDot : public LightsDriver
{
private:
	hid_device *device;
public:
	LightsDriver_BlueDot();

	virtual ~LightsDriver_BlueDot();
	virtual void Set(const LightsState *ls);
};

#endif
