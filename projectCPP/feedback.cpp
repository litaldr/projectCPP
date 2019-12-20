#include "Feedback.h"

Feedback::Feedback(const date& newdate, buyers *buyer,  char* userFeedback) : myDate(newdate), buyer(buyer) // costructor
{
	this->user_feedback = new char[strlen(userFeedback) + 1];
	strcpy(this->user_feedback, userFeedback);
	this->user_feedback[strlen(userFeedback)] = '\0';
}

Feedback::Feedback(const Feedback &other) :buyer(other.buyer)//copy costructor
{
	this->user_feedback = strdup(other.user_feedback);
	this->myDate = other.myDate;
}

Feedback::~Feedback()//destructor
{
	delete[]user_feedback;
}

//---------------------set & get functions-----------------------//

buyers* Feedback::getBuyer() const
{
	return buyer;
}

date Feedback::getDate()     const
{
	return myDate;
}

char * Feedback::getUserFeedback() const
{
	return user_feedback;
}

//-----------not in use--------------//

void Feedback::setFeedback(char * userFeedback)
{
	strcpy(this->user_feedback, userFeedback);
	this->user_feedback[strlen(userFeedback)] = '\0';
}

bool Feedback::setDate(int day, int month, int year)
{
	if (this->myDate.setDay(day) && this->myDate.setMonth(month) && this->myDate.setYear(year)) // sets of date check validation
		return true;
	else 
		return false;
}