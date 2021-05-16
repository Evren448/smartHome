#include "deviceFactory.h"
#include "functions.h"
#include "menuManager.h"
#include "userInterface.h"

userInterface* userInterface::instance = NULL;
Logger* Logger::instance = NULL;

int main(const int argc, const char* argv[])
{
	int datFileCount = argc-1; // .exe haricindeki arg�man say�s�n� al�r. (.dat dosya say�s�)
	string *datFileNames = new string[datFileCount]; // arg�mandan gelecek .dat dosylar�n�n isimlerini tutar.

	for (int i = 0; i < datFileCount; i++) { // .dat dosya isimleri i�in arg�manlar haf�zaya al�n�yor.
		datFileNames[i] = argv[i+1];
	}


	vector <Device*> allDevices;
	vector <string> theDatFileLines; // ge�erli .dat file �n sat�rlar�n� tutar.
	Device* deviceTMP;


	if (datFileCount > 0 && checkDatFileName(datFileCount, datFileNames) == true) { // arg�man say�s� ve dosya isimlendirme format� kontrol ediliyor.
		for (int i = 0; i < datFileCount; i++) { // .dat dosyalar� tek tek okunuyor ve sat�lar�na ayr�larak geri d�nd�r�l�yor.
			theDatFileLines = readFromFile(datFileNames[i]);
			for (int j = 0; j < theDatFileLines.size(); j++) { // her bir sat�r�n nesnesi yarat�l�yor ve d�nen de�er depolan�yor.
				deviceTMP = deviceFactory::create(theDatFileLines[j]);
				allDevices.push_back(deviceTMP);
			}
			theDatFileLines.clear();
		}
	}
	else {
		cout << endl << "Invalid file name(s) was detected. Please enter the file name(s) in the correct format." << endl << endl << endl;
		exit(0);
	}

	menuManager myDeviceMenu;
	myDeviceMenu.createMenu(allDevices);

	return 0;
}