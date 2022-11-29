#ifndef USER_H
#define USER_H
#include"General_Functions.h"

class Status;



class User
{
public:
	bool setUserName(char* name);
	bool setUserDOB(Date& DOB);
	void setUserStatus(Status* status);
	void showAllUserStatuses() const;
	void showRecentFreindsStatuses() const;
	bool addFriend(User& new_friend);
	bool friendshipCancelation(User& new_friend);
	char* getUserName() const;
	Date getUserDOB();
	void showUserFriendsList() const;


private:
	char* name_;
	Status** status_list_user_;
	int statuses_pysical_size_ = 1;
	int statuses_logical_size_ = 0;
	User** _friends;
	Date _date_of_birth;
	//friends feed
};



#endif // !USER_H