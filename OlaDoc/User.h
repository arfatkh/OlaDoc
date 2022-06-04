#pragma once
class User
{
	char name[30];
	char userName[20];
	char password[60];
	char address[150];
	char mobileNo[11];
	char email[30];

public:
	char* getName();
	char* getUserName();
	char* getEmail();
	char* getMobileNo();
	char* getAddress();
	char* getPassword();

};

