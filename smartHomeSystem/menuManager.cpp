#include "menuManager.h"
#include "userInterface.h"
#include "functions.h"


/**
* \brief <h2><b><i>Ana menuyu yaratir</i></b></h2>
*
* <p>&emsp;&emsp;Device listesini okuyarak ana menuyu listeler ve secim icin girdi bekler. Gelen secimin uygunluguna gore istenen cihazin kendi menusu acilir.</p>
*
* \param deviceList: Device listesi
*/
void menuManager::createMenu(vector<Device*>& deviceList) {
	if (this->deviceList.size() == 0) { // Özyineli fonksiyon olarak kullanýldýðý için, deviceList bir kere doldu ise tekrar doldrulmasýný engeller.
		this->deviceList = deviceList;
	}
	

	string theMenuElement; // menu ekranýnda görünecek her bir elemaný uygun biçimde saklar.
	userInterface* myDeviceMenuGUI = userInterface::getGUI();

	myDeviceMenuGUI->display("\n");
	system("cls");
	for (int i = 0; i < this->deviceList.size(); i++){ // Device isimleri uygun biçimde display fonksiyonuna atýlýyor.

		theMenuElement = to_string(i+1) + ") " + this->deviceList[i]->getDeviceName() + "\n";
		myDeviceMenuGUI->display(theMenuElement);
		if (i + 1 == this->deviceList.size()) { // En sonuncu elemanýn altýna "Shutdown all devices" seçeðini basar.
			theMenuElement = "---" + to_string(i + 2) + ") " + "Shutdown all devices." + "\n";
			myDeviceMenuGUI->display(theMenuElement);
		}
	}


	int selection = 0;
	int selectionMAX = this->deviceList.size();
	myDeviceMenuGUI->display("\n\tPlease make your selection: ");	cin >> selection;
	Logger* ShutDownAllLogger = Logger::getInstance();
	string logMsg = "";

	if (selection > 0 && selection <= selectionMAX) {
		this->deviceList[selection - 1]->displayMenu();
		this->createMenu(deviceList);
	}
	else if (selection == selectionMAX + 1) {
		for (int i = 0; i < this->deviceList.size(); i++) {
			this->deviceList[i]->off();
		}
		logMsg = "All devices were disabled.";
		ShutDownAllLogger->writeLine(logMsg);
		this->createMenu(deviceList);
	}
	else {
		myDeviceMenuGUI->display("\n\tWrong Choise.\n\tPlease fix it and try again.\n\t");
		delayWithMsg("", 1500);
		this->createMenu(deviceList);
	}
}