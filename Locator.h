#pragma once
//static string va fi parola moderatorului, doar moderatorul poate face modificari de tipul
//stabilirea numarului maxim de locuri, adaugarea evenimentelor, stergerea evenimentelor
#include <iostream>
#include <string>



using namespace std;

class Locator 
{
private:
	static string adminPasscodeLocator;

	int noRowsVIPZone = 0;
	int* noSeatsRowVIPZone = nullptr;

	int noRowsStandardZone = 0;
	int* noSeatsRowStandardZone = nullptr;

public:
	Locator() = default;
	Locator(int noRowsVIPZone, int* noSeatsRowVIPZone, int noRowsStandardZone, int* noSeatsRowStandardZone);
	~Locator();
	Locator(const Locator& lc);
	Locator& operator=(const Locator& lc);

	void setNoRowsVIPZone(int noRowsVIPZone);
	int getNoRowsVIPZone();

	void setNoSeatsRowVIPZone(int noRowsVIPZone, int* noSeatsRowVIPZone);
	int* getNoSeatsRowVIPZone();

	void setNoRowsStandardZone(int noRowsStandardZone);
	int getNoRowsStandardZone();

	void setNoSeatsRowStandardZone(int noRowsStandardZone, int* noSeatsRowStandardZone);
	int* getNoSeatsRowStandardZone();

	static int getNoMaxOfSeats(int noRowsVIPZone, int* noSeatsRowVIPZone, int noRowsStandardZone, int* noSeatsRowStandardZone);

	friend istream& operator>>(istream& in, Locator& lc);
};
