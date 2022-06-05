#include "Menu.h"
#include <iostream>
#include <iomanip>

#include <fstream>

#include"OlaDoc.h"
#include "Patient.h"
#include "Doctor.h"



using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;







//Global functons to be removed later
void viewDoctors()
{
	const char *DOCTOR_FILE_NAME = "doctors.dat";
	system("cls");
	cout << "\n\n================= Doctors List ======================\n\n " << endl;
	Doctor D;

	ifstream fin;
	fin.open(DOCTOR_FILE_NAME, std::ios::in | std::ios::binary);

	int x = 0;
	while (fin.read((char*)&D, sizeof(D)))
	{
		cout << "========================================================================\n";
		cout << " Name :" << D.getName() << "\n ID:" << D.getID() << endl;
		cout << "========================================================================\n";

	}


	fin.close();









}
















void Menu::displayMainMenu()
{
	

	cout << " =================== Welcome to OlaDoc ====================" << endl;
	cout << "[1] Login " << endl;
	cout << "[2] Register " << endl;
	cout << "[0] Quit " << endl;

	cout << "====================================\n";
	
	int choice = -1;

		choice = getIntChoice();	
	
		while (choice >= 0)		{



			switch (choice)
			{
			case 1:
				displayLoginMenu();
				break;
			case 2:
				displayRegisterMenu();
				break;
			case 0:
				cout << "Quitting ...\n";
				exit(0);
				break;
			default:							
				cout << "Invalid Choice Select Again!!!" << endl;
				break;
			}

			
			ClearScreen();
			cout << " =================== Welcome to OlaDoc ====================" << endl;
			cout << "[1] Login " << endl;
			cout << "[2] Register " << endl;
			cout << "[0] Quit " << endl;

			choice = getIntChoice();

		}



}
void Menu::displayAdminMenu()
{
	cout << "==================== Oladoc Admin Menu ==================" << endl;


	cout << "[1] Add Doctor \n";
	cout << "[2] View Doctor \n";
	cout << "[3] Delete Doctor \n";
	cout << "[4] Edit Doctor's Data/Schedule\n";
	cout << "[5] View Patient \n";
	cout << "[6] View Appoitments \n";
	cout << "[7] Edit Appoitments \n";

	cout<<"====================================\n";
	
	int choice = -1;

	choice = getIntChoice();

	while (choice > 0) {



		switch (choice)
		{
		case 1:
			viewDoctors();
			break;
			break;		
		case 0:
			cout << "Quitting ...\n";
			exit(0);
			break;
		default:
			ClearScreen();
			cout << "Invalid Choice Select Again!!!" << endl;

			break;
		}

		cout << "==================== Oladoc Admin Menu ==================" << endl;
		cout << "[1] Add Doctor \n";
		cout << "[2] View Doctor \n";
		cout << "[3] Delete Doctor \n";
		cout << "[4] Edit Doctor's Data/Schedule\n";
		cout << "[5] View Patient \n";
		cout << "[6] View Appoitments \n";
		cout << "[7] Edit Appoitments \n";

		cout << "====================================\n";	

		choice = getIntChoice();

	}









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

	displayAdminMenu();



}
void Menu::displayRegisterMenu()
{
	//To clear the screen
	ClearScreen();

	
	cout << "\n================ Registration Menu =================\n" << endl;
	cout << "[1] Register as Patient." << endl;
	cout << "[2] Register as Doctor" << endl;
	cout << "[0] Back to MainMenu" << endl;

	cout << "====================================\n";

	int choice = -1;

	choice = getIntChoice();

	while (choice >= 0) {



		switch (choice)
		{
		case 1:
			PatientRegistration();
			break;

		case 2:
			DoctorRegistration();
			break;
		case 0:
			ClearScreen();
			displayMainMenu();
			
			break;
		default:
			ClearScreen();
			cout << "Invalid Choice Select Again!!!\n\n" << endl;
			break;
		}
		ClearScreen();
		cout << "\n================ Registration Menu =================\n" << endl;
		cout << "[1] Register as Patient." << endl;
		cout << "[2] Register as Doctor" << endl;
		cout << "[0] Quit" << endl;
		cout << "====================================\n";

		choice = getIntChoice();

	}

		

}

bool Menu::PatientRegistration()
{
	char PATIENT_FILE_NAME[20] = "patients.dat";

	Patient _tempPatient;
	ClearScreen();
	cout << "\n\t================== PATIENT REGISTRATION PORTAL ==================\n " << endl;
	

	
	//Getting Patients Data
		cout << "Full Name :";
		cin.getline(_tempPatient.name, sizeof(_tempPatient.name));
		
	
		
		_tempPatient.setUserName();

		_tempPatient.setPassword();

		
	

		//cout << "Confirm password :";
		//cin.ignore();
		//cin.getline(_tempPatient.name, sizeof(_tempPatient.name));

		cout << "CNIC :";
		
		cin.getline(_tempPatient.CNIC, sizeof(_tempPatient.CNIC));


		cout << "Date Of Birth [ddmmyyyy] :";
		cin.getline(_tempPatient.dateOfBirth, sizeof(_tempPatient.dateOfBirth));

		cout << "Gender [ M /F / O(for Others) ] :";
		cin.getline(_tempPatient.gender, sizeof(_tempPatient.gender));

		cout << "Address :";
		cin.getline(_tempPatient.address, sizeof(_tempPatient.address));

		cout << "Mobile No";
		cin.getline(_tempPatient.mobileNo, sizeof(_tempPatient.mobileNo));

		cout << "Email :";
		cin.getline(_tempPatient.email, sizeof(_tempPatient.email));

		cout << "\n====================== Medical Data ===================\n" << endl;
		cout << "Leave Blank If Not Available :\n";
		

		cout << "Blood Group :";
		cin.getline(_tempPatient.bloodGroup, sizeof(_tempPatient.bloodGroup));


		cout << "Martial Status [ M(arried) / U(nmarried) / D(ivorced) / W(idowed) ] :";
		cin.getline(_tempPatient.martialStatus, sizeof(_tempPatient.martialStatus));


		cout << "Allergies (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.allergies, sizeof(_tempPatient.allergies));

		cout << "Perscriptions (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.prescriptions, sizeof(_tempPatient.prescriptions));

		cout << "Diseases (if any) [Seperate with commas(,) ] :";
		cin.getline(_tempPatient.diseases, sizeof(_tempPatient.diseases));

		




	

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

	cout << "Patient "<< _tempPatient.getID() << " Successfully Added."<<endl;

	//Closing the Patient Data File
	fout.close();






}


bool Menu::DoctorRegistration()
{
	char DOCTOR_FILE_NAME[20] = "doctors.dat";

	Doctor _tempDoctor;
	//To clear the screen
	ClearScreen();
	cout << "\n\t================== DOCTOR REGISTRATION PORTAL ==================\n " << endl;


	//Getting Doctors Data
	//cin.ignore(INT_MAX, '\n');
	cout << "Full Name :";
	cin.getline(_tempDoctor.name, sizeof(_tempDoctor.name));
	

	_tempDoctor.setUserName();
	
	_tempDoctor.setPassword();
	

	
	

	//cout << "Confirm password :";
	//cin.ignore();
	//cin.getline(_tempDoctor.name, sizeof(_tempDoctor.name));

	cout << "CNIC :";

	cin.getline(_tempDoctor.CNIC, sizeof(_tempDoctor.CNIC));



	cout << "Gender [ M /F / O(for Others) ] :";
	cin.getline(_tempDoctor.gender, sizeof(_tempDoctor.gender));


	
	cout << "Mobile No :";
	cin.getline(_tempDoctor.mobileNo, sizeof(_tempDoctor.mobileNo));

	
	cout << "Email :";

	cin.getline(_tempDoctor.email, sizeof(_tempDoctor.email));

	cout << "\n====================== Professional Data ===================\n" << endl;
	cout << "Leave Blank If Not Available :\n";

	cout << "Hourly Charge :";
	
	cin >> _tempDoctor.hourlyCharge;
	

	cout << "Academic Degree :";
	cin.ignore(INT_MAX, '\n');
	cin.getline(_tempDoctor.academicDegree, sizeof(_tempDoctor.academicDegree));









	/*	while (true)
		{
			if(strlen(_tempDoctor.name) == 0)
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
	//Opening the Doctor data file
	fout.open(DOCTOR_FILE_NAME, std::ios::app | std::ios::binary);


	//If file fails to open
	if (!fout.is_open())
	{
		cout << "There was a problem trying to open the file [Contact Sys Admin][Error 1] " << endl;
		return false;
	}
	//Writing to the File
	fout.write((char*)&_tempDoctor, sizeof(class Doctor));

	cout << "Doctor " << _tempDoctor.getID() << " Successfully Added." << endl;

	//Closing the Doctor Data File
	fout.close();

}




//Input Validation Fucntions
int Menu::getIntChoice(const char* textToAdd)
{

	int choice = 0;

	cout << textToAdd;
	cin >>std::setw(1) >> choice;

	while (!cin.good())
	{
		//Displaying Error
		cout << "Faulty  Input ! Try Again.\n";


		//Clearing Stream
		cin.clear();
		cin.ignore(INT_MAX,'\n');

		//Taking Input Again;
		cout << textToAdd;
		cin >> choice;

	}

	//Clearing Stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	



	return choice;

}

void Menu::ClearScreen() { system("cls"); }