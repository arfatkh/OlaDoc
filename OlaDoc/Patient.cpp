#include "Patient.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>


void Patient::generateID()
{

	    int const IDLength = 10;
		
	

		srand(time(0));
		patientID[0] = 'P';
		int x = 0;
		for (int i = 1; i < IDLength; i++)
		{
			x = (rand() % 9) + 48;
			patientID[i] = static_cast<char>(x);//Added 48 for ascii;
		}
		patientID[IDLength - 1] = '\0';
		
	
	
	
	

}

bool Patient::IDisAvailable(char *ID)
{


		Patient P;
		std::ifstream fin;
		fin.open("patients.dat", std::ios::in | std::ios::binary);
		
		while (fin.read((char*)&P, sizeof(P)))
		{

			if (strcmp(P.getID(), ID))
				return false;



		}
		fin.close();

		return true;

}