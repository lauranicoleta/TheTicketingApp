#include "Event.h"

Event::Event() :idEvent(++nextIdEvent) 
{
	nameOfEvent = nullptr;
	dateOfEvent = "";
};
Event::Event(char* nameOfEvent, string dateOfEvent) : Event()
{
	this->nameOfEvent = new char[strlen(nameOfEvent) + 1];
	strcpy_s(this->nameOfEvent, strlen(nameOfEvent) + 1, nameOfEvent);

	this->dateOfEvent = dateOfEvent;
};
Event::Event(const Event& ev) : idEvent(ev.idEvent) 
{
	if (ev.nameOfEvent != nullptr && strlen(ev.nameOfEvent) > 0)
	{
		this->nameOfEvent = new char[strlen(ev.nameOfEvent) + 1];
		strcpy_s(this->nameOfEvent, strlen(ev.nameOfEvent) + 1, ev.nameOfEvent);
	}

	this->dateOfEvent = ev.dateOfEvent;
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

		return *this;
	}
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
		return true;
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
				return true;
			}
			else if (monthInt < 1 + newtime.tm_mon)
			{
				return false;
			}
			else if ((monthInt == 1 + newtime.tm_mon) && monthInt <= 12) {

				if ((dayInt >= newtime.tm_mday) && dayInt <= 31)
					return true;
				else
				{
					cout << "Invalid day" << endl; return false;
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


ostream& operator<<(ostream& out, Event ev)
{
	out << "Id of Event: " << ev.idEvent << endl;
	out << "Name of event: " << ev.nameOfEvent << endl;
	out << "Date of event: " << ev.dateOfEvent << endl;
	return out;
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
	cout << "Enter the future date of event(YYYY.MM.DD): ";
	string bufferDate;
	in >> bufferDate; 
	while (ev.checkFutureDateOfEvent(bufferDate) == false)
	{
		cout << "This date is invalid, you must enter a future date in order to add a future event." << endl;
		cout << "Enter the future date of event(YYYY.MM.DD): ";
		bufferDate = "";
		in >> bufferDate;
		cout << endl;
		cout << ev.checkFutureDateOfEvent(bufferDate) << endl;
	}
	ev.dateOfEvent = bufferDate;
	cout << "For " << ev.nameOfEvent << " Event ";
	in >> ev.lc;
	return in;
}


string Event::adminPasscodeEvent = "moderatorevent545";
int Event::nextIdEvent = 0;