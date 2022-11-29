#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include"General_Functions.h"

class Status;
class User;

class FanPage
{
public:

	bool setFanPageName(char* name);
	void setFanPageStatus(Status* status);
	void showAllStatusesfanPage() const;
	bool addFanToPage(User* new_fan);
	bool removeFanFromPage(User* fan);
	void showFanPageFans() const;

private:
	int pysical_size_ = 1;
	int logical_size_ = 0;
	char* name_;
	User* fans;
	Status** status_list_fp_;

};

#endif // !FAN_PAGE_H

