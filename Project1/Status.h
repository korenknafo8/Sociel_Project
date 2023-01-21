#ifndef STATUS_H
#define STATUS_H
#include <string.h>
#include <iostream>
#include "DateTimeUtils.h"
#pragma warning (disable: 4996)
using namespace std;

enum statusChoiseEnum { TEXT_STATUS = 1, PICTURE_STATUS, VIDEO_STATUS };


class Status
{
public:
	Status(const string text) { text_ = text; };
	Status(const string text, Date date, Clock time) { text_ = text; date_of_Status_ = date, time_of_Status_ = time; };
	virtual void show() const;
	bool operator!=(Status other);
	bool operator==(Status other);
	friend ostream& operator<<(ostream& os, const Status& p);
	virtual void toFile(ostream& os) const {}

protected:
	int status_type_;
	string text_;
	Date date_of_Status_;
	Clock time_of_Status_;
};

//pictures
class Status_Picture : public Status
{
public:
	Status_Picture(string text, string ststus_picture) : Status(text) { text_ = text; picture_description_ = ststus_picture; };
	Status_Picture(string text, string ststus_picture, Date date, Clock time) : Status(text) { text_ = text; picture_description_ = ststus_picture;
	date_of_Status_ = date, time_of_Status_ = time; };
	virtual void show() const override;
	virtual void toFile(ostream& os) const override;

private:
	string picture_description_;
};

//videos
class Status_Video : public Status
{

public:
	Status_Video(string text, string ststus_video) : Status(text) { text_ = text; video_description_ = ststus_video; };
	Status_Video(string text, string ststus_video, Date date, Clock time) : Status(text) { text_ = text; video_description_ = ststus_video;
	date_of_Status_ = date, time_of_Status_ = time; };
	virtual void show() const override;
	virtual void toFile(ostream& os) const override;

private:
	string video_description_;
};

#endif // !STATUS_H