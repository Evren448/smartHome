#include "functions.h"


/**
* \brief <h2><b><i>Mesaj opsiyonlu gecikme</i></b></h2>
*
* <p>&emsp;&emsp;Opsiyonel olarak mesaj yazdirarak, eklendigi yerde program akisini verilen milisaniye kadar duraklatir.</p>
*
* \param msg: Mesaj
* \param time: Zaman
*/
void delayWithMsg(string msg, int time) {
	cout << msg;
	chrono::duration<int, milli> timespan(time);
	this_thread::sleep_for(timespan);
}

/**
* \brief <h2><b><i>.dat dosyalari icin format kontrolu</i></b></h2>
*
* <p>&emsp;&emsp;.dat dosyalarinin formatini kontrol eder ve biri bile uygun degil ise false dondurur. Hepsi uygun ise true dondurur.</p>
*
* \param datFileCount: .dat dosyalarinin adedi
* \param datFileNames: .dat dosyalarinin ismi
* \return formatCheck
*/
bool checkDatFileName(int datFileCount, string* datFileNames) {
	bool formatCheck = false; // dosya isimlerinden en az birisinin uygun formatta gelmediði anda bu durumu saklar.

	size_t index;

	for (int i = 0; i < datFileCount; i++) { // format kontrol ediliyor. Direkt return kullanýmlarý yapýlamaz. Yapýlýrsa ilk olumlu durumda herþey olumlu gibi kabul görecektir.
		index = datFileNames[i].find(".dat");

		if (index != string::npos) {
			if (datFileNames[i].size() > 4 && datFileNames[i].size() == index + 4)
				formatCheck = true;
			else {
				formatCheck = false;
				break;
			}
		}
		else {
			formatCheck = false;
			break;
		}
	}

	if (formatCheck)
		return true;
	else
		return false;
}

/**
* \brief <h2><b><i>Dosyadan okuma</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametreyi dosya ismi olarak kullanir ve dosyayi  bulursa okuma gerceklesir. Her satiri vektor icinde ayri ayri tutar ve geriye dondurur.</p>
*
* \param filePath: dosya ismi
* \return fileLines
*/
vector <string> readFromFile(string filePath) {
	vector <string> fileLines;
	ifstream theFile(filePath);
	if (theFile.is_open()) {
		string line;
		while (getline(theFile, line)) { // dosyadaki her satýr tek tek vektöre atýlýyor.
			fileLines.push_back(line);
		}
	}
	else {
		cout << "ERROR! - Unable to open file: " << filePath << endl;
		cout << "The program will be terminated." << endl << endl;
		system("pause");
		exit(0);
	}

	return fileLines;
}