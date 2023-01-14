#include "System.h"
#include <iostream>
#include <string>

/// <summary>
///	Prints menu
/// </summary>
void System::showMenu() const
{
	cout << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Please choose one of the followings actions below:" << endl << endl;
	cout << "1 - Add new User" << endl;
	cout << "2 - Add new Fan Page" << endl;
	cout << "3 - Add new status to a User / Fan Page" << endl;
	cout << "4 - Show all User's / Fan Page's statuses" << endl;
	cout << "5 - Show 10 latest statuses of a specific User's friends" << endl;
	cout << "6 - Create friendship between two Users" << endl;
	cout << "7 - Cancel friendship between two Users" << endl;
	cout << "8 - Make User a fan of a Fan Page" << endl;
	cout << "9 - Cancel user from being a fan of a Fan Page" << endl;
	cout << "10 - Show all Users and fan pages" << endl;
	cout << "11 - Show all User's / Fan page's connections" << endl;
	cout << "12 - Exit" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Enter a number between 1 to 12: ";
}

/// <summary>
/// Taking care of the chosen action from the menu
/// </summary>
/// <param name="selection">chosen action</param>
void System::menuSelection(int selection) noexcept
{
	try
	{
		switch (selection)
		{
		case ADD_USER: // 1
			addUser();
			break;
		case ADD_PAGE: // 2
			addFanPage();
			break;
		case ADD_STATUS:
			addNewStatus();
			break;
		case SHOW_STATUSES: //4
			showUserOrPageStatuses();
			break;
		case SHOW_FEAD:
			TenLatestFeadOfUser(); // 5
			break;
		case MAKE_FRIENDSHIP: //6
			makeFriendship();
			break;
		case CANCEL_FRIENDSHIP: //7
			cancelFriendship();
			break;
		case ADD_FAN: //8
			addFanToPage();
			break;
		case REMOVE_PAGE: //9
			removeFanOfPage();
			break;
		case SHOW_ALL: //10
			showAllUsers();
			showAllFanPages();
			break;
		case SHOW_RELATIONS: //11
			showRelatedToUserOrPage();
			break;
		case EXIT:	//12
			setExit();
			break;
		default:
			throw selectionOutOfRangeException();
		}
	}
	catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
}

/// <summary>
/// Creating the first users fan pages and their statuses 
/// </summary>
void System::initiateCreation()
{
	User Ofir("Ofir", 2, 2, 1996), Koren("Koren", 16, 8, 1997),
		Baz("Baz Light-years", 15, 10, 2021);
	Status staOfir1("user Ofir status 1"), staOfir2("user Ofir status 2"),
		staKoren1("user Koren status 1"), staKoren2("user Koren status 2")
		, staBaz1("user Baz status 1"), staBaz2("user Baz status 2");
	setUser(Ofir);
	setUser(Koren);
	setUser(Baz);
	User* Ptr_Ofir = findUser(0);
	User* Ptr_Koren = findUser(1);
	User* Ptr_Baz = findUser(2);

	Ptr_Ofir->setUserStatus(staOfir1);
	Ptr_Ofir->setUserStatus(staOfir2);
	Ptr_Koren->setUserStatus(staKoren1);
	Ptr_Koren->setUserStatus(staKoren2);
	Ptr_Baz->setUserStatus(staBaz1);
	Ptr_Baz->setUserStatus(staBaz2);
	initiateFanPages(Ptr_Ofir, Ptr_Koren, Ptr_Baz);

	(*Ptr_Ofir) += (*Ptr_Koren);
	(*Ptr_Koren) += (*Ptr_Baz);
	(*Ptr_Baz) += (*Ptr_Ofir);
}

/// <summary>
/// Creating the first fan pages and their statuses 
/// </summary>
void System::initiateFanPages(User* user1, User* user2, User* user3)
{
	FanPage page1("Page 1"), page2("Page 2"), page3("Page 3");
	Status staPage1_A("user Ofir status 1"), staPage1_B("user Ofir status 2"),
		staPage2_A("user Koren status 1"), staPage2_B("user Koren status 2")
		, staPage3_A("user Baz status 1"), staPage3_B("user Baz status 2");

	setFanPage(page1);
	setFanPage(page2);
	setFanPage(page3);
	FanPage* Ptr_page1 = findFanPage(0);
	FanPage* Ptr_page2 = findFanPage(1);
	FanPage* Ptr_page3 = findFanPage(2);
	Ptr_page1->setFanPageStatus(staPage1_A);
	Ptr_page1->setFanPageStatus(staPage1_B);
	Ptr_page2->setFanPageStatus(staPage2_A);
	Ptr_page2->setFanPageStatus(staPage2_B);
	Ptr_page3->setFanPageStatus(staPage3_A);
	Ptr_page3->setFanPageStatus(staPage3_B);
	(*Ptr_page1) += *user1;
	(*Ptr_page1) += *user2;
	(*Ptr_page2) += *user1;
	(*Ptr_page2) += *user3;
	(*Ptr_page3) += *user3;
	(*Ptr_page3) += *user2;
}

/// <summary> 1
///	get user details into a user and returns the created user
/// </summary>
/// <returns>created user</returns>
User& System::createUser()
{
	string name;
	Date date_of_birth;
	bool isValidData = false;
	while (!isValidData)
	{
		try
		{
			name = initUserName();
			date_of_birth = initDOB();
			isValidData = true;
		}
		catch (nameExistException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (unvalidDateException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (futureDateException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
		if (!isValidData)
			cout << "Enter data again.\n";
	}

	User* userPtr = new User(name, date_of_birth);
	return *userPtr;
}

//initialize a user name - runs checks if name already exists
const string System::initUserName() const noexcept(false)
{
	string name;
	cout << endl << "Enter a User's name:" << endl;
	do
	{
		getline(cin, name);
	} while (name[0] == 0); //override 'enter' previously in the headerline
	if (isUserNameExist(name))
		throw nameExistException();

	return name;
}

//runs a list of users and compares the name, return boolean if exist
bool System::isUserNameExist(string name) const
{
	list<User>::const_iterator itr = users_.begin();
	for (int index = 0; index < users_.size(); index++, itr++)
	{
		if ((*itr).getName() == name)
			return true;
	}
	return false;
}

//initialize a fan page name - checks if already exist in list
const string System::initFanPageName() const noexcept(false)
{
	string name;
	cout << "Enter a Fan-Page's name:" << endl;
	do
	{
		getline(cin, name);
	} while (name[0] == 0); //override 'enter' previously in the headerline
	if (isFanPageNameExist(name))
		throw nameExistException();

	return name;
}

//boolean page exists or not
bool System::isFanPageNameExist(string name) const
{
	list<FanPage>::const_iterator itr = fan_pages_.begin();
	for (int index = 0; index < fan_pages_.size(); index++, itr++)
	{
		if ((*itr).getName() == name)
			return true;
	}
	return false;
}

//initialize date of birth - recieve input from user (checks happening inside Date constructor)
Date System::initDOB()
{
	int day, month, year;
	cout << "Please enter a user's date of birth" << endl;
	cout << "day of birth: ";
	cin >> day;
	cout << endl << "month of birth: ";
	cin >> month;
	cout << endl << "year of birth: ";
	cin >> year;
	return Date(day, month, year);
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
FanPage& System::createFanPage()
{
	/*string name, enter;
	getline(cin, enter);
	cout << "Please enter a fan page name, and press 'Enter' afterwards(max limit : 30 characters):" << endl;
	getline(cin, name);
	FanPage* new_page = new FanPage(name);
	return *new_page;
	*/
	string name;
	bool isValidData = false;
	while (!isValidData)
	{
		try
		{
			name = initFanPageName();
			isValidData = true;
		}
		catch (nameExistException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
		if (!isValidData)
			cout << "Enter data again.\n";
	}

	FanPage* new_page = new FanPage(name);
	return *new_page;
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
	selection = UserOrPageCheck();
	switch (selection)
	{
	case USER_CHOISE:
		addUserStatus();
		break;
	case PAGE_CHOISE:
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
	string status_input, media_description, enter;
	cout << "Choose one of the following users:" << endl;
	this->showAllUsers();
	cin >> selection;
	User* user = findUser(selection - 1);
	cout << endl << "Please enter the status (Max limit 100 characters): " << endl;
	getline(cin, enter);
	getline(cin, status_input);
	cout << "would you like to add a video or a picture for your status?" << endl;
	cout << "0 - No" << endl << "1 - Picture" << endl << "2 - Video" << endl;
	cin >> selection;
	switch (selection)
	{
	case 0:
		Status new_status(status_input);
		break;
	case 1:
		media_description = getPicture();
		Status_Picture new_status_picture(status_input, media_description);
		break;
	case 2:
		media_description = getVideo();
		Status_Picture new_status_video(status_input, media_description);
	}
	user->setUserStatus(new_status);
}

string System::getPicture() const
{
	string enter, media_description;
	cout << endl << "Please enter a picture description:" << endl;
	getline(cin, enter);
	getline(cin, media_description);
	return media_description;
}

string System::getVideo() const
{
	string enter, status_description;
	cout << endl << "Please enter a picture description:" << endl;
	getline(cin, enter);
	getline(cin, status_description);
	return status_description;
}

/// <summary>
///	create and set a status for a fan page
/// </summary>
void System::addFanPageStatus()
{
	int selection;
	string status_input, enter;
	cout << endl << "Choose one of the following fan pages:" << endl;
	showAllFanPages();
	cin >> selection;
	cout << "Please enter the status (Max limit 100 characters): " << endl;
	getline(cin, enter);
	getline(cin, status_input);
	Status status(status_input);
	FanPage* ptr_page = findFanPage(selection - 1);
	ptr_page->setFanPageStatus(status);
}

/// <summary> 4
/// Ask for a single user or fan page and show it's statustes
/// </summary>
void System::showUserOrPageStatuses()
{
	int selection;
	cout << "1 - Show statuses of a user" << endl;
	cout << "2 - Show statuses of a Fan Page" << endl;

	selection = UserOrPageCheck();
	switch (selection)
	{
	case USER_CHOISE:
		showUserStatuses();
		break;

	case PAGE_CHOISE:
		showsFanPageStatuses();
		break;
	}
}

/// <summary>
/// Present all statuses of a given user
/// </summary>
void System::showUserStatuses() const
{
	int selection;
	bool isSelectionValid = false;
	while (!isSelectionValid)
	{
		cout << endl << "Please choose one of the following Users: " << endl;
		showAllUsers();
		try
		{
			selection = selectionInRange(users_.size());
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
	}
	const User* user = findUser(selection - 1);
	user->showStatuses();
}

/// <summary>
/// Present all statuses of a given fan page
/// </summary>
const User* System::selectionOfUser() const
{
	int selection;
	cout << endl << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection;
	const User* user = findUser(selection - 1);
	return user;
}

/// <summary>
/// get a fan page and show all his statuses 
/// </summary>
void System::showsFanPageStatuses()
{
	int selection;
	bool isSelectionValid = false;
	while (!isSelectionValid)
	{
		cout << endl << "Please choose one of the following Fan PAges: " << endl;
		showAllUsers();
		try
		{
			selection = selectionInRange(fan_pages_.size());
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
	}
	const User* user = findUser(selection - 1);

	const FanPage* ptr_page = selectionOfFanPages();
	ptr_page->showStatuses();

}

/// <summary>
///	get a fan page from the header-line
/// </summary>
/// <returns></returns>
const FanPage* System::selectionOfFanPages() const
{
	int selection;
	cout << endl << "Please choose one of the following FanPages: " << endl;
	showAllFanPages();
	cin >> selection;
	const FanPage* ptr_page = findFanPage(selection - 1);
	return ptr_page;
}

//5
/// <summary>
/// prints the 10 latest statuses of a user's friends
/// </summary>
void System::TenLatestFeadOfUser()
{
	int selection;
	bool isSelectionValid = false;
	while (!isSelectionValid)
	{
		cout << endl << "Please choose one of the following Users: " << endl;
		showAllUsers();
		try
		{
			selection = selectionInRange(users_.size());
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
	}
	User* user = findUser(selection - 1);
	user->showFriendsStatuses();
}


//6
/// <summary>
/// Making two users friends
/// </summary>
void System::makeFriendship()
{
	int selection1, selection2;
	bool isSelectionValid = false;
	while (!isSelectionValid)
	{
		cout << "Please choose two of the following users: " << endl;
		showAllUsers();
		try
		{
			twoSelectionsInRange(users_.size(), &selection1, &selection2);
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (FriendHimselfException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
	}
	User* user1 = findUser(selection1 - 1);
	User* user2 = findUser(selection2 - 1);
	*user1 += *user2;
}

/// <summary> 7
/// canceling two users from being friends
/// </summary>
void System::cancelFriendship()
{
	int selection;
	bool isSelectionValid = false;
	while (!isSelectionValid)
	{
		cout << endl << "Please choose one of the following Users: " << endl;
		showAllUsers();
		try
		{
			selection = selectionInRange(users_.size());
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
	}
	User* user = findUser(selection - 1);
	isSelectionValid = false;
	while (!isSelectionValid)
	{
		try
		{
			selection = friendSelection(*user);
			isSelectionValid = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (lonelyException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
		user->friendshipCancelation(selection - 1);
	}
}

//8
/// <summary>
/// Adding a user to be a fan of a page
/// not in loop so it won't get into a infinity loop (in case all users are already fans of all pages)
/// </summary>
void System::addFanToPage()
{
	int page_selection, user_selection;
	try
	{
		cout << endl << "Please choose one of the following fan pages: " << endl;
		showAllFanPages();
		page_selection = selectionInRange(fan_pages_.size());

		cout << "Please choose one of the following users: " << endl;
		showAllUsers();
		user_selection = selectionInRange(users_.size());

		FanPage* ptr_page = findFanPage(page_selection - 1);
		User* user = findUser(user_selection - 1);
		ptr_page->addFanToPage(*user);
		cout << "User " << user->getName() << " is now a fan of the page: " <<
			ptr_page->getName() << endl;
	}
	catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
	catch (alreadyFanException& exception) { cout << "Error: " << exception.what() << endl; }
	catch (...) { cout << "Unkown Error" << endl; }
}

//9
/// <summary>
/// Canceling a user to be a fan of a page
/// </summary>
void System::removeFanOfPage()
{
	int selection, index, num_pages_with_fans;
	bool isSelectionValid = false;
	num_pages_with_fans = showAllFanPagesWithFans();
	if (num_pages_with_fans)
	{
		while (!isSelectionValid)
		{
			try
			{
				selection = selectionInRange(num_pages_with_fans);
				index = findFanPageIndex(selection - 1);
				isSelectionValid = true;
			}
			catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
			catch (...) { cout << "Unkown Error" << endl; }
			if (!isSelectionValid)
				showAllFanPagesWithFans();
		}
		isSelectionValid = false;
		FanPage* ptr_page = findFanPage(index);
		while (!isSelectionValid)
		{
			cout << endl << "Please choose one of the following fans of " << ptr_page->getName() << ": " << endl;
			ptr_page->showFanPageFans();
			try
			{
				selection = selectionInRange(ptr_page->getFansSize());
				isSelectionValid = true;
			}
			catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
			catch (...) { cout << "Unkown Error" << endl; }
		}
		User* user = ptr_page->getFan(selection - 1);
		ptr_page->removeFanFromPage(selection - 1);
		user->removeLikedPage(*ptr_page);
		cout << "Fan was removed successfuly." << endl;
	}
}

int System::selectionInRange(int size) const noexcept(false)
{
	int selection;
	cin >> selection;
	if (selection > size || selection < 1)
		throw selectionOutOfRangeException();

	return selection;
}

int System::friendSelection(User& user) const noexcept(false)
{
	int size = user.getFriendsSize();

	if (size == 0)
		throw lonelyException();

	int selection;
	cout << "Please choose one of the following friends of " <<
		user.getName() << ": " << endl;
	user.showFriends();
	cin >> selection;
	if (selection > size || selection < 1)
		throw selectionOutOfRangeException();

	return selection;
}

void System::twoSelectionsInRange(int size, int* selection1, int* selection2) const noexcept(false)
{
	cin >> *selection1 >> *selection2;
	if (*selection1 > size || *selection1 < 1 || *selection2 > size || *selection2 < 1)
		throw selectionOutOfRangeException();
	if (*selection1 == *selection2)
		throw FriendHimselfException();
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
		const FanPage* ptr_page = findFanPage(foundIndex);

		if (ptr_page->getFansSize() > 0)
		{
			if (counter == counterIndex)
				return foundIndex;
			counter++;
		}
	}
}

//runs a list and get a fan page by index - const 
const FanPage* System::findFanPage(int index) const
{
	list<FanPage>::const_iterator itr = fan_pages_.begin();
	for (int i = 0; i < index; i++)
		itr++;
	return &(*itr);
}

//runs a list and get a user by index - const 
const User* System::findUser(int index) const
{
	list<User>::const_iterator itr = users_.begin();
	for (int i = 0; i < index; i++)
		itr++;
	return &(*itr);
}

//runs a list and get a fan page by index
FanPage* System::findFanPage(int index)
{
	list<FanPage>::iterator itr = fan_pages_.begin();
	for (int i = 0; i < index; i++)
		itr++;
	return &(*itr);
}

//runs a list and get a user by index
User* System::findUser(int index)
{
	list<User>::iterator itr = users_.begin();
	for (int i = 0; i < index; i++)
		itr++;
	return &(*itr);
}

//10
/// <summary>
/// Prints all users
/// </summary>
void System::showAllUsers() const
{
	int index;
	list<User>::const_iterator itr = users_.begin();
	cout << endl << "All users: " << endl;
	for (index = 0; index < users_.size(); index++, itr++)
		cout << index + 1 << " - " << itr->getName() << endl;
	cout << endl;
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
	selection = UserOrPageCheck();
	switch (selection)
	{
	case USER_CHOISE:
		showUsersFrineds();
		break;

	case PAGE_CHOISE:
		showsFansOfFanPage();
		break;
	}
}

/// <summary>
/// Prints all the friends of a user
/// </summary>
void System::showUsersFrineds() const
{
	const User* ptr_user = selectionOfUser();
	ptr_user->showFriends();
}

/// <summary>
/// Prints all the friends of a user no const
/// </summary>
void System::showUsersFrineds()
{
	const User* chosen = selectionOfUser();
	chosen->showFriends();
}

/// <summary>
/// Prints all the fans of a fan page
/// </summary>
void System::showsFansOfFanPage() const
{
	const FanPage* ptr_page = selectionOfFanPages();
	ptr_page->showFanPageFans();
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
void System::showAllFanPages() const
{
	int index;
	list<FanPage>::const_iterator itr = fan_pages_.begin();
	cout << "All fan pages: " << endl;
	for (index = 0; index < fan_pages_.size(); index++, itr++)
		cout << index + 1 << " - " << itr->getName() << endl;
}

/// <summary>
/// show all fan page entered into the system
/// </summary>
int System::showAllFanPagesWithFans() const
{
	int index, counter = 0;
	for (index = 0; index < fan_pages_.size(); index++)
	{
		const FanPage* ptr_page = findFanPage(index);

		if (ptr_page->getFansSize() > 0)
		{
			if (counter == 0)
				cout << "Please choose one of the following fan-pages:" << endl;
			counter++;
			cout << counter << " - " << ptr_page->getName() << endl;
		}
	}
	if (counter == 0)
	{
		cout << "No fan pages with fans are exist";
		return counter;
	}
	return counter;
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

int System::isUserOrFanPage(int choise) const
{

	if (choise > 2 || choise < 1)
		throw selectionOutOfRangeException();

	return choise;
}

//checks if a selection was a user or a fan page
int System::UserOrPageCheck() const
{
	int selection;
	bool isValidData = false;
	while (!isValidData)
	{
		try
		{
			cin >> selection;
			selection = isUserOrFanPage(selection);
			isValidData = true;
		}
		catch (selectionOutOfRangeException& exception) { cout << "Error: " << exception.what() << endl; }
		catch (...) { cout << "Unkown Error" << endl; }
		if (!isValidData)
			cout << "Enter choise again.\n";
	}
	return selection;
}