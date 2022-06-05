#pragma once
class Menu
{
public:
	void displayMainMenu(); //The Main Menu with Login and Register options
	void displayAdminMenu(); //Special Menu for Admin
	void displayPatientMenu(); //Menu for Patient
	void displayDoctorMenu(); //Menu for Doctors
	void displayLoginMenu(); //Login Menu to take userName and Password

	void displayRegisterMenu(); //Menu for Registring new users
	bool PatientRegistration(); // Specific for patient's Registration.
	bool DoctorRegistration(); //Specific for Doctors's Registration.

};

