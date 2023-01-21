#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

//prints status
void Status::show() const
{
	cout << "Text description: " << text_ << "    ";
	date_of_Status_.showDate();
	cout << " ";
	time_of_Status_.showTime();
}







Status_Picture::Status_Picture(Status_Picture& other)
{
	picture_description_ = other.picture_description_;
}

void Status_Picture::show() const
{
	cout << "Picture description: " << picture_description_ << endl;
	Status::show();
}



void Status_Video::show() const
{
	cout << "Video description: " << video_description_ << endl;
	Status::show();
}

Status::Status(Status& other)
{
	status_type_ = other.status_type_;
	text_ = other.text_;
	date_of_Status_ = other.date_of_Status_;
	time_of_Status_ = other.time_of_Status_;
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
	os << status.status_type_<<"\n";
	if (status.status_type_ != TEXT_STATUS)
		status.mediaToFile(os);
	os << status.date_of_Status_ << "\n" << status.time_of_Status_;
	os << "\n" << status.text_;
	return os;
}

void Status_Video::mediaToFile(ostream& os) const
{
	os << video_description_<<"\n";
	Status::mediaToFile(os);
}

void Status_Picture::mediaToFile(ostream& os) const
{
	os << picture_description_<<"\n";
	Status::mediaToFile(os);
}