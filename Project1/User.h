#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
#include"DateTimeUtils.h"
#include "Status.h"

class FanPage;

class User
{
public:
	User(char* name, int day, int month, int year);
	User(const char* name, int day, int month, int year);
	~User();
	void setUserName(const char* name);
	void setUserStatus(Status* status);
	void showAllUserStatuses() const;
	void showFriendsStatuses() const;
	void makeFriendship(User* new_friend);
	void friendshipCancelation(int index);
	char* getUserName() const;
	void showUsersFriends() const; 
	void addLikedFanPage(FanPage* new_page);
	int findFriend(User* user) const;
	void removeLikedPage(FanPage* liked_page);
	int findLikedPage(FanPage* liked_page);
	int getFriendsLogSize();
	void showAllLikesPages() const;

private:
	char* name_;
	FanPage** liked_pages_;
	int fan_pages_physical_size_ = 1;
	int fan_pages_log_size_ = 0;
	Status** status_list_user_;
	int statuses_physical_size_ = 1;
	int statuses_log_size_ = 0;
	User** friends_;
	int friends_physical_size_ = 1;
	int friends_log_size_ = 0;
	Date date_of_birth_;
	const int NOT_FOUND = -1;
};

#endif // !USER_H