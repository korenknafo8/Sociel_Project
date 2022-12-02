#include "Fan_Page.h"
#include "User.h"


bool FanPage::setFanPageName(char* name)
{
	this->name_ = new char[strlen(name)];
	strcpy(this->name_, name);
	return true;
}

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

void FanPage::showAllFanPageStatuses() const
{
	for (int index = 0; index < this->statuses_logical_size_; index++)
	{
		this->status_list_fan_page_[index]->show_status();
		cout << endl;
	}
}

char* FanPage::getFanPageName() const
{
	return this->name_;

}
/*
void FanPage::addFanToPage(User* new_fan)
{
	if (this->fans_logical_size_ == 0)
		this->fans_ = new User * [1];
	if (this->fans_logical_size_ == this->fans_physical_size_)
	{
		this->fans_physical_size_ *= 2;
		User** temp = new User * [this->fans_physical_size_];
		for (int i = 0; i < this->fans_logical_size_; i++)
			temp[i] = this->fans_[i];
		this->fans_ = temp;
		temp = nullptr;
		delete[] temp;
	}
	this->fans_[this->fans_logical_size_++] = new_fan;
	new_fan->addLikedFanPage(this);
}
*/
void FanPage::removeFanFromPage(User* fan)
{

}

void FanPage::showFanPageFans() const
{
	int index;
	if (this->fans_logical_size_ != 0)
	{
		cout << "All friends: " << endl;
		for (index = 0; index < this->fans_logical_size_; index++)
		{
			if (this->fans_[index] != NULL)
				cout << index + 1 << " - " << this->fans_[index]->getUserName() << endl;
		}
	}
	else
	{
		cout << "Fan page " << this->getFanPageName() << "has no fans to show." << endl;
	}
}
