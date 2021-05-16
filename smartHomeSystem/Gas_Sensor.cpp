#include "Gas_Sensor.h"
Logger* GasLogger = Logger::getInstance();
userInterface* GasMenuGUI = userInterface::getGUI();
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
Gas_Sensor::Gas_Sensor(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Gas_Sensor state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Gas_Sensor nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Gas_Sensor::off() {

	state = false;


}
/**
* \brief <h2><b><i>Gas_Sensor ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Gas_Sensor nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Gas_Sensor::displayMenu() {

	int answer;

	system("cls");

	string GasGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	GasMenuGUI->display(GasGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Gas_Sensor - " + deviceName + " was enabled";
		GasLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Gas_Sensor - " + deviceName + " was disabled";
		GasLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Gas_Sensor - " + deviceName + " was checked " + to_string(checkState());
		GasLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		GasGUI = "\n\tController is being shut down";
		GasMenuGUI->display(GasGUI);

		delayWithMsg("", 1500);
		break;

	default:
		GasGUI = "Wrong choice! Please try again: \n";
		GasMenuGUI->display(GasGUI);

		displayMenu();
	}
}