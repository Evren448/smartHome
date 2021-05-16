#include "Device.h"



/**
* \brief <h2><b><i>Constructor.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor</p>
*
* \param a: id degiskeni.
* \param c: deviceName degiskeni.
* \param d: port degiskeni.
*
*/

Device::Device(int a, string c, int d) : id(a), deviceName(c), port(d) {

	

}
/**
* \brief <h2><b><i>getID fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;id degiskenini dondurur</p>
*
* \return id
*/
const int Device::getID()  {

	return id;

}
/**
* \brief <h2><b><i>getDeviceName fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;deviceName degiskenini dondurur</p>
*
* \return deviceName
*/
const string Device::getDeviceName()  {

	return deviceName;

}
/**
* \brief <h2><b><i>getPort fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;getPort degiskenini dondurur</p>
*
* \return getPort
*/
const int Device::getPort() {

	return port;

}
/**
* \brief <h2><b><i>checkState fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;State yi kontrol edip state'nin getirilmesini calistiran fonksiyon.</p>
*
* \return true/false
*/

const bool Device::checkState() {

	if (state == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
* \brief <h2><b><i>Device state durumunu acma</i></b></h2>
*
* <p>&emsp;&emsp;Device nin state durumunu 1 durumuna getirir.</p>
*
*
*/
void Device::on() {

	state = true;
	
}

