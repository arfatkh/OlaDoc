#pragma once
class User
{
protected:
	char name[30];
	char userName[20];
	char password[60];
	char address[150];
	char mobileNo[11];
	char email[30];
	char CNIC[13];
	char gender[10];
	virtual void generateID()=0;//To generate random ids for users
	virtual bool IDisAvailable(char* ID)=0; //Checks if an ID is available
	bool setUserName();
	bool UserNameIsAvailable(char* _string);
	bool setPassword();


public:
	

	
	

	char* getName();
	char* getUserName();
	char* getEmail();
	char* getMobileNo();
	char* getAddress();
	char* getPassword();

};

