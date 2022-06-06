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
