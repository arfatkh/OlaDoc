#include "User.h"
#include "Patient.h"
#include "Doctor.h"

#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>



//Getters For User
char* User::getName(){return name;}
char* User::getUserName() { return userName; }
char* User::getEmail(){return email;}
char* User::getMobileNo(){return mobileNo;}
char* User::getAddress(){return address;}
char* User::getPassword(){return password;}



//bool User::isAvailable(char* ID)
//{
//	
//	if (ID[0] == 'P')//Check Patient
//	{
//
//		Patient P;
//		std::ifstream fin;
//		fin.open("patients.dat", std::ios::in | std::ios::binary);
//		
//		while (fin.read((char*)&P, sizeof(P)))
//		{
//
//			if (strcmp(P.getID(), ID))
//				return false;
//
//
//
//		}
//		fin.close();
//
//		return true;
//
//
//
//
//
//
//
//	}
//	else if (ID[0] == 'D')//Check Doctor
//	{
//
//
//
//	}
//
//
//
//
//
//}

bool User::setUserName()
{

	char _tempUsername[20];

	std::cout << "Choose a Username :";
	std::cin.getline(_tempUsername, sizeof(_tempUsername));

	/*while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Username cant be larger than 20 characters!!!!" << std::endl;
		std::cout << "Choose a Username [Anything after space will be ignored]  :";
		std::cin.getline(_tempUsername, sizeof(_tempUsername));

	}
		*/


	
	//std::cin.ignore(1000, '\n');



	while (!UserNameIsAvailable(_tempUsername))
	{
		std::cout << "Username Already Exists!!\n";

		//std::cin.ignore(1000, '\n');


		std::cout << "Choose a Username  :";
		std::cin.getline(_tempUsername, sizeof(_tempUsername));


	}

	strcpy_s(userName, _tempUsername);

	return true;

}


bool User::UserNameIsAvailable(char* _string)
{

	const char* DOCTOR_FILE_NAME = "doctors.dat";
	const char* PATIENT_FILE_NAME = "patients.dat";
	


	//Check in doctors Data
	Doctor D;
	std::ifstream fin;
	fin.open(DOCTOR_FILE_NAME, std::ios::in | std::ios::binary);

	while (fin.read((char*)&D, sizeof(D)))
	{

		if (!strcmp(D.getUserName(), _string))
			return false;
	}

	fin.close();



	//Check in Patients Data
	Patient P;

	fin.open(PATIENT_FILE_NAME, std::ios::in | std::ios::binary);

	while (fin.read((char*)&P, sizeof(P)))
	{

		if (!strcmp(P.getUserName(), _string))
			return false;



	}

	fin.close();




	return true;





}


bool User::setPassword()
{
	char _tempPassword[60];




	//Check length
	bool LenCheck = false;
	bool UpperCheck = false;
	bool LowerCheck = false;
	bool SpecialCharCheck = false;
	bool DigitCheck = false;



	do
	{

		LenCheck = false;
		UpperCheck = false;
		LowerCheck = false;
		SpecialCharCheck = false;
		DigitCheck = false;

		std::cout << "Choose a Password :";
		std::cin.getline(_tempPassword, sizeof(_tempPassword));




		//Checking 8 digit minimun length
		LenCheck = strlen(_tempPassword) > 8 ? true : false;

		//Range based for loop
		//Checking lowercase
		for (char ch : _tempPassword)
		{
			if (ch == 0)
				break;
			if (ch >= 97 && ch <= 122)
			{
				LowerCheck = true;
				break;
			}


		}


		//Checking uppercase
		for (char ch : _tempPassword)
		{
			if (ch == 0)
				break;
			if (ch >= 65 && ch <= 90)
			{
				UpperCheck = true;
				break;
			}

		}





		//Checking digit
		for (char& ch : _tempPassword)
		{
			if ((ch >= '0' && ch <= '9'))
			{
				DigitCheck = true;
				break;
			}


		}

		//Special Character Check

		for (char& ch : _tempPassword)
		{
			if (ch == 0)
				break;
			// Ascii Special char ARanges 32–47 / 58–64 / 91–96 / 123–126
			if ((ch >= 32 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126))
			{
				SpecialCharCheck = true;
				break;
			}


		}
		if(!(LenCheck && UpperCheck && LowerCheck && SpecialCharCheck && DigitCheck))
		std::cout << "--------------------------------------\n";
		if (!LenCheck) std::cout << "Password must be atleast 8 characters long!.\n";
		if (!UpperCheck) std::cout << "Password must contain atleast 1 UpperCase character!.\n";
		if (!LowerCheck) std::cout << "Password must contain atleast 1 LowerCase character!.\n";
		if (!DigitCheck) std::cout << "Password must contain atleast 1 Digit!.\n";
		if (!SpecialCharCheck) std::cout << "Password must contain atleast 1 Special character!.\n";
		if (!(LenCheck && UpperCheck && LowerCheck && SpecialCharCheck && DigitCheck))
			std::cout << "--------------------------------------\n";






	} while (!(LenCheck && UpperCheck && LowerCheck && SpecialCharCheck && DigitCheck));

	char reEnterPass[60];
	bool passMatch = true;
	do
	{
		if (!passMatch)
			std::cout << "Both Passwords do not match !!\n";

		std::cout << "Confirm your Password :";
		std::cin.getline(reEnterPass, sizeof(reEnterPass));

		passMatch = !strcmp(reEnterPass, _tempPassword);


	} while (!passMatch);



	strcpy_s(password, _tempPassword);

	return true;
}

bool User::setCNIC()
{
	std::cout << "CNIC :";

	char _tempCNIC[20];

	//std::cout << "Choose a Username :";
	//std::cin.getline(_tempUsername, sizeof(_tempUsername));

	return 1;






}