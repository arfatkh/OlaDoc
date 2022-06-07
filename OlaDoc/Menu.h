#pragma once



class Menu
{
public:

	//friend class Appointment;


	void displayMainMenu(); //The Main Menu with Login and Register options
	void displayAdminMenu(); //Special Menu for Admin

	void displayDoctorMenu(char* DoctorID); //Menu for Doctors
	void displayPatientMenu(char* PatientID); //Menu for Patient

	void displayLoginMenu(); //Login Menu to take userName and Password

	void displayRegisterMenu(); //Menu for Registring new users
	bool PatientRegistration(); // Specific for patient's Registration.
	bool DoctorRegistration(); //Specific for Doctors's Registration.

	//Returns -1 for not found [0 for patient][1 for doctor]
	int checkUserExist(char* _username);


	void ClearScreen();

	//Input validation Fucntions
	int getIntChoice(const char* textToAdd = "Select An option :");


};


