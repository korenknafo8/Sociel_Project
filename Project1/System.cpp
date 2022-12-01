#include "System.h"
#include "General_Functions.h"



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
	cout << "10 - Show all Users" << endl;
	cout << "11 - Show all User's / Fan page's connections" << endl;
	cout << "12 - Exit" << endl;
	cout << "--------------------------------------------------------" << endl << endl;

}
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
		CreateFriendship();
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

User* System::createUser()
{
	User* new_user = new User;
	Date DOB_of_user;
	bool date_valid = false;
	char name[31],enter[1];
	int month, day, year;
	cin.getline(enter,1);
	cout << "Please enter a user name, and press 'Enter' afterwards(max limit : 30 characters) :" << endl;
	cin.getline(name, 31);
	new_user->setUserName(name);
	do
	{
	cout << "Please enter a user's date of birth" << endl;
	cout << "day of birth: ";
	cin >> day;
	DOB_of_user.setDay(day);
	cout <<endl<< "month of birth: ";
	cin >> month;
	DOB_of_user.setMonth(month);
	cout << endl << "year of birth: ";
	cin >> year;
	DOB_of_user.setYear(year);
	date_valid = new_user->setUserDOB(DOB_of_user);
	if (!date_valid)
		cout << "Date is not valid" << endl;
	} while(!date_valid);
	return new_user;
}

void System::addUser()
{
	User* new_user;
	if (this->user_log_size_ == 0)
		this->all_users_ = new User * [1];
	new_user = createUser();
	setUser(new_user);
	

}

bool System::setUser( User* user)
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
	return true;
}

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

bool System::setFanPage(FanPage* page)
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
	return true;
}

void System::addFanPage()
{
	FanPage* new_fan_page;
	if (this->fan_page_log_size_ == 0)
		this->all_fan_pages_ = new FanPage * [1];
	new_fan_page = createFanPage();
	setFanPage(new_fan_page);
}

void System::showAllUsers() //const
{
	int index;
	cout << "All users: " << endl;
	for (index = 0; index < this->user_log_size_; index++)
	{
		cout << index+1 << " - " << this->all_users_[index]->getUserName() << endl;
	}
}

void System::showAllFanPages() //const
{
	int index;
	cout << "All fan pages: " << endl;
	for (index = 0; index < this->fan_page_log_size_; index++)
	{
		cout << index + 1 << " - " << this->all_fan_pages_[index]->getFanPageName() << endl;
	}
}

void System::setExit()
{
	this->exit_ = true;
}

bool System::getExit()
{
	return this->exit_;
}

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
	status->set_content(status_input);
	this->all_users_[selection - 1]->setUserStatus(status);
}

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
	status->set_content(status_input);
	this->all_fan_pages_[selection - 1]->setFanPageStatus(status);
}

//4
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

void System::showUserStatuses()
{
	User* chosen = selectionOfUser();
	chosen->showAllUserStatuses();
}

User* System::selectionOfUser() 
{
	int selection;
	cout << "Please choose one of the following users: " << endl;
	showAllUsers();
	cin >> selection;
	return this->all_users_[selection - 1];
}


void System::showsFanPageStatuses()
{
	FanPage* chosen = selectionOfFanPages();
	chosen->showAllFanPageStatuses();

}

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
void System::CreateFriendship()
{
	int selection1, selection2;
	cout << "Please choose two of the following users: " << endl;
	showAllUsers();
	cin >> selection1 >> selection2;
	this->all_users_[selection1 - 1]->addFriend(this->all_users_[selection2 - 1]);
	cout << "Friendship was successfuly created" <<endl;
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

}

void System::showsFansOfFanPage()
{

}