#include "Admin.h"
#include "Patient.h"
#include "Doctor.h"

#include<iostream>
#include <fstream>

const char* PATIENT_FILE_NAME = "patients.dat";
const char* DOCTOR_FILE_NAME = "doctor.dat";





using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;





void Admin::viewDoctors()
{

    cout << "================= Doctors List " << endl;
    Doctor D;

    ifstream fin;
    fin.open(PATIENT_FILE_NAME, std::ios::in | std::ios::binary);
   
    int x = 0;
    while (fin.read((char*)&D, sizeof(D)))
    {
        cout << "========================================================================\n";
        cout << " Name :" << D.getName() << "\n ID:" << D.getID()<<endl;
        cout << "========================================================================\n";

    }


    fin.close();









}