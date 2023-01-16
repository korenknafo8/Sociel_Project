#ifndef SYSTEM_H
#define SYSTEM_H

#include "Fan_Page.h"
#include "User.h"

enum userFanPageEnum { USER_CHOISE = 1, PAGE_CHOISE };
enum menuSelectionEnum { ADD_USER = 1, ADD_PAGE, ADD_STATUS, SHOW_STATUSES, SHOW_FEAD, MAKE_FRIENDSHIP, CANCEL_FRIENDSHIP, ADD_FAN,
REMOVE_PAGE, SHOW_ALL, SHOW_RELATIONS, EXIT };
enum statusChoiseEnum { REGULAR_STATUS, PICTURE_STATUS, VIDEO_STATUS };

class System 
{
private:
	bool exit_ = false;
	const int NOT_FOUND = -1;
	list<FanPage> fan_pages_;
	list<User> users_;

public:
	void showMenu() const;
	void menuSelection(int selection) noexcept;
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
	const string initUserName() const noexcept(false);
	Date initDOB();
	int selectionInRange(int size) const noexcept(false);
	int friendSelection(User& user) const noexcept(false);
	void twoSelectionsInRange(int size, int* selection1, int* selection2) const noexcept(false);
	const string initFanPageName() const noexcept(false);
	bool isFanPageNameExist(string name) const;
	int isUserOrFanPage(int choise) const;
	int UserOrPageCheck() const;
	string getVideo() const;
	string getPicture() const;

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