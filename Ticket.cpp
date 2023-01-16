#include "Ticket.h"


Ticket::Ticket()
{
	idTicket = ++nextIdTicket;
	int rowChoice = 0;
	int seatChoice = 0;
	string seatCategoryChoice = "";
}


Ticket::Ticket(int rowChoice, int seatChoice, string seatCategoryChoice, Event ev, Client cl) :Ticket()
{
	this->rowChoice = rowChoice;
	this->seatChoice = seatChoice;
	if (seatCategoryChoice == "V" || seatCategoryChoice == "v" || seatCategoryChoice == "S"|| seatCategoryChoice == "s")
		this->seatCategoryChoice = seatCategoryChoice;
	this->ev = ev;
	this->cl = cl;
}


Ticket::Ticket(const Ticket& t)
{
	this->idTicket = t.idTicket;
	if (t.seatCategoryChoice == "V" || t.seatCategoryChoice == "S")
		this->seatCategoryChoice = t.seatCategoryChoice;
	this->rowChoice = t.rowChoice;
	this->seatChoice = t.seatChoice;
	this->ev = t.ev;
	this->cl = t.cl;
}


void Ticket::setSeatCategoryChoice(string seatCategoryChoice)
{
	if (seatCategoryChoice == "V" || seatCategoryChoice == "S")
		this->seatCategoryChoice = seatCategoryChoice;
	else
	{
		this->seatCategoryChoice = ""; cout << "This option is invalid. Please try again!" << endl;
	}
}
string Ticket::getSeatCategoryChoice()
{
	return seatCategoryChoice;
}

void Ticket::setRowChoice(int rowChoice)
{
	if (this->seatCategoryChoice == "V")
	{
		if (rowChoice > 0 && rowChoice <= ev.getLocatorForThisEvent().getNoRowsVIPZone())
			this->rowChoice = rowChoice;
		else
		{
			this->rowChoice = 0; cout << "This row doesn't exist in VIP category." << endl;
		}
	}
	else
	{
		if (rowChoice > 0 && rowChoice <= ev.getLocatorForThisEvent().getNoRowsStandardZone())
			this->rowChoice = rowChoice;
		else
		{
			this->rowChoice = 0; cout << "This row doesn't exist in Standard category." << endl;
		}
	}
}

int Ticket::getRowChoice()
{
	return rowChoice;
}

void Ticket::setSeatChoice(int seatChoice)
{
	if (this->seatCategoryChoice == "V" || this->seatCategoryChoice == "v")
	{
		if (seatChoice > 0 && seatChoice <= ev.getLocatorForThisEvent().getNoSeatsRowVIPZone()[rowChoice-1])
			this->seatChoice = seatChoice;
		else
		{
			this->seatChoice = 0; cout << "This seat doesn't exist on " << rowChoice << "row." << endl;
		}
	}
	else
	{
		if (seatChoice > 0 && seatChoice <= ev.getLocatorForThisEvent().getNoSeatsRowStandardZone()[rowChoice-1])
			this->seatChoice = seatChoice;
		else
		{
			this->seatChoice = 0; cout << "This seat doesn't exist on " << rowChoice << " row." << endl;
		}
	}
}

int Ticket::getSeatChoice()
{
	return seatChoice;
}

Ticket Ticket::operator--(int)
{
	Ticket copy = *this;
	if (getSeatCategoryChoice() == "V" || getSeatCategoryChoice() == "v")
		this->ev.getLocatorForThisEvent().getNoSeatsRowVIPZone()[getRowChoice()]--;
	else
		this->ev.getLocatorForThisEvent().getNoSeatsRowStandardZone()[getRowChoice()]--;

	return copy;
}

void Ticket::setClient(Client cl)
{
	this->cl = cl;
}
Client Ticket::getClient()
{
	return this->cl;
}


void Ticket::setEvent(Event ev)
{
	this->ev = ev;
}
Event Ticket::getEvent()
{
	return this->ev;
}

int Ticket::getTicketId()
{
	return this->idTicket;
}

istream& operator>>(istream& in, Ticket& t)
{
	cout << "Book your ticket! " << endl;
	cout << endl;

	//t.ev.getLocatorForThisEvent().insertBookedVIP(1, 3);
	//t.ev.getLocatorForThisEvent().insertBookedVIP(1, 6);

	//for (auto i : t.ev.getLocatorForThisEvent().bookedVIP)
	//	cout << i.second << " ";
	//cout << endl;

	//t.ev.getLocatorForThisEvent().bookedStandard.insert({ 2,4 });
	//t.ev.getLocatorForThisEvent().bookedStandard.insert({ 2,7 });

	/*for (auto i : t.ev.getLocatorForThisEvent().bookedStandard)
		cout << i.second << " ";
	cout << endl;

	cout << "              *****************       SCREEN       *****************" << endl;
	cout << endl;
	for (int i = 0; i < t.ev.getLocatorForThisEvent().getNoRowsVIPZone(); i++)
	{
		cout << "      VIP Row " << i + 1 << " ";
		for (int j = 1; j <= t.ev.getLocatorForThisEvent().getNoSeatsRowVIPZone()[i]; j++)
		{
			for (auto itr = t.ev.getLocatorForThisEvent().bookedVIP.begin(); itr != t.ev.getLocatorForThisEvent().bookedVIP.end(); itr++)
				if (itr->second == j)
					cout << "[" << 0 << "]" << " ";
			cout << "[" << j << "]" << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < t.ev.getLocatorForThisEvent().getNoRowsStandardZone(); i++)
	{
		cout << " STANDARD Row " << i + 1 << " ";
		for (int j = 1; j <= t.ev.getLocatorForThisEvent().getNoSeatsRowStandardZone()[i]; j++)
		{
			for (auto itr = t.ev.getLocatorForThisEvent().bookedStandard.begin(); itr != t.ev.getLocatorForThisEvent().bookedStandard.end(); itr++)
				if (itr->second == j)
					cout << "[" << 0 << "]" << " ";

			cout << "[" << j << "]" << " ";
		}
		cout << endl;
	}

	cout << endl;*/



	cout << "Enter the seat category. Enter V for VIP zone or S for standard zone.";
	string buffer;
	in >> buffer;
	while (buffer != "V" && buffer != "v" && buffer != "S" && buffer != "s")
	{
		cout << "This option is invalid! Please try again!" << endl;
		cout << "Enter V for VIP zone or S for standard zone." << endl;
		buffer = "";
		in >> buffer;
		cout << endl;
	}
	t.seatCategoryChoice = buffer;
	if (t.seatCategoryChoice == "V" || t.seatCategoryChoice == "v")
		cout << "The price for this category is 40 RON." << endl;
	else
		cout << "The price for this category is 25 RON." << endl;
	cout << endl;

	int bufferRowChoice;
	int bufferSeatChoice;

	cout << "Choose the row: "; in >> bufferRowChoice; cout << endl;

	t.setRowChoice(bufferRowChoice);
	cout << endl;
	while (t.rowChoice == 0)
	{
		cout << "Choose the row: "; in >> bufferRowChoice; cout << endl;

		t.setRowChoice(bufferRowChoice);
	}
	cout << "Choose the seat: "; in >> bufferSeatChoice; cout << endl;
	t.setSeatChoice(bufferSeatChoice);

	while (t.seatChoice == 0)
	{
		cout << "Choose the seat: "; in >> bufferSeatChoice; cout << endl;
		t.setSeatChoice(bufferSeatChoice);
	}
	//if (t.seatCategoryChoice == "V" || t.seatCategoryChoice == "v")
	//{
	//	for (auto itr = t.ev.getLocatorForThisEvent().bookedVIP.find(bufferRowChoice); itr != t.ev.getLocatorForThisEvent().bookedVIP.end(); itr++)
	//	{
	//		while (itr->second == bufferSeatChoice)
	//		{
	//			cout << "This seat is already booked. Try another one!" << endl;
	//			in >> bufferSeatChoice;
	//		}
	//	}
	//	t.rowChoice = bufferRowChoice;
	//	t.seatChoice = bufferSeatChoice;
	//	t.ev.getLocatorForThisEvent().bookedVIP.insert(make_pair(t.rowChoice, t.seatChoice));
	//}
	//else
	//{
	//	for (auto itr = t.ev.getLocatorForThisEvent().bookedStandard.find(bufferRowChoice); itr != t.ev.getLocatorForThisEvent().bookedStandard.end(); itr++)
	//	{
	//		while (itr->second == bufferSeatChoice)
	//		{
	//			cout << "This seat is already booked. Try another one!" << endl;
	//			in >> bufferSeatChoice;
	//		}
	//	}
	//	t.rowChoice = bufferRowChoice;
	//	t.seatChoice = bufferSeatChoice;
	//	t.ev.getLocatorForThisEvent().bookedVIP.insert(make_pair(t.rowChoice, t.seatChoice));
	//	cout << endl;
	//}

	return in;
}

ostream& operator<<(ostream& out, Ticket t)
{
	out << "\n\t\t\t Id is: " << t.idTicket << endl;
	out << "\n\t\t\t Category: ";
	if (t.seatCategoryChoice == "V" || t.seatCategoryChoice == "v")
		out << "VIP" << endl;
	else
		out << "Standard" << endl;
	out << "\n\t\t\t Row: " << t.rowChoice << endl;
	out << "\n\t\t\t Seat Number: " << t.seatChoice << endl;
	return out;
}

int Ticket::nextIdTicket = 653482;
