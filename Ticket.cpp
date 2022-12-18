#include "Ticket.h"


Ticket::Ticket()
{
	idTicket = ++nextIdTicket;
	int rowChoice = 0;
	int seatChoice = 0;
	string seatCategoryChoice = "";
}


Ticket::Ticket(string seatCategoryChoice):Ticket()
{
	if (seatCategoryChoice == "V" || seatCategoryChoice == "S")
		this->seatCategoryChoice = seatCategoryChoice;
}


Ticket::Ticket(const Ticket& t)
{
	this->idTicket = t.idTicket;
	if (t.seatCategoryChoice == "V" || t.seatCategoryChoice == "S")
		this->seatCategoryChoice = t.seatCategoryChoice;

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
		if (rowChoice > 0 && rowChoice <= lc.getNoRowsVIPZone())
			this->rowChoice = rowChoice;
		else 
		{
			this->rowChoice = 0; cout << "This row doesn't exist in VIP category." << endl;
		}
	}
	else
	{
		if (rowChoice > 0 && rowChoice <= lc.getNoRowsStandardZone())
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
	if (this->seatCategoryChoice == "V")
	{
		if (seatChoice > 0 && seatChoice <= lc.getNoSeatsRowVIPZone()[rowChoice])
			this->seatChoice = seatChoice;
		else
		{
			this->seatChoice = 0; cout << "This seat doesn't exist on "<<rowChoice<<"." << endl;
		}
	}
	else
	{
		if (seatChoice > 0 && seatChoice <= lc.getNoSeatsRowStandardZone()[rowChoice])
			this->seatChoice = seatChoice;
		else
		{
			this->seatChoice = 0; cout << "This seat doesn't exist on " << rowChoice << "." << endl;
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
		if (getSeatCategoryChoice() == "V")
			this->lc.getNoSeatsRowVIPZone()[getRowChoice()]--;
		else
			this->lc.getNoSeatsRowStandardZone()[getRowChoice()]--;

		return copy;
}



ostream& operator<<(ostream& out, Ticket t)
{
	out << "Id is: " << t.idTicket <<endl;
	out << "Category: " << t.seatCategoryChoice << endl;
	out << "Row: " << t.rowChoice << endl;
	out << "Seat Number: " << t.seatChoice << endl;
	return out;
}

istream& operator>>(istream& in, Ticket& t)
{
	cout << "Enter the seat category. Enter V for VIP zone or S for standard zone.";
	string buffer;
	in >> buffer;
	while (buffer != "V" && buffer != "S")
	{
		cout << "This option is invalid! Please try again!" << endl;
		cout << "Enter V for VIP zone or S for standard zone." << endl;
		buffer = "";
		in >> buffer;
		cout << endl;
	}
	t.seatCategoryChoice = buffer;
	if (t.seatCategoryChoice == "V")
		cout << "The price for this category is 40 RON." << endl;
	else
		cout << "The price for this category is 25 RON." << endl;
	return in;
}

int Ticket::nextIdTicket = 653482;