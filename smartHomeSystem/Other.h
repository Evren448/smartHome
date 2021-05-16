#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Other class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Other class'i</p>
*
*
*/
class Other : public Device {

public:
	

	Other(int, string, int);
	void off();
	void displayMenu();

};