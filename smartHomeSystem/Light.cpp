#include "Light.h"
Logger* LightLogger = Logger::getInstance();
userInterface* LightMenuGUI = userInterface::getGUI();

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
Light::Light(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Light state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Light nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Light::off() {

	state = false;


}
/**
* \brief <h2><b><i>Light ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Light nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Light::displayMenu() {

	int answer;

	system("cls");
	
	string LightGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	LightMenuGUI->display(LightGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Light - " + deviceName + " was enabled";
		LightLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Light - " + deviceName + " was disabled";
		LightLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Light - " + deviceName + " was checked " + to_string(checkState());
		LightLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		LightGUI = "\n\tController is being shut down";
		LightMenuGUI->display(LightGUI);

		delayWithMsg("", 1500);
		break;

	default:
		LightGUI = "Wrong choice! Please try again: \n";
		LightMenuGUI->display(LightGUI);

		displayMenu();
	}
}