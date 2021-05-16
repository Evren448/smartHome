#include "Door.h"
Logger* DoorLogger = Logger::getInstance();
userInterface* DoorMenuGUI = userInterface::getGUI();

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
Door::Door(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Door state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Door nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Door::off() {

	state = false;


}
/**
* \brief <h2><b><i>Door ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Door nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Door::displayMenu() {

	int answer;

	system("cls");

	string DoorGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	DoorMenuGUI->display(DoorGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Camera - " + deviceName + " was enabled";
		DoorLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Camera - " + deviceName + " was disabled";
		DoorLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Camera - " + deviceName + " was checked " + to_string(checkState());
		DoorLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		DoorGUI = "\n\tController is being shut down";
		DoorMenuGUI->display(DoorGUI);

		delayWithMsg("", 1500);
		break;

	default:
		DoorGUI = "Wrong choice! Please try again: \n";
		DoorMenuGUI->display(DoorGUI);

		displayMenu();
	}
}