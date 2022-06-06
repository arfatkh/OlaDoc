#pragma once
#include "DateTime.h"
#include <fstream>
class Appointment
{
	const char* APPOINTMENT_FILE_NAME = "appointments.dat";
	char appointmentID[20] = "";
	char DoctorID[10] = "";
	char patientID[10] = "";


	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
	char status[5] = "P";
	DateTime appointmentTime;


	//char* generateID();
	bool IDisAvailable(char* _string);


public:

	char* getID();
	Appointment()
	{
		//generateID();
	}





};

