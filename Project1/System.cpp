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
		case ADD_STATUS: //3
			addNewStatus();
			break;
		case SHOW_STATUSES: //4
			showUserOrPageStatuses();
			break;
		case SHOW_FEAD:
			TenLatestFeadOfUser(); //5
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
	User Ofir("Ofir", 2, 2, 1996), Koren("Koren", 16, 5, 1997),
		Baz("Baz Light-years", 15, 10, 2021);

	Status* staOfir1 = new Status("user Ofir status 1");
	Status* staOfir2 = new Status("user Ofir status 2");
	Status* staKoren1 = new Status("user Koren status 1");
	Status* staKoren2 = new Status("user Koren status 2");
	Status* staBaz1 = new Status("user Baz status 1");
	Status* staBaz2 = new Status("user Baz status 2");
	setUser(Ofir);
	setUser(Koren);
	setUser(Baz);
	User* Ptr_Ofir = findUser(0);
	User* Ptr_Koren = findUser(1);
	User* Ptr_Baz = findUser(2);

	Ptr_Ofir->setStatus(staOfir1);
	Ptr_Ofir->setStatus(staOfir2);
	Ptr_Koren->setStatus(staKoren1);
	Ptr_Koren->setStatus(staKoren2);
	Ptr_Baz->setStatus(staBaz1);
	Ptr_Baz->setStatus(staBaz2);
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

	Status* staPage1_A = new Status("Page 1 status 1");
	Status* staPage1_B = new Status("Page 1 status 2");
	Status* staPage2_A = new Status("Page 2 status 1");
	Status* staPage2_B = new Status("Page 2 status 2");
	Status* staPage3_A = new Status("Page 3 status 1");
	Status* staPage3_B = new Status("Page 3 status 2");
	setFanPage(page1);
	setFanPage(page2);
	setFanPage(page3);
	FanPage* Ptr_page1 = findFanPage(0);
	FanPage* Ptr_page2 = findFanPage(1);
	FanPage* Ptr_page3 = findFanPage(2);
	Ptr_page1->setStatus(staPage1_A);
	Ptr_page1->setStatus(staPage1_B);
	Ptr_page2->setStatus(staPage2_A);
	Ptr_page2->setStatus(staPage2_B);
	Ptr_page3->setStatus(staPage3_A);
	Ptr_page3->setStatus(staPage3_B);
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
	string status_text, media_description, enter;
	cout << "Choose one of the following users:" << endl;
	this->showAllUsers();
	cin >> selection;
	User* user = findUser(selection - 1);
	cout << endl << "Please enter the status (Max limit 100 characters): " << endl;
	getline(cin, enter);
	getline(cin, status_text);
	cout << endl << "Would you like to add a video or a picture for your status?" << endl;
	cout << "1 - No" << endl << "2 - Picture" << endl << "3 - Video" << endl;
	cin >> selection;
	switch (selection)
	{
	case TEXT_STATUS:
		user->setStatus(new Status(status_text));
		break;
	case PICTURE_STATUS:
		media_description = getPicture();
		user->setStatus(new Status_Picture(status_text, media_description));
		break;
	case VIDEO_STATUS:
		media_description = getVideo();
		user->setStatus(new Status_Video(status_text, media_description));
		break;
	}
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
	cout << endl << "Please enter a video description:" << endl;
	getline(cin, enter);
	getline(cin, status_description);
	return status_description;
}

/// <summary>
///	create and set a status for a user
/// </summary>
void System::addFanPageStatus()
{
	int selection;
	string status_text, media_description, enter;
	cout << endl << "Choose one of the following fan pages:" << endl;
	showAllFanPages();
	cin >> selection;
	FanPage* page = findFanPage(selection - 1);
	cout << endl << "Please enter the status (Max limit 100 characters): " << endl;
	getline(cin, enter);
	getline(cin, status_text);
	cout << endl << "Would you like to add a video or a picture for your status?" << endl;
	cout << "1 - No" << endl << "2 - Picture" << endl << "3 - Video" << endl;
	cin >> selection;
	switch (selection)
	{
	case TEXT_STATUS:
		page->setStatus(new Status(status_text));
		break;
	case PICTURE_STATUS:
		media_description = getPicture();
		page->setStatus(new Status_Picture(status_text, media_description));
		break;
	case VIDEO_STATUS:
		media_description = getVideo();
		page->setStatus(new Status_Video(status_text, media_description));
		break;
	}
}

/// <summary> 4
/// Ask for a single user or fan page and show it's statustes
/// </summary>
void System::showUserOrPageStatuses()
{
	int selection;
	cout << endl;
	cout << "1 - Show statuses of a user" << endl;
	cout << "2 - Show statuses of a Fan Page" << endl;

	selection = UserOrPageCheck();
	switch (selection)
	{
	case USER_CHOISE:
		showUserStatuses();
		break;

	case PAGE_CHOISE:
		showFanPageStatuses();
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
void System::showFanPageStatuses()
{
	int selection;
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
	cout << endl << "Please choose one of the following Fan Pages: " << endl;
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
	user->showFriendsTenStatuses();
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

	if (choise > PAGE_CHOISE || choise < USER_CHOISE)
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
			cout << "Enter choise again:\n";
	}
	return selection;
}

void System::dataToFile(string filename) const
{
	ofstream file(filename, ios::trunc);
	usersToFile(file);
	fanPagesToFile(file);
	writeConnectionsToFile(file);
	file.close();
}

void System::usersToFile(ofstream& file) const
{
	int size = users_.size();
	file << size << endl;
	list<User>::const_iterator itr = users_.begin();
	for (int i = 0; i < size; i++, itr++)
	{
		file << *itr << endl;
	}
}

void System::fanPagesToFile(ofstream& file) const
{
	int size = fan_pages_.size();
	file << size << endl;
	list<FanPage>::const_iterator itr = fan_pages_.begin();
	for (int i = 0; i < size; i++, itr++)
	{
		file << *itr << endl;
	}

}

void System::initializeSystem(const string& file_name)
{
	int num_of_users, num_of_pages;
	ifstream file(file_name);
	if (file.fail())
		initiateCreation();
	else
	{
		num_of_users = fileToUsers(file);
		num_of_pages = fileToPages(file);
		makeUsersConnections(file, num_of_users);
	}
	file.close();
}

void System::writeConnectionsToFile(ofstream& file) const
{
	int size = users_.size();
	list<User>::const_iterator itr = users_.begin();
	for (int i = 0; i < size; i++,itr++)
	{
		itr->connectionsToFile(file);
	}
}

void System::makeUsersConnections(ifstream& file, int num_of_users)
{

	string friend_name, page_name, enter;
	int friends_amount, pages_amount;
	getline(file, enter);

	list<User>::iterator itr = users_.begin();
	for (int i = 0; i < num_of_users; i++, ++itr)
	{
		file >> friends_amount;
		getline(file, enter);
		for (int j = 0; j < friends_amount; j++)
		{								
			getline(file, friend_name);
			User* pfriend = findUserByName(friend_name);
			(*itr) += *pfriend;
		}
		file >> pages_amount;
		getline(file, enter);
		for (int j = 0; j < pages_amount; j++)
		{
			getline(file, page_name);
			FanPage* pfan_page = findPageByName(page_name);
			itr->addLikedPage(pfan_page);
			pfan_page->addFanToPage(*itr);
		}
	}
}


//finding a user by his name
User* System::findUserByName(string friend_name)
{
	list<User>::iterator itr = users_.begin();
	for (int i = 0; i < users_.size(); i++, ++itr)
	{
		if (itr->getName() == friend_name)
			return (&(*itr));
	}
	return nullptr;
}

//find a fan page by his name (loop until find)
FanPage* System::findPageByName(string page_name)
{
	list<FanPage>::iterator itr = fan_pages_.begin();
	for (int i = 0; i < fan_pages_.size(); i++, ++itr)
	{
		if (itr->getName() == page_name)
			return (&(*itr));
	}
	return nullptr;
}

void System::makeConnection(User& user1, User& user2)//manually added
{
	user1.addFriend(user2);
}


//initiate users from file
int System::fileToUsers(ifstream& file)
{
	int num_of_users, statuses_amount, day, month, year, seconds, minutes, hours, status_type;
	string enter, user_name, status_text, media_description;

	file >> num_of_users;

	for (int i = 0; i < num_of_users; i++)
	{
		getline(file, enter);
		getline(file, user_name);
		file >> day >> month >> year;
		users_.push_back(User(user_name, Date(day, month, year)));
		User* puser = findUser(i);
		file >> statuses_amount;
		for (int j = 0; j < statuses_amount; j++)
		{
			file >> status_type >> day >> month >> year  >> seconds >> minutes >> hours;
			getline(file, enter);
			getline(file, status_text);
			switch (status_type)
			{
			case TEXT_STATUS:
				puser->setStatus(new Status(status_text, Date(day, month, year), Clock(seconds, minutes,hours)));
				break;
			case PICTURE_STATUS:
				getline(file, enter);
				getline(file, media_description);
				puser->setStatus(new Status_Picture(status_text, media_description, Date(day, month, year), Clock(seconds, minutes, hours)));
				break;
			case VIDEO_STATUS:
				getline(file, enter);
				getline(file, media_description);
				puser->setStatus(new Status_Video(status_text, media_description, Date(day, month, year), Clock(seconds, minutes, hours)));
				break;
			}
		}
	}
	return num_of_users;
}

//initiate fan pages from file
int System::fileToPages(ifstream& file)
{
	int num_of_pages, statuses_amount, day, month, year, seconds, minutes, hours, status_type;
	string enter, page_name, status_text, media_description;

	file >> num_of_pages;

	for (int i = 0; i < num_of_pages; i++)
	{
		getline(file, enter);
		getline(file, page_name);
		fan_pages_.push_back(FanPage(page_name));
		list<FanPage>::iterator itr = fan_pages_.end();
		--itr;
		file >> statuses_amount;
		for (int j = 0; j < statuses_amount; j++)
		{
			file >> status_type >> day >> month >> year >> seconds >> minutes >> hours, status_text;
			getline(file, enter);
			getline(file, status_text);
			switch (status_type)
			{
			case TEXT_STATUS:
				itr->setStatus(new Status(status_text, Date(day, month, year), Clock(seconds, minutes, hours)));
				break;
			case PICTURE_STATUS:
				getline(file, enter);
				getline(file, media_description);
				itr->setStatus(new Status_Picture(status_text, media_description, Date(day, month, year), Clock(seconds, minutes, hours)));
				break;
			case VIDEO_STATUS:
				getline(file, enter);
				getline(file, media_description);
				itr->setStatus(new Status_Video(status_text, media_description, Date(day, month, year), Clock(seconds, minutes, hours)));
				break;
			}
		}
	}
	return num_of_pages;
}