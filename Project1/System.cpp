#include "System.h"

/// <summary>
///	Prints menu
/// </summary>
void System::showMenu() const
{
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Please choose one of the followings below:" << endl <<endl;
	cout << "1 - Add new User" << endl;
	cout << "2 - Add new Fan Page" << endl;
	cout << "3 - Add new status to a User / Fan Page" << endl;
	cout << "4 - Show all User's / Fan Page's statuses" << endl;
	cout << "5 - Show 10 latest statuses of a specific User's friends" << endl;
	cout << "6 - Create friendship between two Users" <<endl;
	cout << "7 - Cancel friendship between two Users" << endl;
	cout << "8 - Make User a fan of a Fan Page" << endl;
	cout << "9 - Cancel User from being a fan of a Fan Page" << endl;
	cout << "10 - Show all Users and fan pages" << endl;
	cout << "11 - Show all User's / Fan page's connections" << endl;
	cout << "12 - Exit" << endl;
	cout << "--------------------------------------------------------" << endl << endl;

}

/// <summary>
/// Taking care of the chosen action from the menu
/// </summary>
/// <param name="selection">chosen action</param>
void System::menuSelection(int selection) 
{
	switch (selection)
	{
	case 1:
		addUser();
		break;
	case 2:
		addFanPage();
		break;
	case 3:
		addNewStatus();
		break;
	case 4:
		showUserOrPageStatuses();
		break;
	case 5:
		TenLatestFeadOfUser();
		break;
	case 6:
		makeFriendship();
		break;
	case 7:
		CancelFriendship();
		break;
	case 8:
		addFanOfPage();
		break;
	case 9:
		removeFanOfPage();
		break;
	case 10:
		showAllUsers();
		showAllFanPages();
		break;
	case 11:
		showRelatedToUserOrPage();
		break;
	case 12:	
		setExit();
		break;
	}
}

/// <summary>
///	Initial creation of users, fan pages and statuses as required at task.
/// </summary>
void System::initCreation()
{
	all_users_ = new User * [3];
	all_users_[0]->setUserName("user1");
	all_users_[0]->setUserDOB(1, 1, 2001);
	all_users_[0]->setUserStatus("user1 - Status");
	all_users_[1]->setUserName("user2");
	all_users_[1]->setUserDOB(2, 2, 2002);
	all_users_[1]->setUserStatus("user2 - Status");
	all_users_[2]->setUserName("user3");
	all_users_[2]->setUserDOB(3, 3, 2003);
	all_users_[2]->setUserStatus("user3 - Status");
	createFriendship(all_users_[0], all_users_[1]);
	createFriendship(all_users_[1], all_users_[2]);


	all_fan_pages_ = new FanPage * [3];
	all_fan_pages_[0]("page1");
	all_fan_pages_[0]->addFanToPage(all_users_[0]);
	all_fan_pages_[1]("page2");
	all_fan_pages_[1]->addFanToPage(all_users_[1]);
	all_fan_pages_[2]("page3");
	all_fan_pages_[2]->addFanToPage(all_users_[2]);
}

/// <summary> 1
///	get user details into a user and returns the created user
/// </summary>
/// <returns>created user</returns>
User* System::createUser()
{
	User* new_user = new User;
	bool date_valid = false;
	char name[31],enter[1];
	int month, day, year;
	cin.getline(enter,1);
	cout << "Please enter a user name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	cin.getline(name, 31);
	new_user->setUserName(name);
	do
	{
	cout << "Please enter a user's date of birth" << endl;
	cout << "day of birth: ";
	cin >> day;
	cout <<endl<< "month of birth: ";
	cin >> month;
	cout << endl << "year of birth: ";
	cin >> year;
	Date DOB_of_user(day, month, year);
	date_valid = new_user->setUserDOB(DOB_of_user);
	if (!date_valid)
		cout << "Date is not valid" << endl;
	} while(!date_valid);
	return new_user;
}

/// <summary>
///	calls func to create a user and another func to set it into system's pointers array of users
/// </summary>
void System::addUser()
{
	User* new_user;
	new_user = createUser();
	setUser(new_user);
	

}

/// <summary>
/// get a user and set it into the system's pointers array of users
/// </summary>
/// <param name="user">a created user given to be entered</param>
void System::setUser( User* user)
{
	
	if (this->user_physical_size_ == this->user_log_size_)
	{
		this->user_physical_size_ *= 2;
		User** temp = new User * [this->user_physical_size_];
		for (int i = 0; i < this->user_log_size_; i++)
			temp[i] = this->all_users_[i];
		this->all_users_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->all_users_[this->user_log_size_] = user;
	this->user_log_size_++;
}

/// <summary>
///	create a fan-page
/// </summary>
/// <returns>created fan-page</returns>
FanPage* System::createFanPage()
{
	FanPage* new_fan_page = new FanPage;
	char name[31], enter[1];
	cin.getline(enter, 1);
	cout << "Please enter a fan page name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	cin.getline(name, 30);
	new_fan_page->setFanPageName(name);
	return new_fan_page;
}

/// <summary>
///	set a given fan page into the system's fan-page pointers array
/// </summary>
/// <param name="page">given page to be entered</param>
void System::setFanPage(FanPage* page)
{
	if (this->fan_page_physical_size_ == this->fan_page_log_size_)
	{
		this->fan_page_physical_size_ *= 2;
		FanPage** temp = new FanPage * [this->fan_page_physical_size_];
		for (int i = 0; i < this->fan_page_log_size_; i++)
			temp[i] = this->all_fan_pages_[i];
		this->all_fan_pages_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->all_fan_pages_[this->fan_page_log_size_] = page;
	this->fan_page_log_size_++;
}

/// <summary>
/// calls func's that create and set a fan-page into the system's fan-page pointers array
/// </summary>
void System::addFanPage()
{
	FanPage* new_fan_page;
	if (this->fan_page_log_size_ == 0)
		this->all_fan_pages_ = new FanPage * [1];
	new_fan_page = createFanPage();
	setFanPage(new_fan_page);
}

/// <summary>
///	create and set a new status to a user or a fan page
/// </summary>
void System::addNewStatus()
{
	int selection;
	cout << "1 - Add status for a user" << endl;
	cout << "2 - Add status for a Fan Page" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		addUserStatus();
		break;
	case 2:
		addFanPageStatus();
		break;
	}
}

/// <summary>
///	create and set a status for a user
/// </summary>
void System::addUserStatus()
{
	Status* status = new Status;
	int selection;
	char status_input[101], enter[1];
	cout << "Choose one of the following users:" << endl;
	this->showAllUsers();
	cin >> selection;
	cin.getline(enter, 1);
	cout << "Please enter the status (Max limit 100 characters): " << endl;
	cin.getline(status_input, 101);
	status->setContent(status_input);
	this->all_users_[selection - 1]->setUserStatus(status);
}

/// <summary>
///	create and set a status for a fan page
/// </summary>
void System::addFanPageStatus()
{
	Status* status = new Status;
	int selection;
	char status_input[101];
	cout << "Choose one of the following users:" << endl;
	this->showAllUsers();
	cin >> selection;
	cout << "Please enter the status (Max limit 100 characters): " << endl;
	cin.getline(status_input, 101);
	status->setContent(status_input);
	this->all_fan_pages_[selection - 1]->setFanPageStatus(status);
}

/// <summary> 4
/// Ask for a single user or fan page and show it's statustes
/// </summary>
void System::showUserOrPageStatuses()
{
	int selection;
	cout << "1 - Show statuses of a user" << endl;
	cout << "2 - Show statuses of a Fan Page" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		showUserStatuses();
		break;

	case 2:
		showsFanPageStatuses();
		break;
	}
}

/// <summary>
/// Present all statuses of a given user
/// </summary>
void System::showUserStatuses()
{
	User* chosen = selectionOfUser();
	chosen->showAllUserStatuses();
}

/// <summary>
/// Present all statuses of a given fan page
/// </summary>
User* System::selectionOfUser() 
{
	int selection;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection;
	return this->all_users_[selection - 1];
}

/// <summary>
/// get a fan page and show all his statuses 
/// </summary>
void System::showsFanPageStatuses()
{
	FanPage* chosen = selectionOfFanPages();
	chosen->showAllFanPageStatuses();

}

/// <summary>
///	get a fan page from the header-line
/// </summary>
/// <returns></returns>
FanPage* System::selectionOfFanPages()
{
	int selection;
	cout << "Please choose one of the following FanPages: " << endl;
	showAllFanPages();
	cin >> selection;
	return this->all_fan_pages_[selection - 1];
}

//5
void System::TenLatestFeadOfUser()
{
	User* chosen = selectionOfUser();
	chosen->showFriendsStatuses();

}

//6
void System::makeFriendship()
{
	int selection1, selection2;
	cout << "Please choose two of the following users: " << endl;
	showAllUsers();
	cin >> selection1 >> selection2;
	createFriendship(all_users_[selection1 - 1], all_users_[selection2 - 1]);
	cout << "Friendship was successfuly created" <<endl;
}

/// <summary>
/// Create friendship between two given users
/// </summary>
void System::createFriendship(User* user1, User* user2)
{
	user1->addFriend(user2);
	user2->addFriend(user1);
}

//7
void System::CancelFriendship()
{
	int selection1, selection2;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection1;
	cout << "Please choose one of the following friends of " << 
		this->all_users_[selection1 - 1]->getUserName() << ": " << endl;
	this->all_users_[selection1 - 1]->showUsersFriends();
	cin >> selection2;
	this->all_users_[selection1 - 1]->friendshipCancelation(selection2 -1);
	cout << "Friendship cancelation has been done successfuly." << endl;
}

//8
void System::addFanOfPage()
{
	int selection1, selection2;
	cout << "Please choose one of the following fan pages: " << endl;
	showAllFanPages();
	cin >> selection1;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection2;
	this->all_fan_pages_[selection1 - 1]->addFanToPage(this->all_users_[selection2 - 1]);
	cout << "User " << this->all_users_[selection2 - 1] << "is now a fan of the page: " <<
		this->all_fan_pages_[selection1 -1]->getFanPageName() << endl;
}

//9
void System::removeFanOfPage()
{
	int selection1, selection2;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection1;
	cout << "Please choose one of the following fans of " << 
		this->all_fan_pages_[selection1 - 1]->getFanPageName() << ": " << endl;
	this->all_fan_pages_[selection1 - 1]->showFanPageFans();
	cin >> selection2;
	this->all_fan_pages_[selection1 - 1]->removeFanFromPage(this->all_users_[selection2 - 1]);
	cout << "Fan has been removed from fan page's list successfuly." << endl;
}

//10
void System::showAllUsers() //const
{
	int index;
	cout << "All users: " << endl;
	for (index = 0; index < this->user_log_size_; index++)
	{
		cout << index + 1 << " - " << this->all_users_[index]->getUserName() << endl;
	}
}

//11
void System::showRelatedToUserOrPage() //const
{
	int selection;
	cout << "1 - Show friends of a user" << endl;
	cout << "2 - Show fans of a Fan Page" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		showUsersFrineds();
		break;

	case 2:
		showsFansOfFanPage();
		break;
	}
}


void System::showUsersFrineds()
{
	User* chosen = selectionOfUser();
	chosen->showUsersFriends();
}

void System::showsFansOfFanPage()
{
	FanPage* chosen = selectionOfFanPages();
	chosen->showFanPageFans();
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
void System::showAllFanPages() //const
{
	int index;
	cout << "All fan pages: " << endl;
	for (index = 0; index < this->fan_page_log_size_; index++)
	{
		cout << index + 1 << " - " << this->all_fan_pages_[index]->getFanPageName() << endl;
	}
}

//12
void System::setExit()
{
	this->exit_ = true;
}

bool System::getExit()
{
	return this->exit_;
}