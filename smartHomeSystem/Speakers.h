#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Speakers class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Speakers class'i</p>
*
*
*/
class Speakers : public Device {

public:
	

	Speakers(int, string, int);
	void off();
	void displayMenu();

};