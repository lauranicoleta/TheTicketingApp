#pragma once

#include <iostream>
#include <string>

#include "Event.h"
#include "Client.h"

using namespace std;


class Ticket
{
protected:
	static int nextIdTicket;
private:
	int idTicket;
	Event ev;
	Client cl;

	int rowChoice = 0;
	int seatChoice = 0;
	string seatCategoryChoice = "";

public:
	Ticket();
	Ticket(int rowChoice, int seatChoice, string seatCategoryChoice, Event ev, Client cl);
	~Ticket() = default;
	Ticket(const Ticket& t);

	void setRowChoice(int rowChoice);
	int getRowChoice();

	void setSeatChoice(int seatChoice);
	int getSeatChoice();

	void setSeatCategoryChoice(string seatChoice);
	string getSeatCategoryChoice();

	void setClient(Client cl);
	Client getClient();

	void setEvent(Event ev);
	Event getEvent();

	int getTicketId();

	Ticket operator--(int);

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);

};
