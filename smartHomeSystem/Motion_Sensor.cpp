#include "Motion_Sensor.h"
Logger* MotionLogger = Logger::getInstance();
userInterface* MotionMenuGUI = userInterface::getGUI();

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
Motion_Sensor::Motion_Sensor(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Motion_Sensor state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Motion_Sensor nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Motion_Sensor::off() {

	state = false;


}
/**
* \brief <h2><b><i>Motion_Sensor ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Motion_Sensor nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Motion_Sensor::displayMenu() {

	int answer;

	system("cls");

	string MotGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	MotionMenuGUI->display(MotGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Motion_Sensor - " + deviceName + " was enabled";
		MotionLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Motion_Sensor - " + deviceName + " was disabled";
		MotionLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Motion_Sensor - " + deviceName + " was checked " + to_string(checkState());
		MotionLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		MotGUI = "\n\tController is being shut down";
		MotionMenuGUI->display(MotGUI);

		delayWithMsg("", 1500);
		break;

	default:
		MotGUI = "Wrong choice! Please try again: \n";
		MotionMenuGUI->display(MotGUI);

		displayMenu();
	}
}