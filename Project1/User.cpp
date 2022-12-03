#include "User.h"
using namespace std;
#pragma warning (disable: 4996)
#include "Fan_Page.h"


User::User(char* name, int day, int month, int year) 
{
	setUserName(name);
	friends_ = new User * [friends_physical_size_];
	status_list_user_ = new Status * [statuses_physical_size_];
	liked_pages_ = new FanPage * [fan_pages_physical_size_];
	date_of_birth_ = Date(day, month, year);
}

User::User(const char* name, int day, int month, int year)
{
	setUserName(name);
	friends_ = new User * [friends_physical_size_];
	status_list_user_ = new Status * [statuses_physical_size_];
	liked_pages_ = new FanPage * [fan_pages_physical_size_];
	date_of_birth_ = Date(day, month, year);
}

void User::setUserName(const char* name)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

char* User::getUserName() const
{
	return this->name_;

}

/// <summary>
/// Set a status for a given user
/// </summary>
/// <param name="status">status</param>
void User::setUserStatus(Status* status)
{
	if (statuses_physical_size_ == statuses_log_size_)
	{
		statuses_physical_size_ *= 2;
		Status** temp = new Status * [statuses_physical_size_];
		for (int i = 0; i < statuses_log_size_; i++)
			temp[i] = status_list_user_[i];
		status_list_user_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	status_list_user_[statuses_log_size_++] = status;
}

Date User::getUserDOB()
{
	return date_of_birth_;
}

/// <summary>
/// 
/// </summary>
void User::showAllUserStatuses() const
{
	for (int index = 0; index < statuses_log_size_; index++)
	{
		status_list_user_[index]->showStatus();
		cout << endl;
	}
}

/// <summary>
/// Present all/10 statuses of the friends of a single user
/// </summary>
void User::showFriendsStatuses() const
{
	for (int i = 0; i < this->friends_log_size_; i++)
	{
		cout << "Statuses of: " << this->friends_[i]->getUserName() << endl;
		for (int j = 0; j < this->friends_[i]->statuses_log_size_ && j < 10; j++)
		{
			cout << j << " - ";
			this->friends_[i]->status_list_user_[j]->showStatus();
			cout << endl;
		}
	}	
}

/// <summary>
/// 
/// </summary>
/// <param name="new_friend"></param>
void User::addFriend(User* new_friend)
{
	if (this->friends_log_size_ == this->friends_physical_size_)
	{
		this->friends_physical_size_ *=2;
		User** temp = new User * [this->friends_physical_size_];
		for (int i = 0; i < this->friends_log_size_; i++)
			temp[i] = this->friends_[i];
		this->friends_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	else if (this->friends_log_size_ == 0)
		this->friends_ = new User * [1];
	this->friends_[this->friends_log_size_++] = new_friend;
}

void User::showUsersFriends() //const
{
	int index;
	if (this->friends_log_size_ != 0) 
	{
		cout << "All friends: " << endl;
		for (index = 0; index < this->friends_log_size_; index++)
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


/// <summary>
/// Cancel friendship between a user and a given user
/// </summary>
/// <param name="index">Index at the friend's list of the other friend</param>
void User::friendshipCancelation(int index)
{
	int foundIndex = this->friends_[index]->findFriend(this->name_); //in this case allways find the user
	friends_[index]->friends_[foundIndex] = 
		friends_[index]->friends_[friends_[index]->friends_log_size_--];
	friends_[index] = friends_[friends_log_size_--];
}


/// <summary>
/// Locate a friend of user in his friend's pointer array and returns it's index
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
int User::findFriend(char* name)
{
	int index;
	for (index = 0; index < this->friends_log_size_; index++)
	{
		if (strcmp(name, this->friends_[index]->name_) == 0)
		{
			return index;
		}
	}
	return NOT_FOUND;
}

void User::removeLikedPage(char* name)
{
	int foundIndex = findLikedPage(name);
	liked_pages_[foundIndex] = liked_pages_[--fan_pages_log_size_];
}

int User::findLikedPage(char* name)
{
	int index;
	for (index = 0; index < fan_pages_log_size_; index++)
	{
		if (strcmp(name, liked_pages_[index]->getFanPageName()) == 0)
		{
			return index;
		}
	}
	return NOT_FOUND;
}

/// <summary>
/// 
/// </summary>
/// <param name="new_page">name of page to add</param>
void User::addLikedFanPage(FanPage* new_page)
{
	if(this->fan_pages_log_size_ == this->fan_pages_physical_size_)
	{
	this->fan_pages_physical_size_ *= 2;
	FanPage** temp = new FanPage * [this->fan_pages_physical_size_];
	for (int i = 0; i < this->fan_pages_log_size_; i++)
		temp[i] = this->liked_pages_[i];
	this->liked_pages_ = temp;
	temp = nullptr;
	delete[] temp;
	}
	else if (this->fan_pages_log_size_ == 0)
		this->liked_pages_ = new FanPage * [1];

	this->liked_pages_[this->fan_pages_log_size_++] = new_page;
}

int User::getFriendsLogSize()
{
	return friends_log_size_;
}