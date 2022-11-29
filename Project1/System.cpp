#include "System.h"
#include "General_Functions.h"



void System::showMenu() const
{
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
	cout << "--------------------------------------------------------" << endl<<endl;

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
		//addNewStatus();
		break;
	case 6:
		//addNewStatus();
		break;
	case 7:
		//addNewStatus();
		break;
	case 8:
		//addNewStatus();
		break;
	case 9:
		//addNewStatus();
		break;
	case 10:
		showAllUsers();
		break;
	case 11:
		//addNewStatus();
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

	new_user = createUser();
	setUser(new_user);
	

}

bool System::setUser(const User* user)
{
	if (user_pysical_size == user_log_size)
	{
		user_pysical_size *= 2;
		//new
		//memcopy
	}
	//all_users[log_size] = user;
	user_log_size++;
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

bool System::setFanPage(const FanPage* page)
{
	if (user_pysical_size == user_log_size)
	{
		user_pysical_size *= 2;
		//new
		//memcopy
	}
	//all_users[log_size] = user;
	user_log_size++;
	return true;
}

void System::addFanPage()
{
	FanPage* new_fan_page;

	new_fan_page = createFanPage();
	setFanPage(new_fan_page);
}

void System::showAllUsers() //const
{
	int index;
	for (index = 0; index < this->user_log_size; index++)
	{
		cout << index+1 << " - " << this->all_users[index]->getUserName();
	}
}

void System::setExit()
{
	this->_exit = true;
}

bool System::getExit()
{
	return this->_exit;
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
	this->all_users[selection - 1]->setUserStatus(status);
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
	this->all_pages[selection - 1]->setFanPageStatus(status);
}

//4
void System::showUserOrPageStatuses()
{
	int selection;
	cout << "1 - show statuses of a user" << endl;
	cout << "2 - show statuses of a Fan Page" << endl;
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
	return this->all_users[selection - 1];
}




