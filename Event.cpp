#include "Event.h"

Event::Event() :idEvent(++nextIdEvent)
{
	nameOfEvent = nullptr;
	dateOfEvent = "";
};
Event::Event(char* nameOfEvent, string dateOfEvent, Locator lc) : Event()
{
	this->nameOfEvent = new char[strlen(nameOfEvent) + 1];
	strcpy_s(this->nameOfEvent, strlen(nameOfEvent) + 1, nameOfEvent);

	this->dateOfEvent = dateOfEvent;

	this->lc = lc;
};
Event::Event(const Event& ev) : idEvent(ev.idEvent)
{
	if (ev.nameOfEvent != nullptr && strlen(ev.nameOfEvent) > 0)
	{
		this->nameOfEvent = new char[strlen(ev.nameOfEvent) + 1];
		strcpy_s(this->nameOfEvent, strlen(ev.nameOfEvent) + 1, ev.nameOfEvent);
	}

	this->dateOfEvent = ev.dateOfEvent;

	this->lc = ev.lc;
};
Event::~Event()
{
	if (this->nameOfEvent != nullptr)
		delete[] this->nameOfEvent, this->nameOfEvent = nullptr;
}
Event& Event::operator=(const Event& ev)
{
	if (this != &ev)
	{
		if (ev.nameOfEvent != nullptr && strlen(ev.nameOfEvent) > 0)
		{
			if (this->nameOfEvent != nullptr)
				delete[] this->nameOfEvent, this->nameOfEvent = nullptr;
			this->nameOfEvent = new char[strlen(ev.nameOfEvent) + 1];
			strcpy_s(this->nameOfEvent, strlen(ev.nameOfEvent) + 1, ev.nameOfEvent);
		}

		this->dateOfEvent = ev.dateOfEvent;
		this->lc = ev.lc;
		return *this;
	}
}

string Event::getAdminPasscodeEvent()
{
	return adminPasscodeEvent;
}

void Event::setNameOfEvent(char* nameOfEvent)
{
	if (nameOfEvent != nullptr && strlen(nameOfEvent) > 0)
	{
		if (this->nameOfEvent != nullptr)
			delete[] this->nameOfEvent, this->nameOfEvent = nullptr;
		this->nameOfEvent = new char[strlen(nameOfEvent) + 1];
		strcpy_s(this->nameOfEvent, strlen(nameOfEvent) + 1, nameOfEvent);
	}
}
char* Event::getNameOfEvent()
{
	char* copy = new char[strlen(this->nameOfEvent) + 1];
	strcpy_s(copy, strlen(this->nameOfEvent) + 1, this->nameOfEvent);

	return copy;
}

void Event::setDateOfEvent(string dateOfEvent)
{
	if (checkFutureDateOfEvent(dateOfEvent) == 1)
		this->dateOfEvent = dateOfEvent;
	else
	{
		cout << "Invalid date."; this->dateOfEvent = "";
	};
}
string Event::getDateOfEvent()
{
	return dateOfEvent;
}

bool Event::checkFutureDateOfEvent(string dateOfEvent)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now); 

	string year = dateOfEvent.substr(0, 4);
	string month = dateOfEvent.substr(5, 2);
	string day = dateOfEvent.substr(8, 2);

	int yearInt = stoi(year);
	int monthInt = stoi(month); //stoi converts a string to int
	int dayInt = stoi(day);

	if (yearInt > (1900 + newtime.tm_year))
	{
		if (monthInt <= 12 && dayInt <= 31)
			return true;
		else
			return false;
	}
	else if (yearInt < (1900 + newtime.tm_year))
	{
		return false;
	}
	else {
		if (yearInt == (1900 + newtime.tm_year))
		{
			//adding 1900 to get the current year
			if (monthInt > 1 + newtime.tm_mon)
			{
				//adding 1 to get the current month
				if (monthInt <= 12)
					return true;
				else
				{
					cout << "Invalid month" << endl; return false;
				}
			}
			else if (monthInt < 1 + newtime.tm_mon)
			{
				return false;
			}
			else {
				if ((monthInt == 1 + newtime.tm_mon)) {

					if ((dayInt >= newtime.tm_mday))
						if(dayInt <= 31)
							return true;
						else
						{
							cout << "Invalid day" << endl; return false;
						}
					else
					{
						cout << "Invalid day" << endl; return false;
					}
				}
			}
		}
	}
}

bool Event::operator!()
{
	if (checkFutureDateOfEvent(this->dateOfEvent) == 0)
		return false;
}

Locator Event::getLocatorForThisEvent()
{
	return this->lc;
}

int Event::getIdOfEvent()
{
	return this->idEvent;
}

void Event::setLocatorForThisEvent(Locator lc)
{
	this->lc = lc;
}


ostream& operator<<(ostream& out, Event ev)
{
	out << "Id of Event: " << ev.idEvent << endl;
	out << "Name of event: " << ev.nameOfEvent << endl;
	out << "Date of event: " << ev.dateOfEvent << endl;
	out << endl;
	return out;
}

ofstream& operator<<(ofstream& f, Event ev)
{
	f << ev.idEvent << endl;
	f << ev.nameOfEvent << endl;
	f << ev.dateOfEvent << endl;
	f << endl;
	return f;
}

istream& operator>>(istream& in, Event& ev)
{
	cout << "Enter the name of Event: ";
	string buffer;
	in >> buffer;
	if (buffer != "")
	{
		if (ev.nameOfEvent != nullptr)
			delete[] ev.nameOfEvent, ev.nameOfEvent = nullptr;
		ev.nameOfEvent = new char[buffer.length() + 1];
		strcpy_s(ev.nameOfEvent, buffer.length() + 1, buffer.c_str());
	}
	cout << "Enter the future date of event: " << endl;
	string bufferDate;
	string bY;
	string bM;
	string bD;
	cout << "Day(DD): "; in >> bD; cout << endl;
	cout << "Month(MM): "; in >> bM; cout << endl;
	cout << "Year(YYYY): "; in >> bY; cout << endl;

	while(bY.length() != 4 || bM.length() != 2 || bD.length() != 2)
	{
		cout << "Invalid date!" << endl;
		cout << "Day(DD): "; in >> bD; cout << endl;
		cout << "Month(MM): "; in >> bM; cout << endl;
		cout << "Year(YYYY): "; in >> bY; cout << endl;
	}
	bufferDate = bY + "." + bM + "." + bD;
	cout << bufferDate << endl << endl;
	while (ev.checkFutureDateOfEvent(bufferDate) == false)
	{
		cout << "This date is invalid, you must enter a future date in order to add a future event." << endl;
		cout << "Enter the future date of event(YYYY.MM.DD): ";
		bufferDate = "";
		cout << "Day(DD): "; in >> bD; cout << endl;
		cout << "Month(MM): "; in >> bM; cout << endl;
		cout << "Year(YYYY): "; in >> bY; cout << endl;
		bufferDate = bY + "." + bM + "." + bD;
		cout << endl;
	}

	ev.dateOfEvent = bufferDate;
	return in;
}


string Event::adminPasscodeEvent = "moderatorevent545";
int Event::nextIdEvent = 0;
