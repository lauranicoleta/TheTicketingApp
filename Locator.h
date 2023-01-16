#pragma once
//static string va fi parola moderatorului, doar moderatorul poate face modificari de evenimente
#include <iostream>
#include <string>
#include <map>




using namespace std;

class Locator
{
private:
	static string adminPasscodeLocator;

	int noRowsVIPZone = 0;
	int* noSeatsRowVIPZone = nullptr;

	int noRowsStandardZone = 0;
	int* noSeatsRowStandardZone = nullptr;

	//Ticket t;

public:

	multimap<int, int> bookedVIP;
	multimap<int, int> bookedStandard;

	Locator() = default;
	Locator(int noRowsVIPZone, int* noSeatsRowVIPZone, int noRowsStandardZone, int* noSeatsRowStandardZone, multimap<int, int> bookedVIP,
	multimap<int, int> bookedStandard);
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

	void insertBookedVIP(int a, int b);

	/*int& operator[](int index);*/

	friend istream& operator>>(istream& in, Locator& lc);
	friend ostream& operator<<(ostream& out, Locator lc);
};
