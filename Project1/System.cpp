#include "System.h"
/// <summary>
/// Dynamic allocation of system arrays
/// </summary>
System::System()
{
}

System::~System()
{
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
		addFanToPage();
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
/// Creating the first users fan pages and their statuses 
/// </summary>
void System::initiateCreation()
{
	User Ofir("Ofir", 10, 10, 1995), Koren("Koren", 10, 10, 1997),
		Baz("Baz Light-year", 7, 7, 1940);
	Status staOfir1("user Ofir status 1"), staOfir2("user Ofir status 2"),
		staKoren1("user Koren status 1"), staKoren2("user Koren status 2")
		, staBaz1("user Baz status 1"), staBaz2("user Baz status 2");
	setUser(Ofir);
	setUser(Koren);
	setUser(Baz);
	Ofir += Koren;
	Koren += Baz;
	Baz+=Ofir;
	Ofir.setUserStatus(staOfir1);
	Ofir.setUserStatus(staOfir2);
	Koren.setUserStatus(staKoren1);
	Koren.setUserStatus(staKoren2);
	Baz.setUserStatus(staBaz1);
	Baz.setUserStatus(staBaz2);
	initiateFanPages(&Ofir, &Koren, &Baz);
}

/// <summary>
/// Creating the first fan pages and their statuses 
/// </summary>
void System::initiateFanPages(User* user1,User* user2,User* user3)
{
	FanPage page1("Page 1"), page2("Page 2"), page3("Page 3");
	Status staPage1_A("user Ofir status 1"), staPage1_B("user Ofir status 2"),
		staPage2_A("user Koren status 1"), staPage2_B("user Koren status 2")
		, staPage3_A("user Baz status 1"), staPage3_B("user Baz status 2");

	setFanPage(page1);
	setFanPage(page2);
	setFanPage(page3);
	page1 += *user1;
	page1 += *user2;
	page2 += *user1;
	page2 += *user3;
	page3 += *user3;
	page3 += *user2;
}

/// <summary> 1
///	get user details into a user and returns the created user
/// </summary>
/// <returns>created user</returns>
User System::createUser()
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
	return User(name,day,month,year);
}

/// <summary>
///	calls func to create a user and another func to set it into system's pointers array of users
/// </summary>
void System::addUser()
{
	User new_user = createUser();
	setUser(new_user);
}

/// <summary>
/// get a user and set it into the system's pointers array of users
/// </summary>
/// <param name="user">a created user given to be entered</param>
void System::setUser(User& user)
{
	users_.push_back(user);
}

/// <summary>
///	create a fan-page
/// </summary>
/// <returns>created fan-page</returns>
FanPage System::createFanPage()
{
	char name[31], enter[1];
	cin.getline(enter, 1);
	cout << "Please enter a fan page name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	cin.getline(name, 30);
	return FanPage(name);
}

/// <summary>
///	set a given fan page into the system's fan-page pointers array
/// </summary>
/// <param name="page">given page to be entered</param>
void System::setFanPage(FanPage& new_page)
{
	fan_pages_.push_back(new_page);
}

/// <summary>
/// calls func's that create and set a fan-page into the system's fan-page pointers array
/// </summary>
void System::addFanPage()
{
	FanPage new_fan_page = createFanPage();
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
	Status new_status(status_input);
	list<User>::iterator itr = users_.begin();
	for (int index = 0; index < selection; index++)
		itr++;
	(*itr).setUserStatus(new_status);
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
	Status status(status_input);
	FanPage page = findFanPage(selection - 1);
	page.setFanPageStatus(status);
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
	User chosen = selectionOfUser();
	chosen.showStatuses();
}

/// <summary>
/// Present all statuses of a given fan page
/// </summary>
User& System::selectionOfUser() const
{
	int selection;
	cout << endl << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection;
	User user = findUser(selection - 1);
	return user;
}

/// <summary>
/// get a fan page and show all his statuses 
/// </summary>
void System::showsFanPageStatuses()
{
	FanPage chosen = selectionOfFanPages();
	chosen.showStatuses();

}

/// <summary>
///	get a fan page from the header-line
/// </summary>
/// <returns></returns>
FanPage& System::selectionOfFanPages() const
{
	int selection;
	cout << endl << endl << endl << "Please choose one of the following FanPages: " << endl;
	showAllFanPages();
	cin >> selection;
	FanPage page = findFanPage(selection - 1);
	return page;
}

//5

/// <summary>
/// prints the 10 latest statuses of a user's friends
/// </summary>
void System::TenLatestFeadOfUser()
{
	User chosen = selectionOfUser();
	chosen.showFriendsStatuses();

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
	User user1 = findUser(selection1);
	User user2 = findUser(selection2);
	user1 += user2;
	cout << "Friendship was successfuly created" <<endl;
}

/// <summary> 7
/// canceling two users from being friends
/// </summary>
void System::cancelFriendship()
{
	int selection1, selection2;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection1;
	User user1 = findUser(selection1 - 1);
	cout << "Please choose one of the following friends of " <<
		user1.getName() << ": " << endl;
	user1.showFriends();
	if (user1.getFriendsSize() > 0)
	{
		cin >> selection2;
		user1.friendshipCancelation(selection2 - 1);
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
void System::addFanToPage()
{
	int selection1, selection2, index;
	cout << "Please choose one of the following fan pages: " << endl;
	showAllFanPages();
	cin >> selection1;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection2;
	FanPage page = findFanPage(selection1 - 1);
	User user = findUser(selection2 - 1);
	page.addFanToPage(user);
	cout << "User "<<user.getName() << " is now a fan of the page: " <<
		page.getName() << endl;
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
		FanPage page = findFanPage(selection1 - 1);
		index = findFanPageIndex(selection1 - 1);
		cout << endl << "Please choose one of the following fans of " << page.getName() << ": " << endl;
		page.showFanPageFans();
		cin >> selection2;
		page.removeFanFromPage(selection2 - 1);
		User user = findUser(selection2 - 1);
		user.removeLikedPage(page);
		cout << "The user has been removed successfuly." << endl;
	}
}
/// <summary>
/// Finding the right index of a fan page
/// </summary>
/// <param name="counterIndex">the index of the existing fan pages</param>
/// <returns>The wanted index of a fan page</returns>
int System::findFanPageIndex(int counterIndex) const
{
	int foundIndex, counter = 0;
	for (foundIndex = 0; foundIndex < fan_pages_.size(); foundIndex++)
	{
		FanPage page = findFanPage(foundIndex);

		if (page.getFansLogSize() > 0)
		{
			if(counter == counterIndex)
				return foundIndex;
			counter++;
		}
	}
}

const FanPage& System::findFanPage(int index) const
{
	list<FanPage>::const_iterator itr = fan_pages_.begin();
	for (int i=0; i < index; i++)
		itr++;
	return *itr;
}

const User& System::findUser(int index) const 
{
	list<User>::const_iterator itr = users_.begin();
	for (int i=0; i < index; i++)
		itr++;
	return (*itr);
}

FanPage& System::findFanPage(int index) 
{
	list<FanPage>::iterator itr = fan_pages_.begin();
	for (int i=0; i < index; i++)
		itr++;
	return *itr;
}

User& System::findUser(int index) 
{
	list<User>::iterator itr = users_.begin();
	for (int i=0; i < index; i++)
		itr++;
	return (*itr);
}

//10

/// <summary>
/// Prints all users
/// </summary>
void System::showAllUsers() const
{
	int index;
	list<User>::const_iterator itr = users_.begin();
	cout << "All users: " << endl;
	for (index = 0; index < users_.size(); index++)
		cout << index + 1 << " - " << itr->getName() << endl;
}

//11

/// <summary>
/// Prints aa related to a user or a fan page
/// </summary>
void System::showRelatedToUserOrPage() const
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
void System::showUsersFrineds() const
{
	User chosen = selectionOfUser();
	chosen.showFriends();
}

/// <summary>
/// Prints all the fans of a fan page
/// </summary>
void System::showsFansOfFanPage() const
{
	FanPage chosen = selectionOfFanPages();
	chosen.showFanPageFans();
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
void System::showAllFanPages() const
{
	int index;
		list<FanPage>::const_iterator itr = fan_pages_.begin();
	cout << "All fan pages: " << endl;
	for (index = 0; index < fan_pages_.size(); index++)
		cout << index + 1 << " - " << itr->getName() << endl;
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
bool System::showAllFanPagesWithFans() const
{
	int index, counter = 0;
	for (index = 0; index < fan_pages_.size(); index++)
	{
		FanPage page = findFanPage(index - 1);
		if (page.getFansLogSize() > 0)
			counter++;
	}

	if (counter > 0)
	{
		counter = 0;
		cout << "Please choose one from the following fan pages (with fans):" << endl;
		for (index = 0; index < fan_pages_.size(); index++)
		{
			FanPage page = findFanPage(index-1);

			if (page.getFansLogSize() > 0)
			{
				counter++;
				cout << counter << " - " << page.getName() << endl;
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