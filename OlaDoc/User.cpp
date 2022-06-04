#include "User.h"
#include "Patient.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include <string>



//Getters For User
char* User::getName(){return name;}
char* User::getUserName() { return userName; }
char* User::getEmail(){return email;}
char* User::getMobileNo(){return mobileNo;}
char* User::getAddress(){return address;}
char* User::getPassword(){return password;}



//bool User::isAvailable(char* ID)
//{
//	
//	if (ID[0] == 'P')//Check Patient
//	{
//
//		Patient P;
//		std::ifstream fin;
//		fin.open("patients.dat", std::ios::in | std::ios::binary);
//		
//		while (fin.read((char*)&P, sizeof(P)))
//		{
//
//			if (strcmp(P.getID(), ID))
//				return false;
//
//
//
//		}
//		fin.close();
//
//		return true;
//
//
//
//
//
//
//
//	}
//	else if (ID[0] == 'D')//Check Doctor
//	{
//
//
//
//	}
//
//
//
//
//
//}
