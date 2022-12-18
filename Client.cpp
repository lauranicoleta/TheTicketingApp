#include "Client.h"

Client::Client(string firstName, string lastName, string telephoneNumber, int age, string email)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->telephoneNumber = telephoneNumber;
	this->age = age;
	this->email = email;
};

Client::Client(const Client& cl)
{
	this->firstName = cl.firstName;
	this->lastName = cl.lastName;
	this->telephoneNumber = cl.telephoneNumber;
	this->age = cl.age;
	this->email = cl.email;
};

void Client::setFirstName(string firstName)
{
	this->firstName = firstName;
}

string Client::getFirstName()
{
	return firstName;
}

void Client::setLastName(string lastName)
{
	this->lastName = lastName;
}

string Client::getLastName()
{
	return lastName;
}

void Client::setTelephoneNumber(string telephoneNumber)
{
	this->telephoneNumber = telephoneNumber;
}

string Client::getTelephoneNumber()
{
	return telephoneNumber;
}

void Client::setAge(int age)
{
	this->age = age;
}

int Client::getAge()
{
	return age;
}

bool Client::Email_check(string email)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}

//The \w matches any character in any case any number of times.
//Then the \. | _ matches if a dot or underscore is present 0 or 1 times.
//Then \w again match n characters.
//Then @ matches the @ in the email.
//Then we again check for n charactersand a ‘.’and a word after it, which must be present at least one or more times.

void Client::setEmail(string email)
{
	if (Client::Email_check(email))
		this->email = email;
	else
	{
		this->email = ""; cout << "This email adress is invalid!";
	}
}

string Client::getEmail()
{
	return email;
}

string Client::getFullName()
{
	return this->firstName + " " + this->lastName;
}

bool operator>(Client& cl1, Client& cl2)
{
	return cl1.getFullName() > cl2.getFullName();
}

ostream& operator<<(ostream& out, Client cl) 
{
	out << "First Name: " << cl.firstName << endl;
	out << "Last Name: " << cl.lastName << endl;
	out << "Telephone Number: " << cl.telephoneNumber << endl;
	out << "Email: " << cl.email << endl;
	out << "Age: " << cl.age << endl;

	return out;
}

istream& operator>>(istream& in, Client& cl)
{
	cout << "Enter your first name: ";
	in >> cl.firstName; cout << endl;
	cout << "Enter your last name: ";
	in >> cl.lastName; cout << endl;
	cout << "Enter your telephone number: ";
	in >> cl.telephoneNumber; cout << endl;
	cout << "Enter your email: ";
	string buffer = "";
	in >> buffer;
	while (cl.Email_check(buffer) == 0)
	{
		cout << "This email adress is NOT valid! Please enter a valid one: ";
		buffer = "";
		in >> buffer;
	}
	cout << endl;
	cl.email = buffer;
	cout << "Please enter your age: ";
	in >> cl.age; cout << endl;
	
	return in;
};