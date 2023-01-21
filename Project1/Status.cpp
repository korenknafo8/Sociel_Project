#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

//prints status
void Status::show() const
{
	cout << text_ << "    ";
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
	return text_ != other.text_;
}

bool Status::operator==(Status other)
{
	return text_ == other.text_;
}

ostream& operator<<(ostream& os, const Status& status)
{
	os << status.status_type_ <<  status.date_of_Status_ << status.time_of_Status_;
	os << "\n" << status.text_;
	if (status.status_type_ != TEXT_STATUS)
		status.toFile(os);
	return os;
}

void Status_Video::toFile(ostream& os) const
{
	os << "\n" << video_description_;
}

void Status_Picture::toFile(ostream& os) const
{
	os << "\n" << picture_description_;
}