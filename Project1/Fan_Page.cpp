#include "Fan_Page.h"



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
