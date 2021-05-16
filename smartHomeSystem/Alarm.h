#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Alarm class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Alarm class'i</p>
*
*
*/
class Alarm : public Device {

public:
	

	Alarm(int, string, int);
	void off();
	void displayMenu();

};