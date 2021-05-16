#include "userInterface.h"

/**
* \brief <h2><b><i>Arayuz icin nesne yaratilmasi icin singleton yapinin kontrolu</i></b></h2>
*
* <p>&emsp;&emsp;Daha once bu classtan nesne yaratilip yaratilmadigini kontrol eder. Yaratilmadiysa yaratir ve kendi tipinden bir pointer dondurur. Yaratildiysa zaten bellekte var olani dondurur. </p>
*
* \return instance
*/
userInterface* userInterface::getGUI() {
	if (instance == NULL) {
		instance = new userInterface();
	}
	return instance;
}

/**
* \brief <h2><b><i>Arayuzdeki gosterimler</i></b></h2>
*
* <p>&emsp;&emsp;Arayuze bastiralacaklar buradan yapilir. Boylece herhengi bir degisiklikte sadece buraya mudahele edilir ve ortak bir degisim saglanýr.</p>
*
* \param datLine: 
*/
void userInterface::display(string menuElement) {
	cout << menuElement;
}