#pragma once
#include "Menu.h"
#include "Admin.h"

class OlaDoc
{
	Menu MenuMain;
	Admin _admin;



public:
	//TO start the olaDoc program
	void startProgram();
	friend void Menu::displayAdminMenu();
	
};

