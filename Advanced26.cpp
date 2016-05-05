#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void enterCity();
void searchZIP();
int main() {
	int option = 0;
	do {
		cout << "1: Enter a New City" << '\n'
			 << "2: Search By ZIP Code" << '\n'
			 << "3: Exit" << '\n'
			 << "------ ";
		cin >> option;
		switch (option) {
			case 1:
				enterCity();
				cout << '\n';
				break;
			case 2:
				searchZIP();
				cout << '\n';
				break;
			case 3:
				return 0;
				break;
			default:
				break;
			
		}
	} while (true);
}
void enterCity(){
	string name = "";
	string zip = "";
	fstream addPerson;
	addPerson.open("Advanced26.txt", ios::out | ios::app);
	if (addPerson.is_open()){
		cout << "Please enter the city's name (3 to exit): ";
		cin.ignore();
		getline(cin, name);
		while (name != "3") {
			cout << "Please enter the ZIP code for " << name << ": ";
			cin >> zip;
			addPerson << name << "#" << zip << '\n';
			cout << "Please enter the city's name (3 to exit): ";
			cin.ignore();
			getline(cin, name);
		}
	}else {
		cout << "Error Openning file." << '\n';
	}
	addPerson.close();
}
void searchZIP(){
	string city = "";
	string zip = "";
	string search = "";
	bool i = true;
	fstream searchRead;
	searchRead.open("Advanced26.txt", ios::in);
	if (searchRead.is_open()) {
		cout << "Please enter the ZIP code you would like to search (3 to exit): ";
		cin >> search;
		while (search != "3") {
			if (!searchRead.is_open()) {
				searchRead.open("Advanced26.txt", ios::in);
			}
			while (!searchRead.eof()) {
				getline(searchRead >> ws, city, '#');
				searchRead >> zip;
				if (search == zip && i) {
					cout << "The city with the ZIP code of " << search << " is:" << '\n' << city << '\n';
					i = false;
				}
			}
			if (i) {
				cout << "There are no Cities with the ZIP code of " << search << endl;
			}
			cout << "Please enter the ZIP code you would like to search (3 to exit): ";
			cin >> search;
			i = true;
			searchRead.close();
		}
	}else {
		cout << "Error Openning file." << '\n';
	}
}