#include "Logger.h"
/**
* \brief <h2><b><i>getInstance fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;Singleton Pattern ile olusturulmus sadece tek bir instance olmasini sagliyor. k</p>
*
* \return instance
*
*/
Logger* Logger::getInstance() {
	if (instance == NULL) {
		instance = new Logger();
	}
	return instance;
}
/**
* \brief <h2><b><i>writeLine fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;gonderilen bir stringe gore log dosyasini zamanla birlikte tutar.</p>
*
* \param logMsg: log dosyasina yazilacak mesaji tutar.
*
*/
void Logger::writeLine(string logMsg) {

	
	

		// Declaring argument for time() 
		time_t tt;
	
		// Declaring variable to store return value of 
		// localtime() 
		struct tm* ti;
	
		// Applying time() 
		time(&tt);
	
		// Using localtime() 
		ti = localtime(&tt);
	
		ofstream myfile; // MY File adýnda yazdýrma verisi oluþturduk
		myfile.open(fileName , ios::app); // yazdir.txt adýnda bir metin belgesi olduðunu söylüyoruz ve bunu acmasýný istiyoruz. (txt dosyasý yok ise kendisi oluþturuyor.)
		myfile << logMsg << " - " << asctime(ti) << endl; // bu metnimizi txt yapýþtýrýyoruz , farklý uzantýlarda bunu yapamaya biliriz.
		myfile.close(); // Acýlýp yazma iþlemi yapýlan txt dosyasý burda close komutu ile kapatýlýyor.
}

