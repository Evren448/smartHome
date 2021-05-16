#pragma once
#include "Device.h"

/**
* \brief <h2><b><i>TV class.</i></b></h2>
*
* <p>&emsp;&emsp;Device Class'indan inherite edilmis , TV class'i</p>
*
*
*/
class TV : public Device {
private:
	/**
	* \brief activeChannel attribute
	*/
	int activeChannel;
	/**
	* \brief channelList attribute
	*/
	vector<string> channelList = {"STAND BY" , "TRT 1" , "Show TV" , "TV 8" ,
									"Kanal D" , "STAR TV" , "TLC" , "NTV"};

public:
	 
	
	TV(int, string, int);
	void off();
	void displayMenu();
	void selectChannel(int);
	void standBy();
	
	
	 
};


