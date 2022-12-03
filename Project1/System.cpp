#include "System.h"
/// <summary>
/// Dynamic allocation of system arrays
/// </summary>
System::System()
{
	all_users_ = new User * [user_physical_size_];
	all_fan_pages_ = new FanPage * [fan_page_physical_size_];
}

System::~System()
{
	for (int i = 0; i < user_log_size_; i++)
		delete[] all_users_[i];
	for (int i = 0; i < fan_page_log_size_; i++)
		delete[] all_fan_pages_[i];
	delete[] all_users_;
	delete[] all_fan_pages_;

}

/// <summary>
///	Prints menu
/// </summary>
void System::showMenu() const
{
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Please choose one of the followings actions below:" << endl <<endl;
	cout << "1 - Add new User" << endl;
	cout << "2 - Add new Fan Page" << endl;
	cout << "3 - Add new status to a User / Fan Page" << endl;
	cout << "4 - Show all User's / Fan Page's statuses" << endl;
	cout << "5 - Show 10 latest statuses of a specific User's friends" << endl;
	cout << "6 - Create friendship between two Users" <<endl;
	cout << "7 - Cancel friendship between two Users" << endl;
	cout << "8 - Make User a fan of a Fan Page" << endl;
	cout << "9 - Cancel user from being a fan of a Fan Page" << endl;
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
		cancelFriendship();
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
	initiateUsers();
	initiateFanPages();
}
/// <summary>
/// Creating the first users and their statuses 
/// </summary>
void System::initiateUsers()
{
	setUser(new User("Ofir", 10, 10, 1995));
	setUser(new User("Koren", 10, 10, 1997));
	setUser(new User("Jimmy", 7, 7, 1940));
	all_users_[0]->setUserStatus(new Status("user Ofir status 1"));
	all_users_[0]->setUserStatus(new Status("user Ofir status 2"));
	all_users_[1]->setUserStatus(new Status("user Koren status 1"));
	all_users_[1]->setUserStatus(new Status("user Koren status 2"));
	all_users_[2]->setUserStatus(new Status("user Jimmy status 1"));
	all_users_[2]->setUserStatus(new Status("user Jimmy status 2"));
	createFriendship(all_users_[0], all_users_[1]);
	createFriendship(all_users_[1], all_users_[2]);
	createFriendship(all_users_[2], all_users_[0]);
}
/// <summary>
/// Creating the first fan pages and their statuses 
/// </summary>
void System::initiateFanPages()
{
	setFanPage(new FanPage("Page 1"));
	setFanPage(new FanPage("Page 2"));
	setFanPage(new FanPage("Page 3"));
	all_fan_pages_[0]->setFanPageStatus(new Status("Page 1 status 1"));
	all_fan_pages_[0]->setFanPageStatus(new Status("Page 1 status 2"));
	all_fan_pages_[1]->setFanPageStatus(new Status("Page 2 status 1"));
	all_fan_pages_[1]->setFanPageStatus(new Status("Page 2 status 2"));
	all_fan_pages_[2]->setFanPageStatus(new Status("Page 3 status 1"));
	all_fan_pages_[2]->setFanPageStatus(new Status("Page 3 status 2"));
	all_fan_pages_[0]->addFanToPage(all_users_[0]);
	all_fan_pages_[0]->addFanToPage(all_users_[1]);
	all_fan_pages_[1]->addFanToPage(all_users_[1]);
	all_fan_pages_[1]->addFanToPage(all_users_[2]);
	all_fan_pages_[2]->addFanToPage(all_users_[2]);
	all_fan_pages_[2]->addFanToPage(all_users_[0]);
}

/// <summary> 1
///	get user details into a user and returns the created user
/// </summary>
/// <returns>created user</returns>
User* System::createUser()
{
	
	char name[31],enter[1];
	int month, day, year;
	cin.getline(enter,1);
	cout << "Please enter a user name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	cin.getline(name, 31);
	cout << "Please enter a user's date of birth" << endl;
	cout << "day of birth: ";
	cin >> day;
	cout <<endl<< "month of birth: ";
	cin >> month;
	cout << endl << "year of birth: ";
	cin >> year;
	return new User(name,day,month,year);
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
void System::setUser(User* user)
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
	this->all_users_[this->user_log_size_++] = user;
}

/// <summary>
///	create a fan-page
/// </summary>
/// <returns>created fan-page</returns>
FanPage* System::createFanPage()
{
	char name[31], enter[1];
	cin.getline(enter, 1);
	cout << "Please enter a fan page name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	cin.getline(name, 30);
	return new FanPage(name);
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
	int selection;
	char status_input[101], enter[1];
	cout << "Choose one of the following users:" << endl;
	this->showAllUsers();
	cin >> selection;
	cin.getline(enter, 1);
	cout << "Please enter the status (Max limit 100 characters): " << endl;
	cin.getline(status_input, 101);
	this->all_users_[selection - 1]->setUserStatus(new Status(status_input));
}

/// <summary>
///	create and set a status for a fan page
/// </summary>
void System::addFanPageStatus()
{
	int selection;
	char status_input[101], enter[1];
	cout << "Choose one of the following fan pages:" << endl;
	showAllFanPages();
	cin >> selection;
	cin.getline(enter, 1);
	cout << "Please enter the status (Max limit 100 characters): " << endl;
	cin.getline(status_input, 101);
	all_fan_pages_[selection - 1]->setFanPageStatus(new Status(status_input));
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
	cout << endl << "Please choose one of the following users: " << endl;
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
	cout << endl << endl << endl << "Please choose one of the following FanPages: " << endl;
	showAllFanPages();
	cin >> selection;
	return all_fan_pages_[selection - 1];
}

//5

/// <summary>
/// prints the 10 latest statuses of a user's friends
/// </summary>
void System::TenLatestFeadOfUser()
{
	User* chosen = selectionOfUser();
	chosen->showFriendsStatuses();

}

//6

/// <summary>
/// Making two users friends
/// </summary>
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

/// <summary>
/// canceling two users from being friends
/// </summary>
void System::cancelFriendship()
{
	int selection1, selection2;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection1;
	cout << "Please choose one of the following friends of " <<
		all_users_[selection1 - 1]->getUserName() << ": " << endl;
	all_users_[selection1 - 1]->showUsersFriends();
	if (all_users_[selection1 - 1]->getFriendsLogSize() > 0)
	{
		cin >> selection2;
		this->all_users_[selection1 - 1]->friendshipCancelation(selection2 - 1);
		cout << "Friendship cancelation has been done successfuly." << endl;
	}
	else
	{
		cout << "User has no friends to cancel";
	}
}

//8

/// <summary>
/// Adding a user to be a fan of a page
/// </summary>
void System::addFanOfPage()
{
	int selection1, selection2;
	cout << "Please choose one of the following fan pages: " << endl;
	showAllFanPages();
	cin >> selection1;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection2;
	all_fan_pages_[selection1 - 1]->addFanToPage(all_users_[selection2 - 1]);
	cout << "User " << all_users_[selection2 - 1]->getUserName() << " is now a fan of the page: " <<
		all_fan_pages_[selection1 -1]->getFanPageName() << endl;
}

//9

/// <summary>
/// Canceling a user to be a fan of a page
/// </summary>
void System::removeFanOfPage()
{
	int selection1, selection2, index;
	if (showAllFanPagesWithFans())
	{
	cin >> selection1;
	index = findFanPage(selection1 - 1);
		cout << endl << "Please choose one of the following fans of " << all_fan_pages_[index]->getFanPageName() << ": " << endl;
		all_fan_pages_[index]->showFanPageFans();
		cin >> selection2;
		all_fan_pages_[index]->removeFanFromPage(selection2 - 1);
		all_users_[selection2 - 1]->removeLikedPage(all_fan_pages_[index]->getFanPageName());
		cout << "The user has been removed successfuly." << endl;
	}
}
/// <summary>
/// Finding the right index of a fan page
/// </summary>
/// <param name="counterIndex">the index of the existing fan pages</param>
/// <returns>The wanted index of a fan page</returns>
int System::findFanPage(int counterIndex)
{
	int foundIndex, counter = 0;
	for (foundIndex = 0; foundIndex < fan_page_log_size_; foundIndex++)
	{
		if (all_fan_pages_[foundIndex]->getFansLogSize() > 0)
		{
			if(counter == counterIndex)
				return foundIndex;
			counter++;
		}
	}
}

//10

/// <summary>
/// Prints all users
/// </summary>
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

/// <summary>
/// Prints aa related to a user or a fan page
/// </summary>
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

/// <summary>
/// Prints all the friends of a user
/// </summary>
void System::showUsersFrineds()
{
	User* chosen = selectionOfUser();
	chosen->showUsersFriends();
}

/// <summary>
/// Prints all the fans of a fan page
/// </summary>
void System::showsFansOfFanPage()
{
	FanPage* chosen = selectionOfFanPages();
	chosen->showFanPageFans();
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
void System::showAllFanPages() const
{
	int index;
	cout << "All fan pages: " << endl;
	for (index = 0; index < this->fan_page_log_size_; index++)
	{
		cout << index + 1 << " - " << this->all_fan_pages_[index]->getFanPageName() << endl;
	}
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
bool System::showAllFanPagesWithFans() const
{
	int index, counter = 0;
	for (index = 0; index < fan_page_log_size_; index++)
	{
		if (all_fan_pages_[index]->getFansLogSize() > 0)
			counter++;
	}

	if (counter > 0)
	{
		counter = 0;
		cout << "Please choose one from the following fan pages (with fans):" << endl;
		for (index = 0; index < this->fan_page_log_size_; index++)
		{
			if (all_fan_pages_[index]->getFansLogSize() > 0)
			{
				counter++;
				cout << counter << " - " << this->all_fan_pages_[index]->getFanPageName() << endl;
			}
		}
		return true;
	}
	else
	{
		cout << "No fan pages with fans are exist";
		return false;
	}
}

//12

/// <summary>
/// Puting the "true" value in the exit variable
/// </summary>
void System::setExit()
{
	this->exit_ = true;
}

/// <summary>
/// Getting the value of a bool variable
/// </summary>
/// <returns></returns>
bool System::getExit()
{
	return this->exit_;
}