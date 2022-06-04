#include "Menu.h"
#include <iostream>


using std::cout;
using std::endl;
using std::cin;




void Menu::displayMainMenu()
{
	cout << "Welcome to OlaDoc" << endl;
	cout << "1. Login " << endl;
	cout << "2. Register " << endl;
	cout << "::> ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		displayLoginMenu();
		break;
	case 2:
		displayRegisterMenu();
		break;
	default:
		cout << "Invalid Choice Select Again" << endl;
		displayMainMenu();
		break;
	}
	



}
void Menu::displayAdminMenu()
{
	cout << "Oladoc Admin Menu" << endl;


}
void Menu::displayPatientMenu()
{
	cout << "Oladoc Patient Menu" << endl;



}

void Menu::displayDoctorMenu()
{
	cout << "Oladoc Doctor Menu" << endl;



}

void Menu::displayLoginMenu()
{
	cout << "Login Menu" << endl;



}
void Menu::displayRegisterMenu()
{
	cout << "Registration Menu" << endl;


}