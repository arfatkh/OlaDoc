#include "Appointment.h"
#include <iomanip>
//#include "Menu.h"




char* Appointment::getID() { return appointmentID; }

bool Appointment::IDisAvailable(char* _string)
{

	Appointment A;
	std::ifstream fin;
	fin.open(APPOINTMENT_FILE_NAME, std::ios::in | std::ios::binary);

	if (fin.is_open())
	{

		while (fin.read((char*)&A, sizeof(A)))
		{

			if (!strcmp(A.getID(), _string))
			{
				fin.close();
				return false;
			}


		}
	}
	return true;




}

void Appointment::generateAppoitnmentID()
{

	int const IDLength = 10;

	srand(time(0));
	appointmentID[0] = 'A';

	int x = 0;
	do
	{
		for (int i = 1; i < IDLength; i++)
		{
			x = (rand() % 9) + 48;
			appointmentID[i] = static_cast<char>(x);//Added 48 for ascii;
		}
		appointmentID[IDLength - 1] = '\0';

	} while (!IDisAvailable(appointmentID));




	
}

bool Appointment::setStatus(char* _status)
{
	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
  
	strcpy_s(status, _status);



	return true;

}


bool Appointment::setType()
{

	int choice = -1;

	std::cout << "Appointment Type : \n";
	std::cout << "[1] Video \n ";
	std::cout << "[2] In-Person\n ";
	std::cout << "===================\n";
	


	choice = getIntChoice();

	while (choice > 0) {



		switch (choice)
		{
		case 1:
			AppType = 'V';
			break;

		case 2:
			AppType = 'I';
			break;
		default:
			system("cls");
			std::cout << "Invalid Choice Select Again!!!\n\n" << std::endl;
			break;
		}
	

		std::cout << "Appointment Type : \n";
		std::cout << "[1] Video  \n";
		std::cout << "[2] In-Person \n";
		std::cout << "===================\n";
	
		choice = getIntChoice();


	}


		

	return true;


}


bool Appointment::setPatient(char* _patID)
{
	strcpy_s(patientID, _patID);
	return true;
}
bool Appointment::setDoctor(char* _docID)
{

	strcpy_s(DoctorID, _docID);
	return true;
}


int Appointment::getIntChoice(const char* textToAdd)
{

	int choice = 0;

	std::cout << textToAdd;
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
