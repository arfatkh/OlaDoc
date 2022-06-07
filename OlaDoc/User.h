#pragma once
#include "Menu.h"


class User
{
protected:
	const char* DOCTOR_FILE_NAME = "doctors.dat";
	const char* PATIENT_FILE_NAME = "patients.dat";
	char name[30]="";
	char userName[20] = "";
	char password[60] = "";
	char address[150] = "";
	char mobileNo[11] = "";
	char email[30] = "";
	char CNIC[20] = "";
	char dateOfBirth[10] = "";
	char gender[10] = "";
	
	virtual bool IDisAvailable(char* ID) = 0; //Checks if an ID is available
	
	
	

public:
	
	bool setUserName();
	bool UserNameIsAvailable(char* _string);
	bool setPassword();
	bool setCNIC();
	bool CNICAvailable(char* _cnic);//As per requirement both patient and doc databse will be checked
	bool setDOB();
	
	virtual void generateID() = 0;//To generate random ids for users


	char* getName();
	char* getUserName();
	char* getEmail();
	char* getCNIC();
	char* getMobileNo();
	char* getAddress();
	char* getPassword();

};

