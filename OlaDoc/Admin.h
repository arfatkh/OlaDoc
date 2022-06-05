#pragma once
#include<iostream>
class Admin
{
	char userName[20];
	char password[30];



public:
	Admin()
	{
		strcpy_s(userName, "admin");
		strcpy_s(password, "admin");
	}


	void viewDoctors();







};

