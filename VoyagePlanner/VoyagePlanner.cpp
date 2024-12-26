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
	cout <<"1. �������� �� ������ ���������" << endl;
	int choice = 0;
	do {
		cout << "�������� �����: ";
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

		}
	} while (choice != 6);
}

void AddVoyage() {
	system("cls");
	cout << "����� ��������� ������ �� ��������?: ";
	int numOfVoyages;
	cin >> numOfVoyages;
	if(currentVoyages + numOfVoyages > MAX_VOYAGES){
		cout << "���� ���������� ����� �� ���������" << endl;
		return;
	}
	cin.ignore();
	for (int i = 0; i < numOfVoyages; i++)
	{
		seaTrips newVoyage;
		newVoyage.voyageID = currentVoyages + 1;
		cout << "�������� �� ������ �������� " << "�" << newVoyage.voyageID << endl;
		cout << "�������: ";
		getline(cin, newVoyage.route);
		cout << "��� �� ������: ";
		getline(cin, newVoyage.shipName);
		cout << "��� �� ��������: ";
		getline(cin, newVoyage.captainName);
		cout << "���� �� ������ ����� �����: ";
		cin >> newVoyage.ticketPriceFirstClass;
		cin.ignore();
		cout << "���� �� ������ ����� �����: ";
		cin >> newVoyage.ticketPriceSecondClass;
		cin.ignore();
		cout << "���� �������: ";
		cin >> newVoyage.amountOfPassengers;
		cin.ignore();
		cout << "���� �� ��������: ";
		getline(cin, newVoyage.departureDate);
		cout << "���� �� ����������: ";
		getline(cin, newVoyage.arrivalDate);
		cout << "������: ";
		getline(cin, newVoyage.status);
		voyages[currentVoyages] = newVoyage;
		currentVoyages++;
	}
	cout << "����������� ���� �������� �������!" << endl;
	system("pause");
}

void returnAllVoyages()
{
	system("cls");
	cout<<"������ ���������: "<<endl;
	for (int i = 0; i < currentVoyages; i++)
	{
		cout << "������ �������� �" << voyages[i].voyageID << endl;
		cout << "�������: " << voyages[i].route << endl;
		cout << "��� �� ������: " << voyages[i].shipName << endl;
		cout << "��� �� ��������: " << voyages[i].captainName << endl;
		cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceFirstClass << endl;
		cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceSecondClass << endl;
		cout << "���� �������: " << voyages[i].amountOfPassengers << endl;
		cout << "���� �� ��������: " << voyages[i].departureDate << endl;
		cout << "���� �� ����������: " << voyages[i].arrivalDate << endl;
		cout << "������: " << voyages[i].status << endl;
	}
	system("pause");
}
void searchByIDRange() {
	system("cls");
	cout << "������� �� ������ ��������� � �������� �� ID" << endl;
	int minID, maxID;
	cout << "�������� ��������� ID: ";
	cin >> minID;
	cout << "�������� ���������� ID: ";
	cin >> maxID;

	bool found = false;
	for (int i = 0; i < currentVoyages; i++) {
		if (voyages[i].voyageID >= minID && voyages[i].voyageID <= maxID) {
			cout << "������ �������� �" << voyages[i].voyageID << endl;
			cout << "�������: " << voyages[i].route << endl;
			cout << "��� �� ������: " << voyages[i].shipName << endl;
			cout << "��� �� ��������: " << voyages[i].captainName << endl;
			cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceFirstClass << endl;
			cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceSecondClass << endl;
			cout << "���� �������: " << voyages[i].amountOfPassengers << endl;
			cout << "���� �� ��������: " << voyages[i].departureDate << endl;
			cout << "���� �� ����������: " << voyages[i].arrivalDate << endl;
			cout << "������: " << voyages[i].status << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "���� ��������� � ���� ��������!" << endl;
	}
	system("pause");
}
void searchVoyagesByDestination() {
	system("cls");
	cout << "������� �� ������ ��������� �� ����������" << endl;
	string destination;
	cout << "�������� ����������: ";
	cin.ignore();
	getline(cin, destination);
	bool found = false;
	for (int i = 0; i < currentVoyages; i++)
		if (voyages[i].route == destination) {
			cout << "������ �������� �" << voyages[i].voyageID << endl;
			cout << "�������: " << voyages[i].route << endl;
			cout << "��� �� ������: " << voyages[i].shipName << endl;
			cout << "��� �� ��������: " << voyages[i].captainName << endl;
			cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceFirstClass << endl;
			cout << "���� �� ������ ����� �����: " << voyages[i].ticketPriceSecondClass << endl;
			cout << "���� �������: " << voyages[i].amountOfPassengers << endl;
			cout << "���� �� ��������: " << voyages[i].departureDate << endl;
			cout << "���� �� ����������: " << voyages[i].arrivalDate << endl;
			cout << "������: " << voyages[i].status << endl;
			found = true;
		}

	if (!found) {
		cout << "���� ��������� �� ���� ����������!" << endl;
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
	// Implement a outside file work structure


int main() {
	Menu();
	return 0;
}