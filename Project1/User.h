#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
#include"DateTimeUtils.h"
#include "Status.h"
#define NOT_FOUND -1
#define DEFUALT -1

class FanPage;

class User
{
public:
	User(char* name, int day, int month, int year);
	User(const char* name, int day, int month, int year);
	void setUserName(const char* name);
	void setUserStatus(Status* status);
	void showAllUserStatuses() const;
	void showFriendsStatuses() const;
	void addFriend(User* new_friend);
	void friendshipCancelation(int index);
	char* getUserName() const;
	Date getUserDOB();
	void showUsersFriends(); //const
	int findFriend(char* name);
	void addLikedFanPage(FanPage* new_page);
	
private:
	char* name_;
	FanPage** likedPages_;
	int fan_pages_physical_size_ = 1;
	int fan_pages_log_size_ = 0;
	Status** status_list_user_;
	int statuses_physical_size_ = 1;
	int statuses_log_size_ = 0;
	User** friends_;
	int friends_physical_size_ = 1;
	int friends_log_size_ = 0;
	Date date_of_birth_;
};

#endif // !USER_H