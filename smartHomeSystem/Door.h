#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Door class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Door class'i</p>
*
*
*/
class Door : public Device {

public:
	

	Door(int, string, int);
	void off();
	void displayMenu();

};