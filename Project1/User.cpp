#include "User.h"
#include <string.h>
#pragma warning (disable: 4996)

bool User::setUserName(char* name)
{
	this->name_ = new char[strlen(name)];
	strcpy(this->name_, name);
	return true;
}

bool User::setUserDOB(Date& DOB)
{

	if (DOB.getYear() < 1902 || DOB.getYear() > 2022)
	{
		return false;
	}
	if (DOB.getMonth() < 1 || DOB.getMonth() > 12)
	{
		return false;
	}
	if (DOB.getDay() < 1 || DOB.getDay() > 31)
	{
		return false;
	}

	this->_date_of_birth.setYear(DOB.getYear());
	this->_date_of_birth.setMonth(DOB.getMonth());
	this->_date_of_birth.setDay(DOB.getDay());
	return true;
}
char* User::getUserName() const
{
	return this->name_;

}

void User::setUserStatus(Status* status)
{
	if (this->statuses_pysical_size_ = this->statuses_logical_size_)
	{
		this->statuses_pysical_size_ *= 2;
		//new
		// coppy
		//delete
	}

	this->status_list_user_[this->statuses_logical_size_] = status;
	

}
/*
void User::showRecentFreindsStatuses() const
{
	return;

}
bool User::addFriend(User& new_friend)
{
	return;

}
bool User::friendshipCancelation(User& new_friend)
{
	return;

}
*/
Date User::getUserDOB()
{
	return this->_date_of_birth;
}
void User::showUserFriendsList() const
{

}

void User::showAllUserStatuses() const
{
	for (int index = 0; index < this->statuses_logical_size_; index++)
	{
		;
	}
}