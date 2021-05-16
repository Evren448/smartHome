#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Air_Conditioner class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Air_Conditioner class'i</p>
*
*
*/
class Air_Conditioner : public Device {

public:
	

	Air_Conditioner(int, string, int);
	void off();
	void displayMenu();
};