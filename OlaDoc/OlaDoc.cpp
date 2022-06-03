#include "OlaDoc.h"

void OlaDoc::startProgram()
{
	MenuMain.displayMainMenu();
	MenuMain.displayDoctorMenu();


}


int main()
{
	OlaDoc OlaDoc1;


	OlaDoc1.startProgram();


	return 0;
}