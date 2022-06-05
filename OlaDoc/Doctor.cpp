#include "Doctor.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>



Doctor::Doctor()
{
	generateID();
}


void Doctor::generateID()
{

	int const IDLength = 10;



	srand(time(0));
	DoctorID[0] = 'D';
	int x = 0;
	for (int i = 1; i < IDLength; i++)
	{
		x = (rand() % 9) + 48;
		DoctorID[i] = static_cast<char>(x);//Added 48 for ascii;
	}
	DoctorID[IDLength - 1] = '\0';






}

bool Doctor::IDisAvailable(char* ID)
{


	Doctor P;
	std::ifstream fin;
	fin.open("doctors.dat", std::ios::in | std::ios::binary);

	while (fin.read((char*)&P, sizeof(P)))
	{

		if (strcmp(P.getID(), ID))
			return false;



	}
	fin.close();

	return true;

}