#include "OlaDoc.h"
#include <iostream>
#include <fstream>
#include "Patient.h"

using namespace std;
/*

Name : Muhammad Arfat
Roll No: i210554
Section : BSCS Z


*/




// Points for invigilator g

/*
 1- The functions instead of void are made bools to be able to return false if error occurs.

*/








void OlaDoc::startProgram()
{
	MenuMain.displayMainMenu();
	//MenuMain.displayDoctorMenu();


}


int main()
{
	OlaDoc OlaDoc1;



	OlaDoc1.startProgram();



    cout << "Displaying Name" << endl;
    Patient P;

    ifstream fin;
    fin.open("patients.dat", ios::in | ios::binary);
    int x = 0;
    while (fin.read((char*)&P, sizeof(P)))
    {
        
        cout<<x++<<" " << P.getName() <<", " << P.getID() << endl;
        
      
    }


    fin.close();






















	return 0;
}