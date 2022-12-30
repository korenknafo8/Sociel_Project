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
	string name_;
	Date date_of_birth_;
	const int NOT_FOUND = -1;
	vector<FanPage*>liked_pages_;
	vector<User*>friends_;
	list<Status>statuses_;

public:
	User(string name, int day, int month, int year);
	~User();
	void setName(const string name);
	void setUserStatus(Status status);
	void showStatuses() const;
	void showFriendsStatuses() const;
	void addFriend(User& new_friend);
	void friendshipCancelation(int index);
	string getName() const;
	void showFriends() const; 
	void addLikedFanPage(FanPage* new_page);
	int findFriend(User& user) const;
	void removeLikedPage(FanPage& liked_page);
	int findLikedPage(FanPage& liked_page) const;
	int getFriendsSize();
	void showAllLikesPages() const;
	User& operator+=(User& other);
	bool operator==(User other);
	bool operator>(User other);
};

#endif // !USER_H