#include "DateTime.h"	
#include<string>

DateTime::DateTime(std::string str)
{
	char _day[2];
	_day[0] = str[0];
	_day[1] = str[1];

	day = std::stoi(_day);

	char _month[2];
	_month[0] = str[2];
	_month[1] = str[3];

	month = std::stoi(_month);

	char _year[4];
	_year[0] = str[4];
	_year[1] = str[5];
	_year[2] = str[6];
	_year[3] = str[7];

	year = std::stoi(_year);


}

void DateTime::setDate(std::string str)
{

	char _day[2];
	_day[0] = str[0];
	_day[1] = str[1];

	day = std::stoi(_day);

	char _month[2];
	_month[0] = str[2];
	_month[1] = str[3];

	month = std::stoi(_month);

	char _year[4];
	_year[0] = str[4];
	_year[1] = str[5];
	_year[2] = str[6];
	_year[3] = str[7];

	year = std::stoi(_year);





}