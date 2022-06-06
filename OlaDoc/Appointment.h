#pragma once
#include "DateTime.h"
class Appointment
{
	char appointmentID[20] = "";
	char DoctorID[10] = "";
	char patientID[10] = "";

	// P - Pending
	// C -Canceled
	// CC - Completed
	// D - Delayed
	char status[5] = "P";
	

	DateTime appointmentTime;















};

