#pragma once
#include<iostream>
class DateTime
{
	int hour = 0;
	int minute = 0;
	int second = 0;

	int day = 0;
	int month = 0;
	int year = 0;

public:

	DateTime(std::string str);
	void setDate(std::string str);

	void setTime(int _hour, int _min, int _sec){
		hour = _hour;
		minute = _min;
		second = _sec;
	}
};

