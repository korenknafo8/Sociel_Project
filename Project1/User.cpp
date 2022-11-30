#include "User.h"
#include "Status.h"
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
	if (this->statuses_physical_size_ == this->statuses_logical_size_)
	{
		this->statuses_physical_size_ *= 2;
		Status** temp = new Status * [this->statuses_physical_size_];
		for (int i = 0; i < this->statuses_logical_size_; i++)
			temp[i] = this->status_list_user_[i];
		this->status_list_user_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->status_list_user_[this->statuses_logical_size_] = status;
	this->statuses_logical_size_++;
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
		this->status_list_user_[index]->show_status();
		cout << endl;
	}
}

void User::showFriendsStatuses() const
{
	for (int i = 0; i < this->friends_logical_size_; i++)
	{
		cout << "Statuses of: " << this->friends_[i]->getUserName() << endl;
		for (int j = 0; j < this->friends_[i]->statuses_logical_size_ && j < 10; j++)
		{
			cout << j << " - ";
			this->friends_[i]->status_list_user_[j]->show_status();
			cout << endl;
		}
	}	
}

void User::addFriend(User& new_friend)
{
	this->friends_[this->friends_logical_size_] = &new_friend;
	new_friend.friends_[new_friend.friends_logical_size_] = this;
}