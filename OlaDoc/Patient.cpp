#include "Patient.h"

#include "Appointment.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>


using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

void Patient::generateID()
{

	    int const IDLength = 10;
		
	

		srand(time(0));
		patientID[0] = 'P';
		int x = 0;
	//	do
		//{
		
			for (int i = 1; i < IDLength; i++)
			{
				x = (rand() % 9) + 48;
				patientID[i] = static_cast<char>(x);//Added 48 for ascii;
			}
			



		//} while (!IDisAvailable(patientID));
		
			patientID[IDLength - 1] = '\0';
	
	
	
	

}

bool Patient::IDisAvailable(char *ID)
{


		Patient P;
		std::ifstream fin;
		fin.open("patients.dat", std::ios::in | std::ios::binary);

		if (fin.is_open())
		{
			while (fin.read((char*)&P, sizeof(P)))
			{

				if (!strcmp(P.getID(), ID))
				{
					fin.close();
					return false;
				}



			}

		}
		
	
		

		return true;

}

void Patient::bookAppointment()
{
	Appointment A;
	system("cls");
	cout << "==================== Appointment Booking ==================" << endl;
	char* DocId = searchDoctor();
	A.setType();

	A.setPatient(patientID);
	A.setDoctor(DocId);



	std::ofstream fout;
	fout.open("appointments.dat", std::ios::app | std::ios::binary);

	if (fout.is_open())
	{
		fout.write((char*)(&A), sizeof(A));
		
	}




	fout.close();

	cout << "Appointment Booked Successfully.!\n";
	system("pause");
	


}
