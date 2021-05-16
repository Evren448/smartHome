#include "Other.h"
Logger* OtherLogger = Logger::getInstance();
userInterface* OtherMenuGUI = userInterface::getGUI();


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
Other::Other(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Other state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Other nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Other::off() {

	state = false;


}
/**
* \brief <h2><b><i>Other ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Other nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Other::displayMenu() {

	int answer;

	system("cls");
	
	
	string OtherGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	OtherMenuGUI->display(OtherGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Other - " + deviceName + " was enabled";
		OtherLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Other - " + deviceName + " was disabled";
		OtherLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Other - " + deviceName + " was checked " + to_string(checkState());
		OtherLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		OtherGUI = "\n\tController is being shut down";
		OtherMenuGUI->display(OtherGUI);

		delayWithMsg("", 1500);
		break;

	default:
		OtherGUI = "Wrong choice! Please try again: \n";
		OtherMenuGUI->display(OtherGUI);

		displayMenu();
	}
}