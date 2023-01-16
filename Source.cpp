#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Ticket.h"
#include "Client.h"
#include "Locator.h"
#include "Event.h"

using namespace std;


fstream eventsData;
fstream ticketsData;


int main()
{
	vector<Ticket> vt;
	vector<Event> vev;


	eventsData.open("Events.txt", ios::in | ios::out);
	ticketsData.open("Tickets.txt", ios::in | ios::out);

		//cin >> ev;
		//cin >> lc;
		//ev.setLocatorForThisEvent(lc);
		////vev.push_back(ev);
		//cout << ev;
		//cout << ev.getLocatorForThisEvent();

		//cout << endl;

		//cin >> cl;
		for (int i = 0; i <= 2; i++)
		{
			//Ticket t;
			//t.setClient(cl);
			//t.setEvent(ev);
			//cin >> t;

			//system("CLS");

			//cout << "\n\t\t\t ---------------------------------" << endl;
			//cout << "\n\t\t\t             YOUR TICKET           " << endl;
			//cout << "\n\t\t\t ---------------------------------" << endl;
			//cout << t;
			//cout << "\n\t\t\t Event: " << t.getEvent().getNameOfEvent() << endl;
			//cout << "\n\t\t\t Date of Event: " << t.getEvent().getDateOfEvent() << endl;
			//cout << "\n\t\t\t Full name: " << t.getClient().getFullName() << endl;
			//cout << endl;
			//cout << "\n\t\t\t Thank you for your booking!";
			//cout << endl;

			//Event ev;
			//cin >> ev;
			//vev.push_back(ev);
		}

		/*for (auto itr = vev.begin(); itr != vev.end(); itr++)
		{
			cout<< *itr;
		}

		for (auto itr = vev.begin(); itr != vev.end(); itr++)
		{
			cout << itr->getIdOfEvent();
		}

		for (auto itr = vev.begin(); itr != vev.end(); itr++)
		{
			eventsData << *itr;
		}*/



	/*	for (auto itr = vevN.begin(); itr != vevN.end(); itr++)
		{
			cout<< *itr;
		}*/

	/*for (auto itr = vev.begin(); itr != vev.end(); itr++)
		cout << *itr << endl;*/


	int a=0;

		//Menu
	while (a != 5)
	{
		cout << "\n\t\t\t ----------------------------------";
		cout << "\n\t\t\t     Event Ticket Booking System";
		cout << "\n\t\t\t ----------------------------------";
		cout << "\n\t\t\t\t Welcome!";	 																					//Menu for the user
		cout << "\n\n\t\t\t\t <1> List of Events";
		cout << "\n\t\t\t\t <2> Book A Ticket";
		cout << "\n\t\t\t\t <3> Ticket Information";
		cout << "\n\t\t\t\t <4> Add an Event(only for admins)";
		cout << "\n\t\t\t\t <5> Exit \n\n";
		cout << "\t\t\t\tEnter Your Choice :" << "\t";
		cin >> a;
		switch (a)
		{
		case 1:
			{
				for (auto itr = vev.begin(); itr != vev.end(); itr++)
					cout << *itr << endl;
				break;
			}
		case 2:
		{
			bool foundedId = false;
			Ticket t;
			Client cl;
			cin >> cl;
			t.setClient(cl);
			cout << endl;
			cout << "Enter the Event id: ";
			int id=0;
			cin >> id;
			for (auto itr = vev.begin(); itr != vev.end(); itr++)
			{
				if (itr->getIdOfEvent() == id)
				{
					t.setEvent(*itr);
					foundedId = true;
				}
			}
			if (foundedId == true)
			{
				cout << "The hall of Event looks like: " << endl;
				cout << t.getEvent().getLocatorForThisEvent() << endl;
				cin >> t;
				vt.push_back(t);
				system("CLS");
				cout << "\n\t\t\t ---------------------------------" << endl;
				cout << "\n\t\t\t             YOUR TICKET           " << endl;
				cout << "\n\t\t\t ---------------------------------" << endl;
				cout << t;
				cout << "\n\t\t\t Event: " << t.getEvent().getNameOfEvent() << endl;
				cout << "\n\t\t\t Date of Event: " << t.getEvent().getDateOfEvent() << endl;
				cout << "\n\t\t\t Full name: " << t.getClient().getFullName() << endl;
				cout << endl;
				cout << "\n\t\t\t Thank you for your booking!";
				cout << endl;
			}
			else
			{
				cout << "This Event ID is not a valid one!" << endl;
			}
			break;

		}
		case 3:
		{
			int idT = 0;
			bool foundedId = false;
			cout << "\n\t\t\t Introduce Ticket Id: ";
			cin >> idT;
			cout << endl;
			for (auto itr = vt.begin(); itr != vt.end(); itr++)
			{
				if (itr->getTicketId() == idT)
				{
					cout << "\n\t\t\t ---------------------------------" << endl;
					cout << "\n\t\t\t             YOUR TICKET           " << endl;
					cout << "\n\t\t\t ---------------------------------" << endl;
					cout << *itr;
					cout << "\n\t\t\t Event: " << itr->getEvent().getNameOfEvent() << endl;
					cout << "\n\t\t\t Date of Event: " << itr->getEvent().getDateOfEvent() << endl;
					cout << "\n\t\t\t Full name: " << itr->getClient().getFullName() << endl;
					cout << endl;
					cout << "\n\t\t\t Thank you for your booking!";
					cout << endl;
					foundedId = true;
				}
			}
			if (foundedId == false)
				cout << "This Ticket ID is not a valid one!" << endl;
			break;
		}

		case 4:
		{
			Event ev;
			Locator lc;
			system("CLS");
			cout << "\n\t\t\t Please introduce the admin password: ";
			string buff;
			cin >> buff;
			while (buff != ev.getAdminPasscodeEvent())
			{
				cout << "\n\t\t\t Password is invalid! Please try again!  ";
				cin >> buff;
			}
			system("CLS");
			cin >> ev;
			cin >> lc;
			ev.setLocatorForThisEvent(lc);
			cout << ev;
			cout << ev.getLocatorForThisEvent();
			cout << endl;
			vev.push_back(ev);
			break;

		}
		case 5:
			a = 5;
		}
	}
		ticketsData.close();
		eventsData.close();

	return 0;
}
