#pragma once
#include "Device.h"
#include "TV.h"
#include "Air_Conditioner.h"
#include "Home_Theatre.h"
#include "Speakers.h"
#include "Door.h"
#include "Window.h"
#include "Alarm.h"
#include "Camera.h"
#include "Fire_Sensor.h"
#include "Gas_Sensor.h"
#include "Motion_Sensor.h"
#include "Light.h"
#include "Other.h"

/**
* \brief <h2><b><i>Device uretimi</i></b></h2>
*
* <p>&emsp;&emsp;Devicelari uygun bicimde uretmekten sorumlu olan class.</p>
*/
class deviceFactory {
public:
	static Device* create(string);
};