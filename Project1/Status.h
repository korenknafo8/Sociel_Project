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
	void setContent(const string input);
	void show() const;
	Status(const string text);

private:
	string content_; //for first module - text only
	Date date_of_Status_;
	Clock time_of_Status_;
};

#endif // !STATUS_H