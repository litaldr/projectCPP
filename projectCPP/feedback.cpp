#include "Feedback.h"

Feedback::Feedback(const date& newdate, buyers *buyer, const char* userFeedback) : myDate(newdate)
{
	memcpy(this->buyer, buyer, sizeof(buyer)); //ככה עושים ??
	setFeedback(user_feedback);
}

Feedback::Feedback(const Feedback &other) :buyer(other.buyer)//copy c'tor
{
	this->user_feedback = strdup(other.user_feedback);
	this->myDate = other.myDate;
}

Feedback::~Feedback()//destructor
{
	// does we need those delete? we allocate string in static way
	delete[]user_feedback;

}


void Feedback::setFeedback(const char * new_feedback) //feedback is given one time (if buyer wants set a feedback he had given he can't)
{
	this->user_feedback = new char[strlen(new_feedback) + 1];
	strncpy(this->user_feedback, new_feedback, strlen(new_feedback));
	this->user_feedback[strlen(user_feedback)] = '\0';
}
bool Feedback::setDate(int day, int month, int year)
{
	if (myDate.setDay(day) && myDate.setMonth(month) && myDate.setYear(year))
		return true;
	return false;
}
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
