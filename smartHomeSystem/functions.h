#ifndef SMART_HOME
#define SMART_HOME

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>


using namespace std;



void delayWithMsg(string, int);

bool checkDatFileName(int, string*);

vector <string> readFromFile(string);

#endif /* SMART_HOME */