#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class buyers;
static const int MAX_FEEDBACK_SIZE = 100; // static variable for maximum feedback size

class Feedback
{

public:
	Feedback() = delete; //not interested in default constructor 
	Feedback(const date& newdate, buyers *buyer, char* userFeedback);//constructor
	Feedback(const Feedback &other);//copy constructor
	~Feedback(); // destructor

 //---------------------set & get functions-----------------------//
	buyers* getBuyer() const;
	date getDate()     const;
	char * getUserFeedback() const;

//-----------not in use--------------//

	void setFeedback(char * user_feedback);
	bool setDate(int day, int month, int year);

private:
//-----------------------attributes----------------------//
	date myDate;
	char *user_feedback;
	buyers *buyer;

};

#endif 

