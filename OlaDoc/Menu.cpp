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
		DoctorRegistration();
		break;
	default:
		cout << "Invalid Choice Select Again !!!" << endl;
		displayRegisterMenu();
		break;

			}


}

bool Menu::PatientRegistration()
{
	char PATIENT_FILE_NAME[20] = "patients.dat";

	Patient _tempPatient;
	//system("cls");
	cout << "\n\t================== PATIENT REGISTRATION PORTAL ==================\n " << endl;
	

	
	//Getting Patients Data
		cout << "Full Name :";
		
		cin.ignore();
		cin.getline(_tempPatient.name, sizeof(_tempPatient.name));
		
		cout << "Choose a Username :";
		
		cin.getline(_tempPatient.userName, sizeof(_tempPatient.userName));
		cin.ignore();

		cout << "Password :";
	
		cin.getline(_tempPatient.password, sizeof(_tempPatient.password));
		cin.ignore();

		//cout << "Confirm password :";
		//cin.ignore();
		//cin.getline(_tempPatient.name, sizeof(_tempPatient.name));

		cout << "CNIC :";
		
		cin.getline(_tempPatient.CNIC, sizeof(_tempPatient.CNIC));
		cin.ignore();


		cout << "Date Of Birth [ddmmyyyy] :";
		cin.getline(_tempPatient.dateOfBirth, sizeof(_tempPatient.dateOfBirth));
		cin.ignore();

		cout << "Gender [ M /F / O(for Others) ] :";
		cin.getline(_tempPatient.gender, sizeof(_tempPatient.gender));
		cin.ignore();

		cout << "Address :";
		cin.getline(_tempPatient.address, sizeof(_tempPatient.address));
		cin.ignore();

		cout << "Mobile No";
		cin.getline(_tempPatient.mobileNo, sizeof(_tempPatient.mobileNo));
		cin.ignore();

		cout << "Email :";
		cin.getline(_tempPatient.email, sizeof(_tempPatient.email));
		cin.ignore();

		cout << "\n====================== Medical Data ===================\n" << endl;
		cout << "Leave Blank If Not Available :\n";
		cin.ignore();

		cout << "Blood Group :";
		cin.getline(_tempPatient.bloodGroup, sizeof(_tempPatient.bloodGroup));
		cin.ignore();


		cout << "Martial Status [ M(arried) / U(nmarried) / D(ivorced) / W(idowed) ] :";
		cin.getline(_tempPatient.martialStatus, sizeof(_tempPatient.martialStatus));
		cin.ignore();


		cout << "Allergies (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.allergies, sizeof(_tempPatient.allergies));
		cin.ignore();

		cout << "Perscriptions (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.prescriptions, sizeof(_tempPatient.prescriptions));
		cin.ignore();

		cout << "Diseases (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.diseases, sizeof(_tempPatient.diseases));
		cin.ignore();

		




	

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