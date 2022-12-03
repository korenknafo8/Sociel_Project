#include "Fan_Page.h"

FanPage::FanPage(const char* name)
{
	setFanPageName(name);
	fans_ = new User * [fans_physical_size_];
	status_list_fan_page_ = new Status * [statuses_physical_size_];
}
FanPage::FanPage(char* name)
{
	setFanPageName(name);
	fans_ = new User * [fans_physical_size_];
	status_list_fan_page_ = new Status * [statuses_physical_size_];
}

void FanPage::setFanPageName(const char* name)
{
	this->name_ = new char[strlen(name)+1];
	strcpy(this->name_, name);
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
	cout << endl << "below are the statuses of " << getFanPageName() << ":" << endl;
	for (int index = 0; index < statuses_logical_size_; index++)
	{
		status_list_fan_page_[index]->showStatus();
		cout << endl;
	}
}

char* FanPage::getFanPageName() const
{
	return name_;

}

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


void FanPage::removeFanFromPage(int index)
{
	fans_[index] = fans_[--fans_log_size_];
}

void FanPage::showFanPageFans() const
{
	int index;
		cout << "All friends: " << endl;
		for (index = 0; index < fans_log_size_; index++)
		{
			if (fans_[index] != NULL)
				cout << index + 1 << " - " << fans_[index]->getUserName() << endl;
		}
}

int FanPage::showFansLogSize() const
{
	return fans_log_size_;
}