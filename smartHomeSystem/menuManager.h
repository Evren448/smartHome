#pragma once
#include "Device.h"
#include <vector>

/**
* \brief <h2><b><i>Menu yonetimi</i></b></h2>
*
* <p>&emsp;&emsp;Devicelarin listelendigi ana bir menu olustmaktan sorumludur.</p>
*/
class menuManager {
private:
	/**
	* \brief deviceList attribute
	*/
	vector <Device*> deviceList;
public:
	void createMenu(vector<Device*>&);
};