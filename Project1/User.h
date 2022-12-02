#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
#include"DateTimeUtils.h"
#include "Status.h"

using namespace std;


class FanPage;


class User
{
public:
	bool setUserName(char* name);
	bool setUserDOB(Date& DOB);
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
	int fan_pages_logical_size_ = 0;
	Status** status_list_user_;
	int statuses_physical_size_ = 1;
	int statuses_logical_size_ = 0;
	User** friends_;
	int friends_physical_size_ = 1;
	int friends_logical_size_ = 0;
	Date _date_of_birth;
	//friends feed
};


#endif // !USER_H