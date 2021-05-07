#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

char ID[14];
char first_name[15];
char last_name[15];
char ticket[6];
char country_name[20];
char destination[15];
char flug_numer[10];
char stay[4];

void insert()
{
	cout << "ENTER YOUR ID: \n ";
	cin >> ID;
	cout << "ENTER THE FIRST NAME: \n ";
	cin >> first_name;
	cout << "ENTER THE LAST NAME: \n ";
	cin >> last_name;
	cout << "ENTER YOUR Ticket:\n";
	cin >> ticket;
	cout << "ENTER YOUR COUNTRY NAME: \n ";
	cin >> country_name;
	cout << "ENTER YOUR Destination: \n ";
	cin >> destination;
	cout << "ENTER YOUR FLUG_NUM:\n";
	cin >> flug_numer;
	cout << "ENTER THE DURATION OF STAY: \n ";
	cin >> stay;
	fstream f;
	f.open("airport.txt", ios::out | ios::app);
	f << ID << "|" << first_name << "|" << last_name << "|" << ticket << "|" << country_name << "|" << destination << "|" << flug_numer << "|" << stay << "\n";




	f.close();


}

void view()
{
	fstream f;
	f.open("airport.txt", ios::in);
	cout << "ID|First Name|Last Name|ticket|Country|Destination|flug_numer|stay\n";
	while (!f.eof())
	{
		f.getline(ID, 15, '|');
		cout << ID << "  ";
		f.getline(first_name, 16, '|');
		cout << first_name << "\t";
		f.getline(last_name, 16, '|');
		cout << last_name << " \t";
		f.getline(ticket, 7, '|');
		cout << ticket << "\t";
		f.getline(country_name, 21, '|');
		cout << country_name << " \t";
		f.getline(destination, 16, '|');
		cout << destination << "\t\t";
		f.getline(flug_numer, 11, '|');
		cout << flug_numer << "\t";
		f.getline(stay, 5, '\n');
		cout << stay << "\n";
	}
	f.close();
}

void search()
{
	char search_key[15];
	char search_key2[15];
	bool flag = false;
	fstream f;
	f.open("airport.txt", ios::in);
	cout << "ENTER SEARCH KEY: \n ";
	cin >> search_key;

	cout << "ENTER SEARCH KEY2: \n ";
	cin >> search_key2;
	while (!f.eof()) {
		f.getline(ID, 15, '|');
		f.getline(first_name, 16, '|');
		f.getline(last_name, 16, '|');
		f.getline(ticket, 7, '|');
		f.getline(country_name, 21, '|');
		f.getline(destination, 16, '|');
		f.getline(flug_numer, 11, '|');
		f.getline(stay, 5, '\n');
		if (strcmp(search_key, ID) == 0 || strcmp(search_key2, first_name) == 0) {
			cout << ID << "\t" << first_name << "\t" << last_name << "\t" << ticket << "\t" << country_name << "\t" << destination << "\t" << flug_numer << "\t" << stay << "\n";
			flag = true;
		}
	}
	if (flag == false)
		cout << "NOT FOUND \n";
}



void update()
{
	bool flag = false;
	char search_key[20];
	int new_ID;
	int new_name;
	fstream f;
	fstream f2("airport2.txt");
	f.open("airport.txt", ios::app | ios::in);
	f2.open("airport2.txt", ios::out | ios::app);

	cout << "ENTER THE ID YOU WANT TO UPDATE\n";
	cin >> search_key;
	while (!f.eof()) {
		f.getline(ID, 15, '|');
		f.getline(first_name, 16, '|');
		f.getline(last_name, 16, '|');
		f.getline(ticket, 7, '|');
		f.getline(country_name, 21, '|');
		f.getline(destination, 16, '|');
		f.getline(flug_numer, 11, '|');
		f.getline(stay, 5, '\n');
		if (strcmp(search_key, ID) == 0) {
			flag = true;
			cout << "ENTER THE NEW ID:\n ";
			cin >> new_ID;
			cout << "ENTER THE NEW name:\n ";
			cin >> new_name;
			f2 << new_ID << "|" << new_name << "|" << last_name << "|" << ticket << "|" << country_name << "|" << destination << flug_numer << "|" << "|" << stay << "\n";
		}
		else {
			f2 << ID << "|" << first_name << "|" << last_name << "|" << ticket << "|" << country_name << "|" << destination << "|" << flug_numer << "|" << stay << "\n";
		}
	}

	if (flag == false)
		cout << "Not found \n";
	else
		cout << "UPDATED \n";
	f.close();
	f2.close();

	remove("airport.txt");
	rename("airport2.txt", "hotel.txt");
}

void del()
{
	fstream f;
	fstream f2("airport2.txt");
	int flag = 0;
	char search_key[20];
	f.open("airport.txt", ios::in | ios::out | ios::app);
	f2.open("airport2.txt", ios::in | ios::out | ios::app);

	cout << "ENTER THE ID YOU WANT TO DELETE\n";
	cin >> search_key;
	while (!f.eof()) {
		f.getline(ID, 15, '|');
		f.getline(first_name, 16, '|');
		f.getline(last_name, 16, '|');
		f.getline(ticket, 7, '|');
		f.getline(country_name, 21, '|');
		f.getline(destination, 16, '|');
		f.getline(flug_numer, 11, '|');
		f.getline(stay, 5, '\n');
		if (strcmp(search_key, ID) == 0)
		{
			flag = 1;
		}
		else {
			f2 << ID << "|" << first_name << "|" << last_name << "|" << ticket << "|" << country_name << "|" << destination << "|" << flug_numer << "|" << stay << "\n";
		}
	}

	f2.close();
	f.close();
	if (flag != 1)
	{
		cout << "NOT FOUND \n";
	}
	else
	{
		cout << "THE RECORD HAS DELETED\n";
	}
	remove("airport.txt");
	rename("airport2.txt", "airport.txt");

}


int main()
{
	int i;

	cout << "\n";
	cout << "\t\t\t\t* WELCOME TO AIRPORT *  " << endl << endl;


	cout << "               _______________________________________________________  \n";
	cout << "              |                   ENTER AN SELECTION                  |\n";
	cout << "              |                                                       | \n";
	cout << "              |     1 : TO INSERT   A NEW Passanger                   | \n";
	cout << "              |     2 : TO DISPLAY ALl passanger RECORDS              | \n";
	cout << "              |     3 : TO SEARCH AN EXISTING passanger               | \n";
	cout << "              |     4 : TO UPDATE DETAILS ABOUT AN EXISTING passanger | \n";
	cout << "              |     5 : TO DELETE AN EXISTING passanger               | \n";
	cout << "              |_______________________________________________________|  \n";
	cout << "\n\n\t\tSelection: ";

	cin >> i;
	cout << "\n";

	switch (i)
	{
	case 1:
		insert();
		break;

	case 2:
		view();
		break;

	case 3:
		search();
		break;

	case 4:
		update();
		break;

	case 5:
		del();
		break;

	default:

		cout << i << " IS NOT A VAILD \n ";
		break;
	}

	return 0;
}
