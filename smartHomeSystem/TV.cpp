#include "TV.h"
Logger* TVLogger = Logger::getInstance();
userInterface* TVMenuGUI = userInterface::getGUI();

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
TV::TV(int a, string c, int d) : Device(a, c, d) {

	state = false;
	activeChannel = 1;
	
	
}
/**
* \brief <h2><b><i>TV state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Tv nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void TV::off() {
	state = false;
	

}
/**
* \brief <h2><b><i>Kanal secici fonksiyon</i></b></h2>
*
* <p>&emsp;&emsp;Verilen channelValue degerine gore o sayiya ait kanali acar.</p>
*
* \param channelValue: Acilmak istenilen kanalin sira numarasi.
*
*/
void TV::selectChannel(int channelValue) {

	activeChannel = channelValue;

}
/**
* \brief <h2><b><i>StandBy fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;TV yi StandBy moda alir.</p>
*
*
*/
void TV::standBy() {

	activeChannel = 0;

}

/**
* \brief <h2><b><i>TV ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;TV nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/

void TV::displayMenu() {

	int answer;

	system("cls");

	string TVGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Channel Menu, 5 for Stand By ,6 for Exit , depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Channel Menu\n5) Stand By Mode\n6) Exit\n\n\tPlease make your choice: ";
	TVMenuGUI->display(TVGUI);



	cin >> answer;
	string logMsg = "";
	switch (answer)
	{
	case 1:
		on();
		logMsg = "TV - " + deviceName + " was enabled";
		TVLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 2:
		off();
		logMsg = "TV - " + deviceName + " was disabled";
		TVLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

	case 3:
		logMsg = "TV - " + deviceName + " was checked " + to_string(checkState());
		TVLogger->writeLine(logMsg);

		delayWithMsg("\n\t" + logMsg, 1500);

		displayMenu();
		break;

		case 4:
			if (checkState() == true) {
					
				if (activeChannel == 0) {
					TVGUI = "\n\tActive Mode is " + channelList[activeChannel] + "\n\n";
					TVMenuGUI->display(TVGUI);
					delayWithMsg("" , 1500);

				}
				
				else
				{
					TVGUI = "\n\tActive Channel is " + channelList[activeChannel] + "\n\n";
					TVMenuGUI->display(TVGUI);


					logMsg = "TV - " + deviceName + " is changed the channel to " + channelList[activeChannel];
					TVLogger->writeLine(logMsg);
					delayWithMsg("", 250);
				}
				

				int channelValue;
				TVGUI = "\n\n\t---Channel List---\n\n";
				TVMenuGUI->display(TVGUI);
				
				for (int i = 1; i < channelList.size(); i++)
				{
					TVGUI = "";
					TVGUI ="\t" + to_string(i) + " -) " + channelList[i] + "\n";
					TVMenuGUI->display(TVGUI);
					delayWithMsg("", 150);
					
				}


				cout << endl;
				
				TVGUI = "\n\tSelect a channel: ";
				TVMenuGUI->display(TVGUI);

				cin >> channelValue;
				selectChannel(channelValue);
				//cout << activeChannel;
				//cout << channelList[activeChannel];
				
				
			}
			else
			{
				TVGUI = "\n\tYou cant change the channel when the TV is off.\n\tFirst please turn on the TV";
				TVMenuGUI->display(TVGUI);
				delayWithMsg("", 1500);
				
			}
			displayMenu();
			break;
		case 5:

			standBy();
			
			TVGUI = "\n\t" + channelList[activeChannel] + " mode is active. \n";
			TVMenuGUI->display(TVGUI);
			delayWithMsg("", 1500);
			

			logMsg = "TV - " + deviceName + " TV was changed to Stand By mode";
			TVLogger->writeLine(logMsg);
			displayMenu();


			break;
		case 6:
			TVGUI = "\n\tController is being shut down";
			TVMenuGUI->display(TVGUI);

			delayWithMsg("", 1500);
			break;

		default:
			TVGUI = "\n\tWrong choice!Please try again";
			TVMenuGUI->display(TVGUI);

			delayWithMsg("", 1500);

			displayMenu();
		}

}


	