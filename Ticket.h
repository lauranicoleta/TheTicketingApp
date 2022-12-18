#pragma once

#include <iostream>
#include <string>

#include "Locator.h"


using namespace std;


class Ticket
{
protected:
	static int nextIdTicket;
private:
	int idTicket;
	Locator lc;
	
	int rowChoice = 0;
	int seatChoice = 0;
	string seatCategoryChoice = "";

public:
	Ticket();
	Ticket(string seatCategoryChoice);
	~Ticket() = default;
	Ticket(const Ticket& t);

	void setRowChoice(int rowChoice);
	int getRowChoice();

	void setSeatChoice(int seatChoice);
	int getSeatChoice();

	void setSeatCategoryChoice(string seatChoice);
	string getSeatCategoryChoice();

	Ticket operator--(int);

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);

};
