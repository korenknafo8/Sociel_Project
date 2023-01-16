#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

//prints status
void Status::show() const
{
	cout << status_text_ << "    ";
	date_of_Status_.showDate();
	cout << " ";
	time_of_Status_.showTime();
}

void Status_Picture::show() const
{
	Status::show();
	cout << picture_description_ << endl;
}

void Status_Video::show() const
{
	Status::show();
	cout << video_description_ << endl;
}

bool Status::operator!=(Status other)
{
	return status_text_ != other.status_text_;
}

bool Status::operator==(Status other)
{
	return status_text_ == other.status_text_;
}