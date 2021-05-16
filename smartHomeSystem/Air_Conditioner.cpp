#include "Air_Conditioner.h"

Logger* AirLogger = Logger::getInstance();
userInterface* AirMenuGUI = userInterface::getGUI();

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
Air_Conditioner::Air_Conditioner(int a, string c, int d) : Device(a, c, d) {

	state = false;
	
}
/**
* \brief <h2><b><i>Air_Conditioner state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Air_Conditioner nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Air_Conditioner::off() {

	state = false;
	
}
/**
* \brief <h2><b><i>Air_Conditioner ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Air_Conditioner nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Air_Conditioner::displayMenu() {

	int answer;

	system("cls");

		string AirGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
		AirMenuGUI->display(AirGUI);



		cin >> answer;
		string logMsg = "";
		switch (answer)
		{
		case 1:
			on();
			logMsg = "Air_Conditioner - " + deviceName + " was enabled";
			AirLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 2:
			off();
			logMsg = "Air_Conditioner - " + deviceName + " was disabled";
			AirLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 3:
			logMsg = "Air_Conditioner - " + deviceName + " was checked " + to_string(checkState());
			AirLogger->writeLine(logMsg);

			delayWithMsg("\n\t" + logMsg, 1500);

			displayMenu();
			break;

		case 4:
			AirGUI = "\n\tController is being shut down";
			AirMenuGUI->display(AirGUI);

			delayWithMsg("", 1500);
			break;

		default:
			AirGUI = "\n\tWrong choice!Please try again";
			AirMenuGUI->display(AirGUI);

			delayWithMsg("", 1500);

			displayMenu();
		}
}
