#include "Doctor.h"
#include "Appointment.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>

using std::cin;
using std::cout;
using std::endl;


Doctor::Doctor()
{
	//generateID();
}


void Doctor::generateID()
{

	int const IDLength = 10;



	srand(time(0));
	DoctorID[0] = 'D';
	int x = 0;
	do
	{
		for (int i = 1; i < IDLength; i++)
		{
			x = (rand() % 9) + 48;
			DoctorID[i] = static_cast<char>(x);//Added 48 for ascii;
		}
		DoctorID[IDLength - 1] = '\0';

	} while (!IDisAvailable(DoctorID));








}

bool Doctor::IDisAvailable(char* ID)
{


	Doctor D;
	std::ifstream fin;
	fin.open("doctors.dat", std::ios::in | std::ios::binary);


	if (fin.is_open())
	{

		while (fin.read((char*)&D, sizeof(D)))
		{

			if (!strcmp(D.getID(), ID))
			{
				fin.close();
				return false;
			}




		}
	}

	return true;

}

void Doctor::viewMyAppointment()
{

	bool found = false;
	Appointment A;
	std::ifstream fin;
	int count = 1;
	fin.open("appointments.dat", std::ios::in | std::ios::binary);
	system("cls");
	cout << "====================Your Appointments=======================\n";
	if (fin.is_open())
	{
		while (fin.read((char*)&A, sizeof(A)))
		{

			if (!strcmp(A.DoctorID, DoctorID)) //&& strcmp(A.status,"C"))
			{
				cout << "NO " << count++ << endl;
				cout << "Appointment Status :" << A.status << endl;
				cout << "Patient " << A.patientID << endl;
				cout << "Rating " << A.feedback.getRating() << endl;
				cout << "Review: " << A.feedback.getReview() << endl;
				cout << "Response: " << A.feedback.getResponse() << endl;



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


void Doctor::cancleAppointments()
{

	bool found = false;
	Appointment A;
	std::fstream fin;
	int count = 1;
	system("cls");
	fin.open("appointments.dat", std::ios::in  | std::ios::binary);
	fin.seekg(0);
	cout << "====================Your Appointments=======================\n";
	if (fin.is_open())
	{
		while (fin.read((char*)&A, sizeof(A)))
		{

			if (!strcmp(A.DoctorID, DoctorID)) //&& strcmp(A.status,"C"))
			{
				cout << "NO " << count++ << endl;
				cout << "Appointment Status :" << A.status << endl;
				cout << "Patient " << A.patientID << endl;
				cout << "Rating " << A.feedback.getRating() << endl;
				cout << "Review: " << A.feedback.getReview() << endl;
				cout << "Response: " << A.feedback.getResponse() << endl;



				cout << "================================================================\n";

				found = true;

			}



		}

		fin.close();





		fin.open("appointments.dat", std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
		fin.seekg(std::ios::beg);



		if (found)
		{
			int choice;
			cout << "Choose Appointment to cancle [0 to go back]\n";
			choice = getIntChoice();

			while (choice > count)
			{
				cout << "Choose Appointment to cancle [0 to go back]\n";
				choice = getIntChoice();

			}

			if (choice != 0)
			{
				int x = 1;

				while (fin.read((char*)&A, sizeof(A)))
				{

					if (!strcmp(A.DoctorID, DoctorID) && choice == x)
					{
						if (!strcmp(A.status, "C"))
						{
							cout << "Already Cancelled !!";
							fin.close();
							break;
						}
						else
						{
							int current = fin.tellp();
							fin.seekp(current - sizeof(A));
							A.setStatus("C");
							fin.write((char*)&A, sizeof(A));
							fin.close();
							cout << "Appointment Cancelled Successfully!\n";
							break;
						}

						x++;

					}







				}




			}





		}

		if (!found)
		{
			cout << "                        No Appointments Found!                \n";
		}



		system("pause");

	}

}

void Doctor::respondToFeedback()
{

	bool found = false;
	int count = 1;
	Appointment A;
	std::fstream fin;
	fin.open("appointments.dat", std::ios::in | std::ios::binary);
	system("cls");
	cout << "====================Your Feeback Required on Appointments=======================\n";
	if (fin.is_open())
	{
		fin.seekg(std::ios::beg);
		while (fin.read((char*)&A, sizeof(A)))
		{

			if (!strcmp(A.DoctorID, DoctorID))//&& !strcmp(A.status, "CC")) //&& strcmp(A.status,"C"))
			{

				cout << "NO " << count << endl;
				cout << "Doctor ID : " << A.DoctorID << endl;
				cout << "Appointment Status :" << A.status << endl;
				cout << "Patient " << A.patientID << endl;
				cout << "Rating " << A.feedback.getRating() << endl;
				cout << "Review: " << A.feedback.getReview() << endl;
				cout << "Response: " << A.feedback.getResponse() << endl;
				cout << "================================================================\n";
				count++;
				found = true;

			}



		}

		fin.close();
	}

	if (!found)
	{
		cout << "                        No Appointments Found!                \n";
	}



	if (count > 1)
	{

		cout << "Select an Appointment to give feedback to \n";
		cout << "Enter 0 to go back\n";
		int choice = getIntChoice();

		if (choice != 0)
		{
			while (choice > count)
			{
				cout << "Invalid Choice!!\n";
				choice = getIntChoice();

			}


			fin.open("appointments.dat", std::ios::ate | std::ios::out | std::ios::in | std::ios::binary);
			if (fin.is_open())
			{

				fin.seekg(std::ios::beg);
				int i = 1;
				while (fin.read((char*)&A, sizeof(A)))
				{
					if (!strcmp(A.DoctorID, DoctorID))
					{
						if (i == choice)
						{
							int current = fin.tellg();

							fin.seekp(current - sizeof(A));

							A.feedback.setResponse();
						

							fin.write((char*)&A, sizeof(A));
							cout << "Feeback given Successfully!\n";
							fin.close();

							break;
						}

						i++;


					}

				}


			}
			else
				cout << "Error Internal!!" << endl;
		}


	}





	system("pause");


}


void Doctor::viewMydata()
{
	int x = 10;
	system("cls");
	cout << "========================= Information ==============================\n";
	cout << "Name :" << this->name << endl;
	cout << "CNIC :" << this->CNIC << endl;
	cout << "Address :" << this->address << endl;
	cout << "Phone :" << this->mobileNo << endl;
	cout << "ID  :" << this->DoctorID << endl;
	cout << "Date Of Birth :" << this->dateOfBirth << endl;
	cout << "Email :" << this->email << endl;
	cout << "Hourly Charge in Person :" << this->hourlyChargeInPerson << endl;
	cout << "Hourly Charge in Video :" << this->hourlyChargeVideo << endl;
	cout << "Balance :" << (this)->balance << endl;

	cout << " =======  =======  =======  =======  =======  =======  =======  =======\n";



	system("pause");









}
