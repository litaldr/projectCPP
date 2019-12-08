#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class buyers;

class Feedback
{
public:
	Feedback() = delete;
	Feedback(const date& newdate, buyers *buyer, const char* userFeedback);//constructor
	Feedback(const Feedback &other);//copy constructor
	~Feedback(); // defualt destructor because feedback string allocated static

	void setFeedback(const char * user_feedback);
	bool setDate(int day, int month, int year);

	buyers* getBuyer() const;
	date getDate()     const;
	char * getUserFeedback() const;


private:

	date myDate;
	char *user_feedback;
	buyers *buyer;

};

#endif 

