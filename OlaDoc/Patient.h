#pragma once
#include "User.h"
#include "Menu.h"


class Patient :
    public User
{
    char patientID[10];
    char allergies[100];
        char dateOfBirth[10];
        char gender[10];
        char bloodGroup[10];
        char martialStatus[10];
        char prescriptions[100];
        char diseases[100];
        int age;
        double balance;
       virtual void  generateID();
       virtual  bool IDisAvailable(char* ID);
public:
    Patient()
    {
        //Generates and assigns patient ID
       generateID();
    }
    friend bool Menu::PatientRegistration();
    int getAge() { return age; }
    char* getID() { return patientID; }
};
