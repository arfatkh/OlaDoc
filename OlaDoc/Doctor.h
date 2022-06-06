#pragma once
#include "User.h"
#include "Menu.h"




class Doctor :
    public User
{
    const char* DOCTOR_FILE_NAME = "doctors.dat";
    char DoctorID[20] = "";
    char academicDegree[50] = "";
    double hourlyCharge=0;
    char specialization[50] = "";
    virtual void  generateID();
    virtual  bool IDisAvailable(char* ID);
  

  


public:
    Doctor();
    friend bool Menu::DoctorRegistration();
    char* getID() { return DoctorID; };




};

