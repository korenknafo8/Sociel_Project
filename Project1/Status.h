#ifndef STATUS_H
#define STATUS_H
#include <string.h>
#include <iostream>
#include "DateTimeUtils.h"
#pragma warning (disable: 4996)
using namespace std;

class Status
{
public:
	void setContent(const char* input);
	void showStatus();
	Status(const char* text);

private:
	char* content_; //for first module - text only
	Date date_of_Status_;
	Clock time_of_Status;
};

#endif // !STATUS_H