#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Window class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Window class'i</p>
*
*
*/
class Window : public Device {

public:
	

	Window(int, string, int);
	void off();
	void displayMenu();

};