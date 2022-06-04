#include "Menu.h"
#include <iostream>
#include <fstream>
#include "Patient.h"


using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;




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
	int choice;
	cout << "\n================ Registration Menu =================\n" << endl;
	cout << "1- Register as Patient." << endl;
	cout << "2- Register as Doctor" << endl;
	cout << "Select an Option ::> ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		PatientRegistration();
		break;

	case 2:
		//DoctorRegistration();
		break;
	default:
		cout << "Invalid Choice Select Again !!!" << endl;
		displayRegisterMenu();
		break;

		break;
	}


}

bool Menu::PatientRegistration()
{
	char PATIENT_FILE_NAME[20] = "patients.dat";

	Patient _tempPatient;
	//system("cls");
	cout << "\n\t================== PATIENT REGISTRATION PORTAL ==================\n " << endl;
	
	

		cout << "Full Name :";
		cin.ignore();
		cin.getline(_tempPatient.name, sizeof(_tempPatient.name));

	

	/*	while (true)
		{
			if(strlen(_tempPatient.name) == 0)
			{ 
				cout << "Please enter a valid name!" << endl;
				cout << "Full Name :";
		
				
			
			}
			else
			{
				break;
			}
			
		}
	*/


	ofstream fout;
	//Opening the Patient data file
	fout.open(PATIENT_FILE_NAME, std::ios::app | std::ios::binary);


	//If file fails to open
	if (!fout.is_open())
	{
		cout << "There was a problem trying to open the file [Contact Sys Admin][Error 1] " << endl;
		return false;
	}
	//Writing to the File
	fout.write((char*)&_tempPatient, sizeof(class Patient));

	cout << "Patient Successfully Added."<<endl;

	//Closing the Patient Data File
	fout.close();






}