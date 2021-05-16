#pragma once
#include <iostream>
#include <string>

using namespace std;


/**
* \brief <h2><b><i>Arayuz olusturucu (Singleton)</i></b></h2>
*
* <p>&emsp;&emsp;Arayuzun olusturulmasý sirasinda kullanilacak ve sadece tek bir nesnesi olusturulacak sinif.</p>
*/
class userInterface {
private:
	/**
	* \brief instance attribute
	*/
	static userInterface* instance;
	userInterface(){}

public:
	static userInterface* getGUI();
	void display(string);
};