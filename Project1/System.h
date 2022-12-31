#ifndef SYSTEM_H
#define SYSTEM_H

#include "Fan_Page.h"
#include "User.h"
#pragma warning (disable: 4996)

const int ADD_USER = 1;
const int ADD_PAGE = 2;
const int ADD_STATUS = 3;
const int SHOW_STATUSES = 4;
const int SHOW_FEAD = 5;
const int MAKE_FRIENDSHIP = 6;
const int CANCEL_FRIENDSHIP = 7;
const int ADD_FAN = 8;
const int REMOVE_PAGE = 9;
const int SHOW_ALL = 10;
const int SHOW_RELATIONS = 11;
const int EXIT = 12;

using namespace std;

class System 
{
private:
	bool exit_ = false;
	const int NOT_FOUND = -1;
	list<FanPage> fan_pages_;
	list<User> users_;

public:
	System();
	~System();
	void showMenu() const;
	void menuSelection(int selection);
	const User* selectionOfUser() const;
	const FanPage* selectionOfFanPages() const;
	void showUsersFrineds();
	void showAllFanPages() const;
	void initiateCreation();
	void initiateFanPages(User* user1, User* user2, User* user3);
	int showAllFanPagesWithFans() const;
	int findFanPageIndex(int index) const;
	const FanPage* findFanPage(int index) const;
	FanPage* findFanPage(int index);
	const User* findUser(int index) const;
	User* findUser(int index);
	bool isUserNameExist(string name) const;
	bool isPageNameExist(string name) const;
	const string initUserName() const noexcept(false);
	Date initDOB();
	int pageSelection(int num_pages_with_fans) const noexcept(false);
	int userSelection(int size) const noexcept(false);
	const string initFanPageName() const noexcept(false);
	bool isFanPageNameExist(string name) const;
	int isUserOrFanPage(int choise) const;
	int UserOrPageCheck() const;

	//1
	void addUser();
	void setUser(User& user);
	User& createUser();

	//2
	void addFanPage();
	void setFanPage(FanPage& page);
	FanPage& createFanPage();

	//3
	void addNewStatus();
	void addUserStatus();
	void addFanPageStatus();

	//4
	void showUserOrPageStatuses();
	void showsFanPageStatuses();
	void showUserStatuses() const;

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
	void showAllUsers() const;

	//11
	void showRelatedToUserOrPage() const;
	void showUsersFrineds() const;
	void showsFansOfFanPage() const;

	//12
	void setExit();
	bool getExit();
};




#endif // !SYSTEM_H
