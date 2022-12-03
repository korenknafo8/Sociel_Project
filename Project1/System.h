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
	int user_physical_size_ = 4;
	int user_log_size_ = 0;
	int fan_page_physical_size_ = 4;
	int fan_page_log_size_ = 0;
	bool exit_ = false;
	User** all_users_;
	FanPage** all_fan_pages_;

public:
	System();
	//general
	void showMenu() const;
	void menuSelection(int selection);
	User* selectionOfUser();
	FanPage* selectionOfFanPages();
	void showAllFanPages() const;
	void initCreation();
	void initiateUsers();
	void initiateFanPages();
	bool showAllFanPagesWithFans() const;
	int findFanPage(int index);

	//1
	void addUser();
	void setUser(User* user);
	User* createUser();

	//2
	void addFanPage();
	void setFanPage(FanPage* page);
	FanPage* createFanPage();

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
	void createFriendship(User* user1, User* user2);

	//7
	void cancelFriendship();

	//8
	void addFanOfPage();
	
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
