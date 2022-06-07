#pragma once
#include "User.h"
#include "Menu.h"




class Doctor :
    public User
{
    const char* DOCTOR_FILE_NAME = "doctors.dat";
    char DoctorID[10] = "";
    char academicDegree[50] = "";
    double hourlyCharge=0;
    char specialization[50] = "";
   
    virtual  bool IDisAvailable(char* ID);
  

  


public:
    virtual void  generateID();
    Doctor();
    friend bool Menu::DoctorRegistration();
    char* getID() { return DoctorID; };




};

