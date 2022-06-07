#include "Appointment.h"




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

char* Appointment::generateAppoitnmentID()
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





}