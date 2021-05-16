#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>Camera class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , Camera class'i</p>
*
*
*/
class Camera : public Device {

public:
	

	Camera(int, string, int);
	void off();
	void displayMenu();

};