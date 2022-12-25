#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string.h>
#include "Status.h"
#include "Fan_Page.h"
#include "User.h"
#include "DateTimeUtils.h"

#pragma warning (disable: 4996)

using namespace std;

class System 
{
private:
	bool exit_ = false;
	const int NOT_FOUND = -1;
	list<FanPage> all_fan_pages_;
	list<User> all_users_;

public:
	System();
	~System();
	void showMenu() const;
	void menuSelection(int selection);
	User* selectionOfUser();
	FanPage* selectionOfFanPages();
	void showAllFanPages() const;
	void initCreation();
	void initiateUsers();
	void initiateFanPages();
	bool showAllFanPagesWithFans() const;
	int findFanPageIndex(int index);
	//User

	//1
	void addUser();
	void setUser(User& user);
	User createUser();

	//2
	void addFanPage();
	void setFanPage(FanPage& page);
	FanPage createFanPage();

	//3
	void addNewStatus();
	void addUserStatus();
	void addFanPageStatus();

	//4
	void showUserOrPageStatuses();
	void showsFanPageStatuses();
	void showUserStatuses();

	//5
	void TenLatestFeadOfUser();

	//6
	void makeFriendship();

	//7
	void cancelFriendship();

	//8
	void addFanToPage();
	
	//9
	void removeFanOfPage();
	
	//10
	void showAllUsers(); //const

	//11
	void showRelatedToUserOrPage(); //const
	void showUsersFrineds();
	void showsFansOfFanPage();

	//12
	void setExit();
	bool getExit();
};




#endif // !SYSTEM_H
