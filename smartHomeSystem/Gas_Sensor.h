#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Gas_Sensor class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Gas_Sensor class'i</p>
*
*
*/
class Gas_Sensor : public Device {

public:


	Gas_Sensor(int, string, int);
	void off();
	void displayMenu();

};