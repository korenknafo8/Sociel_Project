#ifndef USER_H
#define USER_H

#include <iostream>
#include"DateTimeUtils.h"
#include "Status.h"
#include <list>
#include <vector>
#include <string.h>
using namespace std;

class FanPage;

class User
{
private:
	vector<FanPage*>liked_pages_;
	vector<User*>friends_;
	vector<Status*>statuses_;
	string name_;
	Date date_of_birth_;
	const int NOT_FOUND = -1;

public:
	User(string name, int day, int month, int year); //for init
	User(string name, Date date_of_birth); //for add user
	User(const User& other);
	~User();
	void setName(const string& name);
	void setStatus(Status* status);
	void setStatus(Status_Picture* status);
	void setStatus(Status_Video* status);
	void showStatuses() const;
	void show10LatestStatuses() const;
	void showFriendsTenStatuses() const;
	void addFriend(User& new_friend);
	void friendshipCancelation(int index);
	string getName() const;
	void showFriends() const; 
	void addLikedPage(FanPage* new_page);
	int findFriend(User& user) const;
	void removeLikedPage(FanPage& liked_page);
	int findLikedPage(FanPage& liked_page) const;
	int getFriendsSize();
	void showAllLikesPages() const;
	User& operator+=(User& other);
	bool operator==(User& other);
	bool operator>(User& other);
	bool operator>(FanPage& other);
	friend ostream& operator<<(std::ostream& os, const User& user);
	void connectionsToFile(ofstream& file) const;
};

#endif // !USER_H