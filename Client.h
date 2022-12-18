#pragma once

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Client {
private:
	string firstName = "";
	string lastName = "";
	string telephoneNumber = "";
	int age = 0;
	string email = "";

public:
	Client() = default;
	Client(string firstName, string lastName, string telephoneNumber, int age, string email);
	~Client() = default;
	Client(const Client& cl);

	void setFirstName(string firstName);
	string getFirstName();

	void setLastName(string lastName);
	string getLastName();

	void setTelephoneNumber(string telephoneNumber);
	string getTelephoneNumber();

	void setAge(int age);
	int getAge();

	bool Email_check(string email);

	void setEmail(string email);
	string getEmail();

	string getFullName();

	friend bool operator>(Client& cl1, Client cl2);

	friend ostream& operator<<(ostream& out, Client cl);
	friend istream& operator>>(istream& in, Client& t);
};