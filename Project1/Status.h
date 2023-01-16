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
	Status(const string text) { status_text_ = text; };
	virtual void show() const;
	bool operator!=(Status other);
	bool operator==(Status other);

private:
	string status_text_;
	Date date_of_Status_;
	Clock time_of_Status_;
};

//pictures
class Status_Picture : public Status
{
public:
	Status_Picture(string text, string ststus_picture) : Status(text) { picture_description_ = ststus_picture; };
	virtual void show() const override;
private:
	string picture_description_;
};

//videos
class Status_Video : public Status
{

public:
	Status_Video(string text, string ststus_video) : Status(text) { video_description_ = ststus_video; };
	virtual void show() const override;
private:
	string video_description_;
};

#endif // !STATUS_H