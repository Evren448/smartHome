#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Motion_Sensor class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Motion_Sensor class'i</p>
*
*
*/
class Motion_Sensor : public Device {

public:
	

	Motion_Sensor(int, string, int);
	void off();
	void displayMenu();

};