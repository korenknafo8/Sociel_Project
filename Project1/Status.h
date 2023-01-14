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
	void setContent(const string& input);
	void show() const;
	Status(const string text);
	bool operator!=(Status other);
	bool operator==(Status other);

private:
	string content_;
	Date date_of_Status_;
	Clock time_of_Status_;
};

//pictures
class Status_Picture : public Status
{
public:
	Status_Picture();
	~Status_Picture();

private:
	string picture_description_;
};

//videos
class Status_Video : public Status
{

public:
	Status_Video();
	~Status_Video();

private:
	string video_description_;
};

#endif // !STATUS_H