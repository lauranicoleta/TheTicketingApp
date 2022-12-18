#include "Locator.h"


Locator::Locator(int noRowsVIPZone, int* noSeatsRowVIPZone, int noRowsStandardZone, int* noSeatsRowStandardZone)
{
	if (noRowsVIPZone > 0 && noSeatsRowVIPZone != nullptr)
	{
		this->noRowsVIPZone = noRowsVIPZone;
		this->noSeatsRowVIPZone = new int[this->noRowsVIPZone];
		for (int i = 0; i <= this->noRowsVIPZone; i++)
		{
			this->noSeatsRowVIPZone[i] = noSeatsRowVIPZone[i];
		}
	}

	if (noRowsStandardZone > 0 && noSeatsRowStandardZone != nullptr)
	{
		this->noRowsStandardZone = noRowsStandardZone;
		this->noSeatsRowStandardZone = new int[this->noRowsStandardZone];
		for (int i = 0; i <= this->noRowsStandardZone; i++)
		{
			this->noSeatsRowStandardZone[i] = noSeatsRowStandardZone[i];
		}
	}

}

Locator::~Locator()
{
	if (this->noSeatsRowVIPZone != nullptr)
		delete[] this->noSeatsRowVIPZone, this->noSeatsRowVIPZone = nullptr;

	if (this->noSeatsRowStandardZone != nullptr)
		delete[] this->noSeatsRowStandardZone, this->noSeatsRowStandardZone = nullptr;
}

Locator::Locator(const Locator& lc)
{
	if (this->noSeatsRowVIPZone != nullptr)
		delete[] this->noSeatsRowVIPZone, this->noSeatsRowVIPZone = nullptr;

	if (lc.noRowsVIPZone > 0 && lc.noSeatsRowVIPZone != nullptr)
	{
		this->noRowsVIPZone = lc.noRowsVIPZone;
		this->noSeatsRowVIPZone = new int[this->noRowsVIPZone];
		for (int i = 0; i <= this->noRowsVIPZone; i++)
		{
			this->noSeatsRowVIPZone[i] = lc.noSeatsRowVIPZone[i];
		}
	}

	if (this->noSeatsRowStandardZone != nullptr)
		delete[] this->noSeatsRowStandardZone, this->noSeatsRowStandardZone = nullptr;

	if (lc.noRowsStandardZone > 0 && lc.noSeatsRowStandardZone != nullptr)
	{
		this->noRowsStandardZone = lc.noRowsStandardZone;
		this->noSeatsRowStandardZone = new int[this->noRowsStandardZone];
		for (int i = 0; i <= this->noRowsStandardZone; i++)
		{
			this->noSeatsRowStandardZone[i] = lc.noSeatsRowStandardZone[i];
		}
	}
}


Locator& Locator::operator=(const Locator& lc)
{
	if (this != &lc)
	{
		if (this->noSeatsRowVIPZone != nullptr)
			delete[] this->noSeatsRowVIPZone, this->noSeatsRowVIPZone = nullptr;

		if (lc.noRowsVIPZone > 0 && lc.noSeatsRowVIPZone != nullptr)
		{
			this->noRowsVIPZone = lc.noRowsVIPZone;
			this->noSeatsRowVIPZone = new int[this->noRowsVIPZone];
			for (int i = 0; i <= this->noRowsVIPZone; i++)
			{
				this->noSeatsRowVIPZone[i] = lc.noSeatsRowVIPZone[i];
			}
		}

		if (this->noSeatsRowStandardZone != nullptr)
			delete[] this->noSeatsRowStandardZone, this->noSeatsRowStandardZone = nullptr;

		if (lc.noRowsStandardZone > 0 && lc.noSeatsRowStandardZone != nullptr)
		{
			this->noRowsStandardZone = lc.noRowsStandardZone;
			this->noSeatsRowStandardZone = new int[this->noRowsStandardZone];
			for (int i = 0; i <= this->noRowsStandardZone; i++)
			{
				this->noSeatsRowStandardZone[i] = lc.noSeatsRowStandardZone[i];
			}
		}
		
		return *this;
	}
}

void Locator::setNoRowsVIPZone(int noRowsVIPZone)
{
	if (noRowsVIPZone != 0)
		this->noRowsVIPZone = noRowsVIPZone;
	else
		this->noRowsVIPZone = 0;
}
int Locator::getNoRowsVIPZone()
{
	return noRowsVIPZone;
}


void  Locator::setNoSeatsRowVIPZone(int noRowsVIPZone, int* noSeatsRowVIPZone)
{
	if (noRowsVIPZone > 0 && noSeatsRowVIPZone != nullptr)
	{
		if (this->noSeatsRowVIPZone != nullptr)
			delete[] this->noSeatsRowVIPZone, this->noSeatsRowVIPZone = nullptr;
		this->noRowsVIPZone = noRowsVIPZone;
		this->noSeatsRowVIPZone = new int[this->noRowsVIPZone];
		for (int i = 0; i <= this->noRowsVIPZone; i++)
		{
			this->noSeatsRowVIPZone[i] = noSeatsRowVIPZone[i];
		}
	}
}
int* Locator::getNoSeatsRowVIPZone()
{
	int* copy = new int[noRowsVIPZone];
	for (int i = 0; i <= noRowsVIPZone; i++)
		copy[i] = noSeatsRowVIPZone[i];
	return copy;
}

void  Locator::setNoRowsStandardZone(int noRowsStandardZone)
{
	if (noRowsStandardZone != 0)
		this->noRowsStandardZone = noRowsStandardZone;
	else
		this->noRowsStandardZone = 0;
}
int  Locator::getNoRowsStandardZone()
{
	return noRowsStandardZone;
}

void  Locator::setNoSeatsRowStandardZone(int noRowsStandardZone, int* noSeatsRowStandardZone)
{
	if (noRowsStandardZone > 0 && noSeatsRowVIPZone != nullptr)
	{
		if (this->noSeatsRowStandardZone != nullptr)
			delete[] this->noSeatsRowStandardZone, this->noSeatsRowStandardZone = nullptr;
		this->noRowsStandardZone = noRowsStandardZone;
		this->noSeatsRowStandardZone = new int[this->noRowsStandardZone];
		for (int i = 0; i <= this->noRowsStandardZone; i++)
		{
			this->noSeatsRowStandardZone[i] = noSeatsRowStandardZone[i];
		}
	}
}
int* Locator::getNoSeatsRowStandardZone()
{
	int* copy = new int[noRowsStandardZone];
	for (int i = 0; i <= noRowsStandardZone; i++)
		copy[i] = noSeatsRowStandardZone[i];
	return copy;
}

static int getNoMaxOfSeats(int noRowsVIPZone, int* noSeatsRowVIPZone, int noRowsStandardZone, int* noSeatsRowStandardZone)
{
	int maxSeats = 0;
	for (int i = 0; i < noRowsVIPZone; i++)
		maxSeats += noSeatsRowVIPZone[i];

	for (int i = 0; i < noRowsStandardZone; i++)
		maxSeats += noSeatsRowStandardZone[i];

	return maxSeats;

}


istream& operator>>(istream& in, Locator& lc)
{
	cout << "enter the distribution of seats of the event hall." << endl;
	cout << "Enter the number of rows for VIP zone: ";
	in >> lc.noRowsVIPZone;
	cout << endl;
	while (lc.noRowsVIPZone < 0)
	{
		cout << "The number of rows must be a value greater than 0." << endl;
		lc.noRowsVIPZone = 0;
		cout << "Enter the number of rows for VIP zone: ";
		in >> lc.noRowsVIPZone;
	}
	cout << endl;
	if (lc.noSeatsRowVIPZone != nullptr)
		delete[] lc.noSeatsRowVIPZone, lc.noSeatsRowVIPZone = nullptr;
	lc.noSeatsRowVIPZone = new int[lc.noRowsVIPZone];
	for (int i = 0; i < lc.noRowsVIPZone; i++)
	{
		cout << "Enter the number of seats for row " << i+1 << ": ";
		in >> lc.noSeatsRowVIPZone[i];
		cout << endl;
	}

	cout << "Enter the number of rows for Standard zone: ";
	in >> lc.noRowsStandardZone;
	cout << endl;
	while (lc.noRowsStandardZone < 0)
	{
		cout << "The number of rows must be a value greater than 0." << endl;
		lc.noRowsStandardZone = 0;
		cout << "Enter the number of rows for Standard zone: ";
		in >> lc.noRowsStandardZone;
	}
	cout << endl;
	if (lc.noSeatsRowStandardZone != nullptr)
		delete[] lc.noSeatsRowStandardZone, lc.noSeatsRowStandardZone = nullptr;

	lc.noSeatsRowStandardZone = new int[lc.noRowsStandardZone];

	for (int i = 0; i < lc.noRowsStandardZone; i++)
	{
		cout << "Enter the number of seats for row " << i+1 << ": ";
		in >> lc.noSeatsRowStandardZone[i];
		cout << endl;
	}

	return in;
}


string Locator::adminPasscodeLocator = "moderatorlocator546";