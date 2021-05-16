#include "Speakers.h"
Logger* SpeakersLogger = Logger::getInstance();
userInterface* SpeakersMenuGUI = userInterface::getGUI();

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
Speakers::Speakers(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Speakers state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Speakers nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Speakers::off() {

	state = false;


}
/**
* \brief <h2><b><i>Speakers ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Speakers nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Speakers::displayMenu() {

	int answer;

	system("cls");

	
	string SpeakerGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	SpeakersMenuGUI->display(SpeakerGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Other - " + deviceName + " was enabled";
		SpeakersLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Other - " + deviceName + " was disabled";
		SpeakersLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Other - " + deviceName + " was checked " + to_string(checkState());
		SpeakersLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		SpeakerGUI = "\n\tController is being shut down";
		SpeakersMenuGUI->display(SpeakerGUI);

		delayWithMsg("", 1500);
		break;

	default:
		SpeakerGUI = "Wrong choice! Please try again: \n";
		SpeakersMenuGUI->display(SpeakerGUI);

		displayMenu();
	}
}