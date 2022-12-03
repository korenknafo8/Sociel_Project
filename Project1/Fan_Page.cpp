#include "Fan_Page.h"

/// <summary>
/// constractor of a FanPage class
/// </summary>
/// <param name="name">wanted name as 'const'</param>
FanPage::FanPage(const char* name)
{
	setFanPageName(name);
	fans_ = new User * [fans_physical_size_];
	status_list_fan_page_ = new Status * [statuses_physical_size_];
}

/// <summary>
/// constractor of a FanPage class
/// </summary>
/// <param name="name">wanted name</param>
FanPage::FanPage(char* name)
{
	setFanPageName(name);
	fans_ = new User * [fans_physical_size_];
	status_list_fan_page_ = new Status * [statuses_physical_size_];
}

/// <summary>
/// destructor
/// </summary>
FanPage::~FanPage()
{
	for (int i = 0; i < fans_log_size_; i++)
		delete[] fans_[i];
	for (int i = 0; i <statuses_logical_size_; i++)
		delete[] status_list_fan_page_[i];
	delete[] fans_;
	delete[] status_list_fan_page_;
	delete[] name_;

	
}

/// <summary>
/// Setting the wanted name of a fan page
/// </summary>
/// <param name="name">Wanted name</param>
void FanPage::setFanPageName(const char* name)
{
	this->name_ = new char[strlen(name)+1];
	strcpy(this->name_, name);
}

/// <summary>
/// Adding a wanted status to a fan page
/// </summary>
/// <param name="status">The status</param>
void FanPage::setFanPageStatus(Status* status)
{
	if (this->statuses_physical_size_ == this->statuses_logical_size_)
	{
		this->statuses_physical_size_ *= 2;
		Status** temp = new Status * [this->statuses_physical_size_];
		for (int i = 0; i < this->statuses_logical_size_; i++)
			temp[i] = this->status_list_fan_page_[i];
		this->status_list_fan_page_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->status_list_fan_page_[this->statuses_logical_size_] = status;
	this->statuses_logical_size_++;
}

/// <summary>
/// Prints all statuses of a fan page
/// </summary>
void FanPage::showAllFanPageStatuses() const
{
	cout << endl << "below are the statuses of " << getFanPageName() << ":" << endl;
	for (int index = 0; index < statuses_logical_size_; index++)
	{
		status_list_fan_page_[index]->showStatus();
		cout << endl;
	}
}

/// <summary>
/// Getting a fan page's name
/// </summary>
/// <returns>The name</returns>
char* FanPage::getFanPageName() const
{
	return name_;

}

/// <summary>
/// Adding a user to be a fan of a fan page
/// </summary>
void FanPage::addFanToPage(User* new_fan)
{
	if (this->fans_log_size_ == 0)
		this->fans_ = new User * [1];
	if (this->fans_log_size_ == this->fans_physical_size_)
	{
		this->fans_physical_size_ *= 2;
		User** temp = new User * [this->fans_physical_size_];
		for (int i = 0; i < this->fans_log_size_; i++)
			temp[i] = this->fans_[i];
		this->fans_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->fans_[this->fans_log_size_++] = new_fan;
	new_fan->addLikedFanPage(this);
}

/// <summary>
/// Removing a fan to be a fan of a fan page
/// </summary>
/// <param name="index">The index of the fan in 'fans_' array</param>
void FanPage::removeFanFromPage(int index)
{
	fans_[index] = fans_[--fans_log_size_];
}

/// <summary>
/// Prints all fan page's fans
/// </summary>
void FanPage::showFanPageFans() const
{
	int index;
		cout << "All fans: " << endl;
		for (index = 0; index < fans_log_size_; index++)
		{
			if (fans_[index] != NULL)
				cout << index + 1 << " - " << fans_[index]->getUserName() << endl;
		}
}

/// <summary>
/// Getting the amount of fan of a fan page
/// </summary>
/// <returns>The amount</returns>
int FanPage::getFansLogSize() const
{
	return fans_log_size_;
}

int FanPage::findFan(User* fan) const
{
	int index;
	for (index = 0; index < this->fans_log_size_; index++)
	{
		if (fan == this->fans_[index])
		{
			return index;
		}
	}
	return NOT_FOUND;
}