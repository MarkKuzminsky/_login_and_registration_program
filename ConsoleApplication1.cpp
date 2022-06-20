#include <iostream>
#include <fstream>

using namespace std;

bool checkForDuplicate(const string USERS_DB, string mail)
{
	ifstream fin(USERS_DB);

	// Declare counter which shows duplicates in DB
	int counter = 0;
	string str;

	// Make while loop to search duplicates in users.txt
	while (fin.eof())
	{
		if (mail == str)
		{
			counter += 1;
		}
	}

	// Return true if duplicate are found
	if (counter >= 1)
	{
		return true;
	}

	// Return false if no duplicate
	else
	{
		return false;
	}
}

void login(const string USERS_DB)
{
	ifstream fin(USERS_DB);

	// Ask for user's mail
	cout << "enter your mail: ";
	string mail;
	cin >> mail;

	// If checkForDuplicate is true, then we are logging user
	if (checkForDuplicate(USERS_DB, mail))
	{
		cout << "you succesfully logged in" << endl;
		fin.close();
	}
	
	// if users.txt don't have user's mail, we raise error
	else
	{
		cout << "this email has already taken" << endl;
		fin.close();
	}

}

void registr(const string USERS_DB)
{
	ofstream fout(USERS_DB, ios::app);
	
	// Ask for user's mail
	cout << "enter your mail: ";
	string mail;
	cin >> mail;

	// if checkForDuplicate is false, we add new user
	if (!checkForDuplicate(USERS_DB, mail))
	{
		// Add user in users.txt
		fout << mail << endl;
		cout << "you succesfully registered" << endl;
		fout.close();
	}

	// If user's mail have duplicate we raise "Error"
	else
	{
		cout << "this email is already registered. Try again" << endl;
		fout.close();
	}
}

int main()
{
	// Declare file with users data
	const string USERS_DB = "users.txt";

	while (true)
	{
		cout << "Login or register: ";

		string choice;
		cin >> choice;

		if (choice == "login")
		{
			login(USERS_DB);
			return 0;
		}

		if (choice == "register")
		{
			registr(USERS_DB);
			return 0;
		}

		else
		{
			cout << "invalid option" << endl;
		}
	}
}