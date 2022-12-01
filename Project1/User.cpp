#include "User.h"
#include "Status.h"
#include <string.h>
#define NOT_FOUND -1

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

Date User::getUserDOB()
{
	return this->_date_of_birth;
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

void User::addFriend(User* new_friend)
{
	if (this->friends_logical_size_ == 0)
		this->friends_ = new User * [1];
	if (this->friends_logical_size_ == this->friends_physical_size_)
	{
		this->friends_physical_size_ *=2;
		User** temp = new User * [this->friends_physical_size_];
		for (int i = 0; i < this->friends_logical_size_; i++)
			temp[i] = this->friends_[i];
		this->friends_ = temp;
		temp = nullptr;
	}
	this->friends_[this->friends_logical_size_++] = new_friend;
	if (new_friend->friends_logical_size_ == 0)
		new_friend->friends_ = new User * [1];
	new_friend->friends_[new_friend->friends_logical_size_++] = this;

}

void User::showUsersFriends() //const
{
	int index;
	if (this->friends_logical_size_ != 0) 
	{
		cout << "All friends: " << endl;
		for (index = 0; index < this->friends_logical_size_; index++)
		{
			if (this->friends_[index] != NULL)
				cout << index + 1 << " - " << this->friends_[index]->getUserName() << endl;
		}
	}
	else 
	{
		cout << "User " << this->getUserName() << "has no friends to show." << endl;
	}
}

void User::friendshipCancelation(int index)
{
	int foundIndex = this->friends_[index]->findFriend(this->name_); //in this case allways find the user
	this->friends_[index]->friends_[foundIndex] = 
		this->friends_[index]->friends_[this->friends_[index]->friends_logical_size_--];
	this->friends_[index] = this->friends_[this->friends_logical_size_--];
}

int User::findFriend(char* name)
{
	int index;
	for (index = 0; index < this->friends_logical_size_; index++)
	{
		if (strcmp(name, this->friends_[index]->name_) == 0)
		{
			return index;
		}
	}
	return NOT_FOUND;
}