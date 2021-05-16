#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Fire_Sensor class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Fire_Sensor class'i</p>
*
*
*/
class Fire_Sensor : public Device {

public:
	

	Fire_Sensor(int, string, int);
	void off();
	void displayMenu();

};