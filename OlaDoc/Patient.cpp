#include "Patient.h"
#include "Doctor.h"

#include "OlaDoc.h"

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
	char DocId[20]="";
	strcpy_s(DocId,searchDoctor());


	if (DocId)
	{
		A.generateAppoitnmentID();
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

		cout << "Appointment Booked Successfully!. [Appointment ID :" << A.appointmentID << "]\n";
		system("pause");

	}
	else
		cout << "SOME ERORRR!" << endl;
	


}

char* Patient::searchDoctor()
{
	int choice = -1;
	

	//To clear the screen
	system("cls");
	cout << "\n================ Find Doctors =================\n" << endl;
	cout << "[1] By Name" << endl;
	cout << "[2] By City" << endl;
	cout << "[3] By Specialization " << endl;
	cout << "[4] List All " << endl;
	cout << "[0] Back to MainMenu" << endl;
	cout << "====================================\n";

	choice = getIntChoice();

	bool invalidInput = true;
	while (choice >= 0 && invalidInput) {

		invalidInput = false;

		switch (choice)
		{
		case 1:
		{
			//searchByName();
						
			break;
		}
		case 2:
			//searchByCity();
			break;

		case 3:
			//searchByCat();
			break;
		case 4:
			return ListAllDocs();
			break;
		case 0:
		{
			break;
		}
			
		default:
			system("cls");
			cout << "Invalid Choice Select Again!!!\n\n" << endl;
			invalidInput = true;
			break;
		}
		
		if (invalidInput)
		{
			//To clear the screen
			system("cls");
			cout << "\n================ Find Doctors =================\n" << endl;
			cout << "[1] By Name" << endl;
			cout << "[2] By City" << endl;
			cout << "[3] By Specialization " << endl;
			cout << "[4] List All " << endl;
			cout << "[0] Back to MainMenu" << endl;
			cout << "====================================\n";

			choice = getIntChoice();

		}
		

	}


	


	

	
	


}


//Search
//char* Patient::searchByName()
//{
//
//	const char* DOCTOR_FILE_NAME = "doctors.dat";
//	char _temp[20];
//	cout << "Enter Name to Search :";
//	cin.getline(_temp, sizeof(_temp));
//
//
//	
//
//	bool found = false;
//	Doctor D;
//	ifstream fin;
//	fin.open(DOCTOR_FILE_NAME, std::ios::in | std::ios::binary);
//	if (fin.is_open())
//	{
//
//		int x = 0;
//		while (fin.read((char*)&D, sizeof(D)))
//		{
//			if (!stricmp(D.getName(), _temp))
//			{
//				found = true;
//				break;
//			}
//			
//
//		}
//
//
//		fin.close();
//
//	}
//
//	if (found)
//	{
//
//		cout << "\n\n================= Record Found ======================\n\n " << endl;
//
//		cout << "========================================================================\n";
//		cout << " Name :" << D.getName() << "\n ID:" << D.getID() << endl;
//		cout << "========================================================================\n";
//
//
//
//
//	}
//	else
//	{
//		system("cls");
//		cout << "Doctor Not Found | Try Again \n";
//		system("pause");
//
//	}
//		
//
//	
//
//
//
//
//
//
//
//
//
//
//
//}

char* Patient::ListAllDocs()
{

	const char* DOCTOR_FILE_NAME = "doctors.dat";

	bool found = false;
	Doctor D;
	ifstream fin;
	//fin.seekg(0);
	fin.open("doctors.dat", std::ios::in | std::ios::binary);
	if (fin.is_open())
	{

		int count = 1;

		while (fin.read((char*)&D, sizeof(D)))
		{	
			cout << "\n\n================= Doctor [" << count << "] ======================\n\n " << endl;
			cout <<count << ". Name :" << D.getName() << "\n ID:" << D.getID() << "Cnic: " << D.getCNIC() << endl;
			cout << "\n========================================================================\n";
			count++;
		}

		int choice = getIntChoice();
	
		if (count != 0)
		{

			while (choice > count)
			{
				cout << "Invalid Choice!!\n";
				choice = getIntChoice();

			}


			fin.seekg(choice * sizeof(Doctor), std::ios::beg);
			fin.read((char*)&D, sizeof(D));


			fin.close();

			return D.getID();




		}
		else
		{
			cout << "\n\n================= No Record Found ======================\n\n " << endl;
		}
		

		





		


	}
	


	

	

}

void Patient::viewMyAppointment()
{

	bool found = false;
	Appointment A;
	std::ifstream fin;
	fin.open("appointments.dat", std::ios::in | std::ios::binary);
	system("cls");
	cout << "====================Your Appointment=======================\n";
	if (fin.is_open())
	{
		while (fin.read((char*)&A, sizeof(A)))
		{

			if (!strcmp(A.patientID,patientID )) //&& strcmp(A.status,"C"))
			{
				cout << "Doctor ID : " << A.DoctorID << endl;
				cout << "Appointment Status :" << A.status << endl;
				cout << "Patient " << A.patientID << endl;
				cout << "================================================================\n";
				
				found = true;
				
			}



		}

		fin.close();
	}
	
	if (!found)
	{
		cout << "                        No Appointments Found!                \n";
	}

		

	system("pause");










}

void Patient::cancleAppointment()
{
	bool found = false;



	viewMyAppointment();
	
	char choice;

	do
	{
		cout << "Are you sure to cancle this appointment ? [Y/N] :";
		cin >> choice;
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');


	if (choice == 'y' || choice == 'Y')
	{
		Appointment A;
		std::fstream file;
		file.open("appointments.dat", std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
		file.seekg(0);
		if (file.is_open())
		{
			while (file.read((char*)&A, sizeof(A)))
			{

				if (!strcmp(A.patientID, patientID))
				{
					if (!strcmp(A.status, "C"))
					{
						cout << "Already Cancelled !!";
						file.close();
						break;
					}
					else
					{
						int current = file.tellp();
						file.seekp(current - sizeof(A));
						A.setStatus("C");
						file.write((char*)&A, sizeof(A));
						file.close();
						cout << "Appointment Cancelled Successfully!\n";
						break;
					}
					

				}



			}

		}






	}
	else
		cout << "Okiesss !" << endl;






	system("pause");












}