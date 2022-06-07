#pragma once
#include "DateTime.h"
#include "Patient.h"
#include <ctime>
#include<random>
#include <fstream>

class Appointment
{
	const char* APPOINTMENT_FILE_NAME = "appointments.dat";
	char appointmentID[10] = "";
	char DoctorID[10] = "";
	char patientID[10] = "";
	char AppType = 'I';//I - inperson | V=- video


	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
	char status[5] = "P";
	DateTime appointmentTime;



	void generateAppoitnmentID();
	bool IDisAvailable(char* _string);
	friend void Patient::bookAppointment();

public:

	char* getID();
	Appointment(){}



	bool setStatus(char* _status);
	bool setType();
	bool setPatient(char* _patID);
	bool setDoctor(char* _docID);





};

