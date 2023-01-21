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
	Status(const string text, Date date, Clock time, int status_type = 0) { text_ = text; date_of_Status_ = date, time_of_Status_ = time; };
	bool operator!=(Status other);
	bool operator==(Status other);
	virtual void show() const;
	virtual void mediaToFile(ostream& os) const { };
	friend ostream& operator<<(ostream& os, const Status& p);

protected:
	int status_type_ = 1;
	string text_;
	Date date_of_Status_;
	Clock time_of_Status_;
};

//pictures
class Status_Picture : public Status
{
public:
	Status_Picture(string text, string ststus_picture) : Status(text) { text_ = text;
	picture_description_ = ststus_picture; status_type_ = PICTURE_STATUS; };
	Status_Picture(string text, string ststus_picture, Date date, Clock time) : Status(text) { text_ = text;
	picture_description_ = ststus_picture; date_of_Status_ = date, time_of_Status_ = time; status_type_ = PICTURE_STATUS; };
	virtual void show() const override;
	virtual void mediaToFile(ostream& os) const override;

private:
	string picture_description_;
};

//videos
class Status_Video : public Status
{

public:
	Status_Video(string text, string ststus_video) : Status(text) { text_ = text; 
	video_description_ = ststus_video; status_type_ = VIDEO_STATUS; };
	Status_Video(string text, string ststus_video, Date date, Clock time) : Status(text) { text_ = text;
	video_description_ = ststus_video; date_of_Status_ = date, time_of_Status_ = time; status_type_ = VIDEO_STATUS;	};
	virtual void show() const override;
	virtual void mediaToFile(ostream& os) const override;

private:
	string video_description_;
};

#endif // !STATUS_H