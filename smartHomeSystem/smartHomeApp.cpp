#include "deviceFactory.h"
#include "functions.h"
#include "menuManager.h"
#include "userInterface.h"

userInterface* userInterface::instance = NULL;
Logger* Logger::instance = NULL;

int main(const int argc, const char* argv[])
{
	int datFileCount = argc-1; // .exe haricindeki argüman sayýsýný alýr. (.dat dosya sayýsý)
	string *datFileNames = new string[datFileCount]; // argümandan gelecek .dat dosylarýnýn isimlerini tutar.

	for (int i = 0; i < datFileCount; i++) { // .dat dosya isimleri için argümanlar hafýzaya alýnýyor.
		datFileNames[i] = argv[i+1];
	}


	vector <Device*> allDevices;
	vector <string> theDatFileLines; // geçerli .dat file ýn satýrlarýný tutar.
	Device* deviceTMP;


	if (datFileCount > 0 && checkDatFileName(datFileCount, datFileNames) == true) { // argüman sayýsý ve dosya isimlendirme formatý kontrol ediliyor.
		for (int i = 0; i < datFileCount; i++) { // .dat dosyalarý tek tek okunuyor ve satýlarýna ayrýlarak geri döndürülüyor.
			theDatFileLines = readFromFile(datFileNames[i]);
			for (int j = 0; j < theDatFileLines.size(); j++) { // her bir satýrýn nesnesi yaratýlýyor ve dönen deðer depolanýyor.
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