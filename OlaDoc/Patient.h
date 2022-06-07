#pragma once
#include "User.h"
#include "Menu.h"


class Patient :
    public User
{
    char PATIENT_FILE_NAME[20] = "patients.dat";
    char patientID[10] = "";
    char allergies[100] = "";
       
        char bloodGroup[10] = "";
        char martialStatus[10] = "";
        char prescriptions[100] = "";
        char diseases[100] = "";
        int age=0;
        double balance=3500;
       
       virtual  bool IDisAvailable(char* ID);
     


public:
    virtual void  generateID();
    Patient(){    }
    friend bool Menu::PatientRegistration();
    void bookAppointment();
    void cancleAppointment();
    void giveFeedback();

    void viewMydata();

    //Returns doctor's ID
    char* searchDoctor();
    char* searchByCity();

    int getAge() { return age; }
    char* getID() { return patientID; }


    char* searchByName();
   // char* searchByCity();
   // char* searchByCat();
    char* ListAllDocs();
    void viewMyAppointment();



};
