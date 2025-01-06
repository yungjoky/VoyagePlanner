#include <string>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void AddVoyage();
void returnAllVoyages();
void searchByIDRange();
void searchVoyagesByDestination();
void orderVoyagesByDestination();
void saveVoyagesToFile();
void readVoyagesFromFileAndPrint();
void moreOptions();
void updateVoyageStatus();
char currentDate[3];
const int MAX_VOYAGES = 100;
const int MAX_ROUTE_CHARS = 50;
const int MAX_SHIP_NAME_CHARS = 30;
const int MAX_CAPTAIN_NAME_CHARS = 50;
const int MAX_DATE_CHARS = 16;
const int MAX_STATUS_CHARS = 50;
struct seaTrips {
	int voyageID = 0;
	char route[MAX_ROUTE_CHARS];
	char shipName[MAX_SHIP_NAME_CHARS];
	char captainName[MAX_CAPTAIN_NAME_CHARS];
	float ticketPriceFirstClass;
	float ticketPriceSecondClass;
	int amountOfPassengers;
	char departureDate[MAX_DATE_CHARS];
	char arrivalDate[MAX_DATE_CHARS];
	char status[MAX_STATUS_CHARS];
};

seaTrips voyages[MAX_VOYAGES];
int currentVoyages = 0;

void Menu() {
	system("cls");
	cout << "Добре дошли в системата за планиране на морски пътувания!" << endl;
	cout << "1. Добавяне на морски пътувания" << endl;
	cout << "2. Извеждане на всички пътувания" << endl;
	cout << "3. Търсене на пътувания в диапазон" << endl;
	cout << "4. Търсене на пътувания по дестинация" << endl;
	cout << "5. Подреждане на пътуванията по дестинация" << endl;
	cout << "6. Запази пътуванията във файл" << endl;
	cout << "7. Изведи пътуванията от файл" << endl;
	cout << "8. Още опции" << endl;
	cout << "9. Актуализиране на пътуване" << endl;
	cout << "0. Изход" << endl;

	int choice = 0;
	do {
		cout << "Изберете опция: ";
		cin >> choice;
		cin.clear();
		cin.ignore();
		switch (choice) {
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
		case 7: readVoyagesFromFileAndPrint();
			break;
		case 8: moreOptions();
			break;
		case 9: updateVoyageStatus();
			break;
		case 0: 
			saveVoyagesToFile();
			cout << "Довиждане!" << endl;
			exit(0);
			
		default: cout << "Невалидна опция!" << endl;
			break;
		}
	} while (choice != 0);
}

void AddVoyage() {
	cout << "Колко пътувания искате да добавите?: ";
	int numOfVoyages;
	cin >> numOfVoyages;
	if (currentVoyages + numOfVoyages > MAX_VOYAGES) {
		cout << "Няма достатъчно място за пътувания" << endl;
		return;
	}
	cin.ignore();
	for (int i = 0; i < numOfVoyages; i++) {
		seaTrips newVoyage;
		newVoyage.voyageID = currentVoyages + 1;
		cout << "Добавяне на морско пътуване №" << newVoyage.voyageID << endl;
		cout << "Маршрут: ";
		cin.getline(newVoyage.route, MAX_ROUTE_CHARS);
		cout << "Име на кораба: ";
		cin.getline(newVoyage.shipName, MAX_SHIP_NAME_CHARS);
		cout << "Име на капитана: ";
		cin.getline(newVoyage.captainName, MAX_CAPTAIN_NAME_CHARS);
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
		cin.getline(newVoyage.departureDate, MAX_DATE_CHARS);
		cout << "Дата на пристигане: ";
		cin.getline(newVoyage.arrivalDate, MAX_DATE_CHARS);
		cout << "Статус: ";
		cin.getline(newVoyage.status, MAX_STATUS_CHARS);
		
		
		bool doesItExist = false;
		for (int j = 0; j < currentVoyages; j++) {
			if ((strcmp(newVoyage.shipName, voyages[j].shipName) == 0 || strcmp(newVoyage.captainName, voyages[j].captainName) == 0) &&
				strcmp(newVoyage.departureDate, voyages[j].arrivalDate) <= 0 &&
				strcmp(newVoyage.arrivalDate, voyages[j].departureDate) >= 0) {
				doesItExist = true;
				break;
			}
		}

		if (doesItExist) {
			cout << "Корабът и/или капитанът вече са в друго пътуване в този период!" << endl;
		}
		else {
			

			cout << "Пътуването беше добавено успешно!" << endl;
			voyages[currentVoyages] = newVoyage;
			currentVoyages++;
		}
		system("pause");
		Menu();
	}
}

void returnAllVoyages() {
	system("cls");
	if (currentVoyages == 0)
	{
		cout << "Няма пътувания!" << endl;
		system("pause");
		Menu();
	}
	else {
		for (int i = 0; i < currentVoyages; i++) {
			cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
				<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
				<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
				<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
			cout << string(200, '-') << endl;
		}
		system("pause");
		Menu();
	}
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
			cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
				<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
				<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
				<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
			cout << string(200, '-') << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Няма пътувания в този диапазон!" << endl;
	}
	system("pause");
	Menu();
}
void searchVoyagesByDestination() {
	system("cls");
	cout << "Търсене на морски пътувания по дестинация" << endl;
	char destination[50];
	cout << "Въведете дестинация: ";
	cin.clear();
	cin.getline(destination, 50);
	
	bool found = false;
	for (int i = 0; i < currentVoyages; i++)
		if (strcmp(voyages[i].route,destination) == 0) {
			cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
				<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
				<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
				<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
			cout << string(200, '-') << endl;
			found = true;
		}

	if (!found) {
		cout << "Няма пътувания до тази дестинация!" << endl;
	}
	system("pause");
	Menu();
}
void orderVoyagesByDestination() {
	system("cls");
	if (currentVoyages == 0)
	{
		cout << "Няма пътувания!" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < currentVoyages; i++) {
		for (int j = i + 1; j < currentVoyages; j++) {
			if (strcmp(voyages[i].route, voyages[j].route) > 0) {
				seaTrips temp = voyages[i];
				voyages[i] = voyages[j];
				voyages[j] = temp;
			}
		}
		
	}
	Menu();
}
void saveVoyagesToFile() {
	ofstream outputfile("voyages.dat", ios::binary);
	if (!outputfile) {
		cerr << "Файлът не може да бъде отворен за запис!" << endl;
		return;
		exit(-1);
	}
	else {
		outputfile.write((const char*)&currentVoyages, sizeof(currentVoyages));
		outputfile.write((const char*)voyages, sizeof(seaTrips) * currentVoyages);
		outputfile.close();
		cout << "Пътуванията бяха записани успешно!" << endl;
		system("pause");
		return;
	}
	
}

void readVoyagesFromFileAndPrint() {
	system("cls");
	ifstream inputfile("voyages.dat", ios::binary);
	if (!inputfile) {
		cerr << "Файлът не може да бъде отворен за четене!" << endl;
		system("pause");
		exit(-1);
	}
	inputfile.read((char*)&currentVoyages, sizeof(currentVoyages));
	inputfile.read((char*)voyages, sizeof(seaTrips) * currentVoyages);
	inputfile.close();
	for (int i = 0; i < currentVoyages; i++) {
		cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
			<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
			<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
			<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
		cout << string(200, '-') << endl;
		
	}
	system("pause");
	Menu();
}
void orderFoundDestinations() {
	for (int i = 0; i < currentVoyages; i++) {
		for (int j = i + 1; j < currentVoyages; j++) {
			if (strcmp(voyages[i].departureDate, voyages[j].departureDate) > 0) {
				seaTrips temp = voyages[i];
				voyages[i] = voyages[j];
				voyages[j] = temp;
			}
		}
	}
}

void findDestinationsByStatus() {
	system("cls");
	orderFoundDestinations();
	bool found = false;
	for (int i = 0; i < currentVoyages; i++) {
		if (strcmp(voyages[i].status, "Завършено") == 0) {
			cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
				<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
				<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
				<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
			cout << string(200, '-') << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Няма завършени пътувания!" << endl;
	}
	system("pause");
	Menu();
}

void sortVoyageByPeriodDescending() {
	for (int i = 0; i < currentVoyages; i++) {
		for (int j = i + 1; j < currentVoyages; j++) {
			if (strcmp(voyages[i].route, voyages[j].route) < 0) {
				seaTrips temp = voyages[i];
				voyages[i] = voyages[j];
				voyages[j] = temp;
			}
		}
	}
}
void findVoyageByCaptainName() {
	system("cls");
	char captainName[MAX_CAPTAIN_NAME_CHARS];
	cout << "Въведете име на капитана: ";
	cin.getline(captainName, MAX_CAPTAIN_NAME_CHARS);
	cout << "Въведете начален период: ";
	char startDate[MAX_DATE_CHARS];
	cin.getline(startDate, MAX_DATE_CHARS);
	cout << "Въведете краен период: ";
	char endDate[MAX_DATE_CHARS];
	cin.getline(endDate, MAX_DATE_CHARS);
	sortVoyageByPeriodDescending();
	bool found = false;
	cout << "Пътуванията в този период са:" << endl;
	for (int i = 0; i < currentVoyages; i++) {
		if (strcmp(captainName, voyages[i].captainName) == 0 && strcmp(voyages[i].departureDate, startDate) >= 0 && strcmp(voyages[i].departureDate, endDate) <= 0) {
			cout << "№" << voyages[i].voyageID << string(2, ' ') << "Маршрут: " << voyages[i].route << string(2, ' ') << "Име на кораба: " << voyages[i].shipName << string(2, ' ') << "Име на капитана: " << voyages[i].captainName << string(2, ' ') << "Цена на билети първа класа: "
				<< voyages[i].ticketPriceFirstClass << string(2, ' ') << "Билети втора класа: " << voyages[i].ticketPriceSecondClass << string(2, ' ') << "Брой пасажери: " << voyages[i].amountOfPassengers << string(2, ' ')
				<< "Дата на тръгване: " << voyages[i].departureDate << string(2, ' ')
				<< "Дата на пристигане: " << voyages[i].arrivalDate << string(2, ' ') << "Статус: " << voyages[i].status << string(2, ' ') << endl;
			cout << string(200, '-') << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Няма пътувания за този капитан в този период!" << endl;
	}
	system("pause");
	Menu();
}
void updateVoyageStatus() {
	int id;
	string choice;
	cout << "Въведете ID на пътуването: ";
	cin >> id;
	cout << "Искате ли да коригирате статуса на пътуването? (да/не)" << endl;
	cin >> choice;
	bool found = false;
	if (choice == "да" || choice == "ДА") {
		for (int i = 0; i < currentVoyages; i++) {
			if (id == voyages[i].voyageID) {
				if (strcmp(voyages[i].status, "В очакване") == 0) {
					found = true;
					cout << "Искате ли да коригирате капитана? (да/не)" << endl;
					cin >> choice;
					if (choice == "да" || choice == "ДА") {
						cout << "Въведете ново име на капитана: ";
						cin.ignore();
						cin.getline(voyages[i].captainName, MAX_CAPTAIN_NAME_CHARS);
					}
					cout << "Искате ли да коригирате броят пасажери? (да/не)" << endl;
					cin >> choice;
					if (choice == "да" || choice == "ДА") {
						cout << "Въведете нов брой пасажери: ";
						cin >> voyages[i].amountOfPassengers;
					}
					cout << "Искате ли да коригирате началната дата (дата на потегляне)? (да/не)" << endl;
					cin >> choice;
					if (choice == "да" || choice == "ДА") {
						cout << "Въведете нова дата на потегляне: ";
						cin.ignore();
						cin.getline(voyages[i].departureDate, MAX_DATE_CHARS);
					}
					cout << "Искате ли да коригирате крайната дата (дата на пристигане)? (да/не)" << endl;
					cin >> choice;
					if (choice == "да" || choice == "ДА") {
						cout << "Въведете нова дата на пристигане: ";
						cin.ignore();
						cin.getline(voyages[i].arrivalDate, MAX_DATE_CHARS);
						if (strcmp(voyages[i].departureDate, voyages[i].arrivalDate) > 0) {
							cout << "Дата на пристигане не може да бъде преди датата на тръгване!" << endl;
							return;
						}
					}
					cout << "Искате ли да коригирате цените на билетите? (да/не)" << endl;
					cin >> choice;
					if (choice == "да" || choice == "ДА") {
						int departureDateInt = atoi(voyages[i].departureDate);
						int currentDateInt = atoi(currentDate);

						if (currentDateInt - 3 <= departureDateInt) {
							cout << "Въведете цени на билетите" << endl;
							cout << "Цена на билети първа класа: ";
							cin >> voyages[i].ticketPriceFirstClass;
							cout << "Цена на билети втора класа: ";
							cin >> voyages[i].ticketPriceSecondClass;
							return;
						}
						else {
							cout << "Остават по - малко от 3 дни до отпътуването, цените не могат да бъдат коригирани." << endl;
						}
					}
				}
				else if (strcmp(voyages[i].status, "В процес на изпълнение") == 0 || strcmp(voyages[i].status, "отминало") == 0) {
					cout << "Пътуването е завършено и не може да бъде актуализирано!" << endl;
					return;
				}
			}
		}
	}
	if (!found) {
		cout << "Няма такова пътуване!" << endl;
	}
	cout << "Искате ли да добавите ново пътуване? (да/не)" << endl;
	cin >> choice;
	if (choice == "да" || choice == "ДА") {
		AddVoyage();
	}

}
void moreOptions() {
	system("cls");
	cout << "Повече опции" << endl;
	cout << "1. Отделяне на завършилите пътувания" << endl;
	cout << "2. Извеждане на пътувания, които са на определен капитан в определен период " << endl;
	cout << "3. Обратно към менюто" << endl;
	int choice;
	do {
		cout << "Изберете опция: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1: findDestinationsByStatus();
			break;
		case 2: findVoyageByCaptainName();
			break;
		case 3: Menu();
			break;
		default: cout << "Невалидна опция!" << endl;
			break;
		}
	} while (choice != 3);
}
void automaticVoyageStatusChanger()
{
	int currentDateInt = atoi(currentDate);

	for (int i = 0; i < currentVoyages; i++)
	{
		int arrivalDateInt = atoi(voyages[i].arrivalDate);
		if (currentDateInt > arrivalDateInt)
		{
			strcpy_s(voyages[i].status, "Завършено");
		}
		else if (currentDateInt >= arrivalDateInt - 3)
		{
			strcpy_s(voyages[i].status, "В процес на изпълнение");
		}
		else
		{
			strcpy_s(voyages[i].status, "В очакване");
		}
	}

}
void readVoyageEntriesFromFileOnly()
{
	ifstream inputfile("voyages.dat", ios::binary);
	inputfile.read((char*)&currentVoyages, sizeof(currentVoyages));
	inputfile.read((char*)voyages, sizeof(seaTrips) * currentVoyages);
	inputfile.close();
}

int main() {
	system("chcp 65001");
	system("cls");
	readVoyageEntriesFromFileOnly();
	cout << "Въведете текущият ден" << endl;
	cin >> currentDate;
	cin.ignore();
	automaticVoyageStatusChanger();
	Menu();
	return 0;
}
