#pragma once
#include "DateTime.h"
#include "Patient.h"
#include "Doctor.h"
#include "Feedback.h"
#include <ctime>
#include<random>
#include <fstream>

class Appointment
{
	const char* APPOINTMENT_FILE_NAME = "appointments.dat";
	char appointmentID[10] = "";
	char DoctorID[20] = "";
	char patientID[20] = "";
	char AppType = 'I';//I - inperson | V=- video


	Feedback feedback;


	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
	char status[5] = "P";
	DateTime appointmentTime;



	void generateAppoitnmentID();
	bool IDisAvailable(char* _string);
	friend void Patient::bookAppointment();
	friend void Doctor::viewMyAppointment();


public:

	friend class Patient;
	friend class Doctor;
	char* getID();
	Appointment(){}



	bool setStatus(const char* _status);
	bool setType();
	bool setPatient(char* _patID);
	bool setDoctor(char* _docID);

	int getIntChoice(const char* textToAdd = "Select An option :");




};

