#include "User.h"
#include "Patient.h"
#include "Doctor.h"

#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>
#include<iomanip>



//Getters For User
char* User::getName() { return name; }
char* User::getCNIC() { return CNIC; }
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

	
	//Check in doctors Data
	Doctor D;
	std::ifstream fin;
	fin.open("doctors.dat", std::ios::in | std::ios::binary);

	if (fin.is_open())
	{
		while (fin.read((char*)&D, sizeof(D)))
		{

			if (!strcmp(D.getUserName(), _string))
			{
				fin.close();
				return false;
			}


		}

	}



	//Check in Patients Data
	Patient P;

	std::ifstream fin1;
	fin1.open("patients.dat", std::ios::in | std::ios::binary);

	while (fin1.read((char*)&P, sizeof(P)))
	{

		if (!strcmp(P.getUserName(), _string))
		{
			fin.close();
			return false;
		}



	}

	




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
			// Ascii Special char ARanges 32�47 / 58�64 / 91�96 / 123�126
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
		passMatch = true;
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
	bool ValidCNIC = true;

	do
	{

		if (!ValidCNIC)
			std::cout << "Invalid CNIC NO !!\n";

		ValidCNIC = true;

		std::cout << "CNIC [11111-1111111-1] :";
		std::cin.getline(_tempCNIC, sizeof(_tempCNIC));



		if (strlen(_tempCNIC) != 15)
		{
			ValidCNIC = false;
		}

		if (_tempCNIC[5] != '-' || _tempCNIC[13] != '-')
			ValidCNIC = false;

		for (char& ch : _tempCNIC)
		{

			if (ch == 0)
				break;

			if (!((ch >= '0' && ch <= '9') || ch == '-'))
				ValidCNIC = false;

		}

	/*	for (char& ch : _tempCNIC)
		{

			if (ch == 0)
				break;

			if (!isaplha())
				ValidCNIC = false;

		}*/


	} while (!ValidCNIC);





	while (!CNICAvailable(_tempCNIC))
	{
		std::cout << "CNIC Already Exists!!\n";

		//std::cin.ignore(1000, '\n');


		std::cout << "CNIC [11111-1111111-1] :";
		std::cin.getline(_tempCNIC, sizeof(_tempCNIC));



	}


	strcpy_s(CNIC, _tempCNIC);

	return 1;



}


bool User::CNICAvailable(char* _cnic)
{



	



	//Check in doctors Data
	Doctor D;
	std::ifstream fin;
	fin.open(DOCTOR_FILE_NAME, std::ios::in | std::ios::binary);

	if (fin.is_open())
	{
		while (fin.read((char*)&D, sizeof(D)))
		{

			if (!strcmp(D.getCNIC(), _cnic))
			{
				fin.close();
				return false;
			}
		}

	}



	//Check in Patients Data
	Patient P;

	fin.open(PATIENT_FILE_NAME, std::ios::in | std::ios::binary);
	if (fin.is_open())
	{
		while (fin.read((char*)&P, sizeof(P)))
		{

			if (!strcmp(P.getCNIC(), _cnic))
			{
				fin.close();
				return false;
			}



		}
	}

	




	return true;













}



bool User::setDOB()
{
	

	char _tempDOB[10];
	bool ValidDOB = true;

	do
	{

		if (!ValidDOB)
			std::cout << "Invalid Date of Birth | Follow ddmmyyyy format !!\n";

		ValidDOB = true;

		std::cout << "Date Of Birth[ddmmyyyy] :";

		std::cin.getline(_tempDOB, sizeof(_tempDOB));



		if (strlen(_tempDOB) != 8)
		{
			ValidDOB = false;
		}

		

		for (char& ch : _tempDOB)
		{

			if (ch == 0)
				break;

			if (!(ch >= '0' && ch <= '9'))
				ValidDOB = false;

		}


	} while (!ValidDOB);



	strcpy_s(dateOfBirth, _tempDOB);


	return true;


}


int User::getIntChoice(const char* textToAdd)
{

	int choice = 0;

	std::cout<<"\n" << textToAdd;
	std::cin >> std::setw(1) >> choice;

	while (!std::cin.good())
	{
		//Displaying Error
		std::cout << "Faulty  Input ! Try Again.\n";


		//Clearing Stream
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		//Taking Input Again;
		std::cout << textToAdd;
		std::cin >> choice;

	}

	//Clearing Stream
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');




	return choice;

}

