#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Home_Theatre class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Home_Theatre class'i</p>
*
*
*/
class Home_Theatre : public Device {

public:
	

	Home_Theatre(int, string, int);
	void off();
	void displayMenu();

};
