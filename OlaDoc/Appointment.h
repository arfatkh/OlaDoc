#pragma once
#include "DateTime.h"
#include <ctime>
#include<random>
#include <fstream>
class Appointment
{
	const char* APPOINTMENT_FILE_NAME = "appointments.dat";
	char appointmentID[10] = "";
	char DoctorID[10] = "";
	char patientID[10] = "";


	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
	char status[5] = "P";
	DateTime appointmentTime;


	char* generateAppoitnmentID();
	bool IDisAvailable(char* _string);


public:

	char* getID();
	Appointment(){	generateAppoitnmentID();}
	bool setStatus(char* _status);




};

