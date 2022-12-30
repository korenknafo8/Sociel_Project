#ifndef SYSTEM_H
#define SYSTEM_H

#include "Fan_Page.h"
#include "User.h"

#pragma warning (disable: 4996)

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
	bool showAllFanPagesWithFans() const;
	int findFanPageIndex(int index) const;
	const FanPage* findFanPage(int index) const;
	FanPage* findFanPage(int index);
	const User* findUser(int index) const;
	User* findUser(int index);
	//User

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
