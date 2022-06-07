#pragma once
class Feedback
{
	double Ratingof5 = -1;
	char review[150]="";
	char response[150]="";


public:
	void setRating();
	void setReview();
	void setResponse();

	double getRating();
	char* getReview();
	char* getResponse();

};

