#ifndef USER_H
#define USER_H
#include"General_Functions.h"
#include <iostream>
using namespace std;


class Status;



class User
{
public:
	bool setUserName(char* name);
	bool setUserDOB(Date& DOB);
	void setUserStatus(Status* status);
	void showAllUserStatuses() const;
	void showFriendsStatuses() const;
	void addFriend(User& new_friend);
	bool friendshipCancelation(User& new_friend);
	char* getUserName() const;
	Date getUserDOB();
	void showUserFriendsList() const;



private:
	char* name_;
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