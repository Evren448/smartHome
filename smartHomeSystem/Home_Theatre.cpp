#include "Home_Theatre.h"
Logger* HomeLogger = Logger::getInstance();
userInterface* HomeMenuGUI = userInterface::getGUI();

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
Home_Theatre::Home_Theatre(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Home_Theatre state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Home_Theatre nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Home_Theatre::off() {

	state = false;


}
/**
* \brief <h2><b><i>Home_Theatre ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Home_Theatre nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Home_Theatre::displayMenu() {

	int answer;

	system("cls");
	
	string HomeGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	HomeMenuGUI->display(HomeGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Home_Theatre - " + deviceName + " was enabled";
		HomeLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Home_Theatre - " + deviceName + " was disabled";
		HomeLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Home_Theatre - " + deviceName + " was checked " + to_string(checkState());
		HomeLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		HomeGUI = "\n\tController is being shut down";
		HomeMenuGUI->display(HomeGUI);

		delayWithMsg("", 1500);
		break;

	default:
		HomeGUI = "Wrong choice! Please try again: \n";
		HomeMenuGUI->display(HomeGUI);

		displayMenu();
	}
}