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
	void set_content(char* input);
	void show_status();

private:
	char* content_; //for first module - text only
	Date date_of_Status_;
};

#endif // !STATUS_H