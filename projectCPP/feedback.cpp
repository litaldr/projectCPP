#include "Feedback.h"

Feedback::Feedback(const date& newdate, buyer *buyer,  char* userFeedback) : myDate(newdate), theBuyer(buyer) // constructor
{
	this->user_feedback = strdup(userFeedback);
}



Feedback::Feedback(const Feedback &other) :theBuyer(other.theBuyer)//copy constructor
{
	this->user_feedback = strdup(other.user_feedback);
	this->myDate = other.myDate;
}

Feedback::~Feedback()//destructor
{
	delete[]user_feedback;
}

//---------------------set & get functions-----------------------//

const buyer* Feedback::getBuyer() const
{
	return theBuyer;
}

const date& Feedback::getDate()     const
{
	return myDate;
}

const char * Feedback::getUserFeedback() const
{
	return user_feedback;
}

//-----------not in use--------------//

void Feedback::setFeedback(const char * userFeedback)
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

ostream & operator<<(ostream & os, const Feedback & feedback)
{
	os << feedback.myDate << endl;
	os << feedback.user_feedback<<endl;
	return os;
}