#include "deviceFactory.h"

#include "functions.h"

/**
* \brief <h2><b><i>Uygun devicelari yaratir</i></b></h2>
*
* <p>&emsp;&emsp;Okunmuþ dosya satirini alir, ayristirir ve type degerine uygun olarak device i yaratir. Sonucunda abstract classtan olusturulan bir pointer icinde yaratilmis nesneyi geri dondurur.</p>
*
* \param datLine: Dosyadan okunmus satir
* \return theDevice
*/
Device* deviceFactory::create(string datLine){
	istringstream iss(datLine);
	string id, type, name, port;
	if (!(iss >> id >> type >> name >> port)) { // satýrlar parse ediliyor ve check ediliyor.
		cout << endl << datLine << " => This line is not correct.\nPlease fix it and try again." << endl << endl << endl;
		exit(0);
	}
	int idNum = stoi(id);
	int portNum = stoi(port);

	// type eþleþtirilip nesneler yaratýlyor.
	Device *theDevice = NULL;

	if (type == "TV") {
		theDevice = new TV(idNum, name, portNum);
	}
	else if (type == "Air_Conditioner") {
		theDevice = new Air_Conditioner(idNum, name, portNum);
	}
	else if (type == "Home_Theatre") {
		theDevice = new Home_Theatre(idNum, name, portNum);
	}
	else if (type == "Speakers") {
		theDevice = new Speakers(idNum, name, portNum);
	}
	else if (type == "Door") {
		theDevice = new Door(idNum, name, portNum);
	}
	else if (type == "Window") {
		theDevice = new Window(idNum, name, portNum);
	}
	else if (type == "Alarm") {
		theDevice = new Alarm(idNum, name, portNum);
	}
	else if (type == "Camera") {
		theDevice = new Camera(idNum, name, portNum);
	}
	else if (type == "Fire_Sensor") {
		theDevice = new Fire_Sensor(idNum, name, portNum);
	}
	else if (type == "Gas_Sensor") {
		theDevice = new Gas_Sensor(idNum, name, portNum);
	}
	else if (type == "Motion_Sensor") {
		theDevice = new Motion_Sensor(idNum, name, portNum);
	}
	else if (type == "Light") {
		theDevice = new Light(idNum, name, portNum);
	}
	else {
		theDevice = new Other(idNum, name, portNum);
	}

	return theDevice;
}