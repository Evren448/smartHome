#pragma once
#include "Logger.h"
#include "userInterface.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include<fstream>
#include<vector>
#include "functions.h"




#pragma warning(disable : 4996)
using namespace std;
/**
* \brief <h2><b><i>Device class.</i></b></h2>
*
* <p>&emsp;&emsp;Abstract Device Class</p>
*
*
*/
class Device
{
protected:
	/**
	* \brief id attribute
	*/
	int id;
	/**
	* \brief deviceName attribute
	*/
	string deviceName;
	/**
	* \brief port attribute
	*/
	int port;
	/**
	* \brief state attribute
	*/
	bool state;
public:

	Device() {}
	Device(int , string , int );

	const int getID();
	const string getDeviceName();
	const int getPort();

	const bool checkState();
	void on();
	virtual void off()=0;
	virtual void displayMenu()=0;

	virtual ~Device(){}

};
