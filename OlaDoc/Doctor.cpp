#include "Doctor.h"


//void Doctor::generateID()
//{
//
//	int const IDLength = 6;
//	char ID[IDLength];
//	ID[0] = 'P';
//
//	srand(time(0));
//
//	do
//	{
//		for (int i = 1; i < IDLength; i++)
//		{
//			ID[i] = reinterpret_cast<char>(std::to_string(rand() % 10).c_str());
//		}
//	} while (!IDisAvailable(ID));
//
//	std::strcpy(patientID, ID);
//
//
//
//
//
//}
//
//bool Doctor::IDisAvailable(char* ID)
//{
//
//
//	Patient P;
//	std::ifstream fin;
//	fin.open("patients.dat", std::ios::in | std::ios::binary);
//
//	while (fin.read((char*)&P, sizeof(P)))
//	{
//
//		if (strcmp(P.getID(), ID))
//			return false;
//
//
//
//	}
//	fin.close();
//
//	return true;
//
//}