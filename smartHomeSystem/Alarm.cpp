#include "Alarm.h"
Logger* AlarmLogger = Logger::getInstance();
userInterface* AlarmMenuGUI = userInterface::getGUI();

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
Alarm::Alarm(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Alarm state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Alarm nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Alarm::off() {

	state = false;

}
/**
* \brief <h2><b><i>Alarm ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Alarm nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Alarm::displayMenu() {

	int answer;

	system("cls");

		string AlarmGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
		AlarmMenuGUI->display(AlarmGUI);



		cin >> answer;
		string logMsg = "";
		switch (answer)
		{
		case 1:
			on();
			logMsg = "Alarm - " + deviceName + " was enabled";
			AlarmLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 2:
			off();
			logMsg = "Alarm - " + deviceName + " was disabled";
			AlarmLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 3:
			logMsg = "Alarm - " + deviceName + " was checked " + to_string(checkState());
			AlarmLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 4:
			AlarmGUI = "\n\tController is being shut down";
			AlarmMenuGUI->display(AlarmGUI);

			delayWithMsg("", 1500);
			break;

		default:
			AlarmGUI = "\n\tWrong choice!Please try again";
			AlarmMenuGUI->display(AlarmGUI);

			delayWithMsg("", 1500);

			displayMenu();
		}
}