#include <string>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;
void AddVoyage();
void returnAllVoyages();
void searchByIDRange();
void searchVoyagesByDestination();
void orderVoyagesByDestination();
void saveVoyagesToFile();
void readVoyagesFromFile();


struct seaTrips {
	int voyageID = 0;
	string route = "";
	string shipName = "";
	string captainName = "";
	float ticketPriceFirstClass = 0;
	float ticketPriceSecondClass = 0;
	int amountOfPassengers = 0;
	string departureDate = "";
	string arrivalDate = "";
	string status = "";
};
const int MAX_VOYAGES = 100;
seaTrips voyages[MAX_VOYAGES];
int currentVoyages = 0;

void Menu() {
	system("chcp 1251");
	system("cls");
	cout <<"1. Добавяне на морски пътувания" << endl;
	int choice = 0;
	do {
		cout << "Изберете опция: ";
		cin >> choice;
		switch(choice){
		case 1: AddVoyage(); 
			break;
		case 2: returnAllVoyages(); 
			break;
		case 3: searchByIDRange(); 
			break;
		case 4: searchVoyagesByDestination();
			break;
		case 5: orderVoyagesByDestination(); 
			break;
		case 6: saveVoyagesToFile();
			break;
		case 7: readVoyagesFromFile();
			break;
		default: cout << "Невалидна опция!" << endl;
			break;

		}
	} while (choice != 8);
}

void AddVoyage() {
	system("cls");
	cout << "Колко пътувания искате да добавите?: ";
	int numOfVoyages;
	cin >> numOfVoyages;
	if(currentVoyages + numOfVoyages > MAX_VOYAGES){
		cout << "Няма достатъчно място за пътувания" << endl;
		return;
	}
	cin.ignore();
	for (int i = 0; i < numOfVoyages; i++)
	{
		seaTrips newVoyage;
		newVoyage.voyageID = currentVoyages + 1;
		cout << "Добавяне на морско пътуване " << "№" << newVoyage.voyageID << endl;
		cout << "Маршрут: ";
		getline(cin, newVoyage.route);
		cout << "Име на кораба: ";
		getline(cin, newVoyage.shipName);
		cout << "Име на капитана: ";
		getline(cin, newVoyage.captainName);
		cout << "Цена на билети първа класа: ";
		cin >> newVoyage.ticketPriceFirstClass;
		cin.ignore();
		cout << "Цена на билети втора класа: ";
		cin >> newVoyage.ticketPriceSecondClass;
		cin.ignore();
		cout << "Брой пътници: ";
		cin >> newVoyage.amountOfPassengers;
		cin.ignore();
		cout << "Дата на тръгване: ";
		getline(cin, newVoyage.departureDate);
		cout << "Дата на пристигане: ";
		getline(cin, newVoyage.arrivalDate);
		cout << "Статус: ";
		getline(cin, newVoyage.status);
		voyages[currentVoyages] = newVoyage;
		currentVoyages++;
	}
	cout << "Пътуванията бяха добавени успешно!" << endl;
	system("pause");
}

void returnAllVoyages()
{
	system("cls");
	cout<<"Всички пътувания: "<<endl;
	for (int i = 0; i < currentVoyages; i++)
	{
		cout << "Морско пътуване №" << voyages[i].voyageID << endl;
		cout << "Маршрут: " << voyages[i].route << endl;
		cout << "Име на кораба: " << voyages[i].shipName << endl;
		cout << "Име на капитана: " << voyages[i].captainName << endl;
		cout << "Цена на билети първа класа: " << voyages[i].ticketPriceFirstClass << endl;
		cout << "Цена на билети втора класа: " << voyages[i].ticketPriceSecondClass << endl;
		cout << "Брой пътници: " << voyages[i].amountOfPassengers << endl;
		cout << "Дата на тръгване: " << voyages[i].departureDate << endl;
		cout << "Дата на пристигане: " << voyages[i].arrivalDate << endl;
		cout << "Статус: " << voyages[i].status << endl;
	}
	system("pause");
}
void searchByIDRange() {
	system("cls");
	cout << "Търсене на морски пътувания в интервал от ID" << endl;
	int minID, maxID;
	cout << "Въведете минимално ID: ";
	cin >> minID;
	cout << "Въведете максимално ID: ";
	cin >> maxID;

	bool found = false;
	for (int i = 0; i < currentVoyages; i++) {
		if (voyages[i].voyageID >= minID && voyages[i].voyageID <= maxID) {
			cout << "Морско пътуване №" << voyages[i].voyageID << endl;
			cout << "Маршрут: " << voyages[i].route << endl;
			cout << "Име на кораба: " << voyages[i].shipName << endl;
			cout << "Име на капитана: " << voyages[i].captainName << endl;
			cout << "Цена на билети първа класа: " << voyages[i].ticketPriceFirstClass << endl;
			cout << "Цена на билети втора класа: " << voyages[i].ticketPriceSecondClass << endl;
			cout << "Брой пътници: " << voyages[i].amountOfPassengers << endl;
			cout << "Дата на тръгване: " << voyages[i].departureDate << endl;
			cout << "Дата на пристигане: " << voyages[i].arrivalDate << endl;
			cout << "Статус: " << voyages[i].status << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Няма пътувания в този диапазон!" << endl;
	}
	system("pause");
}
void searchVoyagesByDestination() {
	system("cls");
	cout << "Търсене на морски пътувания по дестинация" << endl;
	string destination;
	cout << "Въведете дестинация: ";
	cin.ignore();
	getline(cin, destination);
	bool found = false;
	for (int i = 0; i < currentVoyages; i++)
		if (voyages[i].route == destination) {
			cout << "Морско пътуване №" << voyages[i].voyageID << endl;
			cout << "Маршрут: " << voyages[i].route << endl;
			cout << "Име на кораба: " << voyages[i].shipName << endl;
			cout << "Име на капитана: " << voyages[i].captainName << endl;
			cout << "Цена на билети първа класа: " << voyages[i].ticketPriceFirstClass << endl;
			cout << "Цена на билети втора класа: " << voyages[i].ticketPriceSecondClass << endl;
			cout << "Брой пътници: " << voyages[i].amountOfPassengers << endl;
			cout << "Дата на тръгване: " << voyages[i].departureDate << endl;
			cout << "Дата на пристигане: " << voyages[i].arrivalDate << endl;
			cout << "Статус: " << voyages[i].status << endl;
			found = true;
		}

	if (!found) {
		cout << "Няма пътувания до тази дестинация!" << endl;
	}
	system("pause");
}
void orderVoyagesByDestination() {
	system("cls");
	for (int i = 0; i < currentVoyages; i++) {
		for (int j = i + 1; j < currentVoyages; j++) {
			if (voyages[i].route > voyages[j].route) {
				seaTrips temp = voyages[i];
				voyages[i] = voyages[j];
				voyages[j] = temp;
			}
		}
	}
	Menu();

}
void saveVoyagesToFile()
{
    ofstream outputfile("voyages.dat", ios::binary);
    if (!outputfile) {
        cerr << "Файлът не може да бъде отворен за запис!" << endl;
        return;
    }
    outputfile.write((const char*)&currentVoyages, sizeof(currentVoyages));
    outputfile.write((const char*)voyages, sizeof(seaTrips) * currentVoyages);
    outputfile.close();
}

void readVoyagesFromFile()
{
    ifstream inputfile("voyages.dat", ios::binary);
    if (!inputfile) {
        cerr << "Файлът не може да бъде отворен за четене!" << endl;
        return;
    }
    inputfile.read((char*)&currentVoyages, sizeof(currentVoyages));
    inputfile.read((char*)voyages, sizeof(seaTrips) * currentVoyages);
    inputfile.close();
    for (int i = 0; i < currentVoyages; i++) {
        cout << "Морско пътуване №" << voyages[i].voyageID << endl;
        cout << "Маршрут: " << voyages[i].route << endl;
        cout << "Име на кораба: " << voyages[i].shipName << endl;
        cout << "Име на капитана: " << voyages[i].captainName << endl;
        cout << "Цена на билети първа класа: " << voyages[i].ticketPriceFirstClass << endl;
        cout << "Цена на билети втора класа: " << voyages[i].ticketPriceSecondClass << endl;
        cout << "Брой пътници: " << voyages[i].amountOfPassengers << endl;
        cout << "Дата на тръгване: " << voyages[i].departureDate << endl;
        cout << "Дата на пристигане: " << voyages[i].arrivalDate << endl;
        cout << "Статус: " << voyages[i].status << endl;
    }
    system("pause");
}



int main() {
	Menu();
	return 0;
}
