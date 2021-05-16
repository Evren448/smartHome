#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Light class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Light class'i</p>
*
*
*/
class Light : public Device {

public:
	

	Light(int, string, int);
	void off();
	void displayMenu();

};