#include "Window.h"
Logger* WindowLogger = Logger::getInstance();
userInterface* WindowMenuGUI = userInterface::getGUI();

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
Window::Window(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Window state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Window nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Window::off() {

	state = false;


}
/**
* \brief <h2><b><i>Window ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Window nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Window::displayMenu() {

	int answer;

	system("cls");

	string WindowsGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
	WindowMenuGUI->display(WindowsGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "Other - " + deviceName + " was enabled";
		WindowLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "Other - " + deviceName + " was disabled";
		WindowLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "Other - " + deviceName + " was checked " + to_string(checkState());
		WindowLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 4:
		WindowsGUI = "\n\tController is being shut down";
		WindowMenuGUI->display(WindowsGUI);

		delayWithMsg("", 1500);
		break;

	default:
		WindowsGUI = "Wrong choice! Please try again: \n";
		WindowMenuGUI->display(WindowsGUI);

		displayMenu();
	}
}