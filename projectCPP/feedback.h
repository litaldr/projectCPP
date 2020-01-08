#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class buyer;

#define MAX_FEEDBACK_SIZE  100 // static variable for maximum feedback size



class Feedback
{

public:
	Feedback() = delete; //not interested in default constructor 
	Feedback(const date& newdate, buyer *buyer, char* userFeedback);//constructor
	Feedback(const Feedback &other);//copy constructor
	~Feedback(); // destructor
	friend ostream& operator<<(ostream& os, const Feedback& feedback);

 //---------------------set & get functions-----------------------//
	const buyer* getBuyer() const;
	const date& getDate()     const;
	const char * getUserFeedback() const;

//-----------not in use--------------//

	void setFeedback(const char * user_feedback);
	bool setDate(int day, int month, int year);

private:
//-----------------------attributes----------------------//
	date myDate;
	char *user_feedback;
	buyer *theBuyer;

};

#endif 

