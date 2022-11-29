#include "Fan_Page.h"
#include <string.h>
#pragma warning (disable: 4996)

bool FanPage::setFanPageName(char* name)
{
	this->name_ = new char[strlen(name)];
	strcpy(this->name_, name);
	return true;
}

void FanPage::setFanPageStatus(Status* status)
{
	if (this->pysical_size_ = this->logical_size_)
	{
		this->pysical_size_ *= 2;
		//new
		// coppy
		//delete
	}

	this->status_list_fp_[this->logical_size_] = status;

}