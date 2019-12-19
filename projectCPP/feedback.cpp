#include "Feedback.h"

Feedback::Feedback(const date& newdate, buyers *buyer,  char* userFeedback) : myDate(newdate), buyer(buyer)
{
	this->user_feedback = new char[strlen(userFeedback) + 1];
	strcpy(this->user_feedback, userFeedback);
	this->user_feedback[strlen(userFeedback)] = '\0';
}

Feedback::Feedback(const Feedback &other) :buyer(other.buyer)//copy c'tor
{
	this->user_feedback = strdup(other.user_feedback);
	this->myDate = other.myDate;
}

Feedback::~Feedback()//destructor
{
	delete[]user_feedback;
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
