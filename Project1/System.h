#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string.h>
#include "Status.h"
#include "Fan_Page.h"
#include "User.h"
#pragma warning (disable: 4996)

using namespace std;

class System 
{
public:
	//general
	void showMenu() const;
	void menuSelection(int selection);
	User* selectionOfUser();

	//1
	void addUser();
	bool setUser(const User* user);
	User* createUser();

	//2
	void addFanPage();
	bool setFanPage(const FanPage* page);
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


	//10
	void showAllUsers(); //const

	void setExit();
	bool getExit();

private:
	int user_pysical_size = 1;
	int user_log_size = 0;
	int fan_page_pysical_size = 1;
	int fan_page_log_size = 0;
	bool _exit = false;
	User** all_users;
	FanPage** all_pages;

};




#endif // !SYSTEM_H
