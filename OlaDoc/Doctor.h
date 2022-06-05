#pragma once
#include "User.h"
#include "Menu.h"


class Doctor :
    public User
{
    char DoctorID[20];
    char academicDegree[50];
    double hourlyCharge;
    char specialization[50];
    virtual void  generateID();
    virtual  bool IDisAvailable(char* ID);


public:
    Doctor();
    friend bool Menu::DoctorRegistration();
    char* getID() { return DoctorID; };




};

