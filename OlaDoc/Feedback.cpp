#include "Feedback.h"
#include <iostream>

using std::cin;
using std::cout;


double Feedback::getRating() { return Ratingof5; }
char* Feedback::getReview() { return review; }
char* Feedback::getResponse() { return response; }

void Feedback::setRating()
{
	double _r=0;
	bool flag = false;

	do {
		
		cout << "Enter Rating out of 5 :";
		cin >> _r;
		cin.ignore(1000, '\n');
	} while (_r > 5 || _r < 0);
	
	Ratingof5 = _r;
}
void Feedback::setReview()
{
	char _str[150];
	cout << "Enter Review :";
	cin.getline(_str, sizeof(_str));
	strcpy_s(review, _str);
}
void Feedback::setResponse()
{
	char _str[150];
	cout << "Enter Response :";
	cin.getline(_str, sizeof(_str));
	strcpy_s(response, _str);

}

