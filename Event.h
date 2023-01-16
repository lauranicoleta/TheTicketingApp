#pragma once
//Pentru fiecare eveniment exista un vector alocat dinamic ce contine id-urile unice ale biletelor

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#include "Locator.h";

using namespace std;

class Event {
protected:
	static int nextIdEvent;

private:
	static string adminPasscodeEvent;

	char* nameOfEvent;
	const int idEvent;
	string dateOfEvent = "";

	Locator lc;

public:
	Event();
	Event(char* nameOfEvent, string dateOfEvent, Locator lc);
	Event(const Event& ev);
	~Event();
	Event& operator=(const Event& ev);

	void setNameOfEvent(char* nameOfEvent);
	char* getNameOfEvent();

	void setDateOfEvent(string dateOfEvent);
	string getDateOfEvent();

	bool checkFutureDateOfEvent(string dateOfEvent);
	bool operator!();

	string getAdminPasscodeEvent();
	int getIdOfEvent();

	Locator getLocatorForThisEvent();
	void setLocatorForThisEvent(Locator lc);

	friend ostream& operator<<(ostream& out, Event ev);
	friend ofstream& operator<<(ofstream& f, Event ev);
	friend istream& operator>>(istream& in, Event& ev);
};
