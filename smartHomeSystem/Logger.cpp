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
	
		ofstream myfile; // MY File ad�nda yazd�rma verisi olu�turduk
		myfile.open(fileName , ios::app); // yazdir.txt ad�nda bir metin belgesi oldu�unu s�yl�yoruz ve bunu acmas�n� istiyoruz. (txt dosyas� yok ise kendisi olu�turuyor.)
		myfile << logMsg << " - " << asctime(ti) << endl; // bu metnimizi txt yap��t�r�yoruz , farkl� uzant�larda bunu yapamaya biliriz.
		myfile.close(); // Ac�l�p yazma i�lemi yap�lan txt dosyas� burda close komutu ile kapat�l�yor.
}

