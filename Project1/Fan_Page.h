#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include"General_Functions.h"
#include "Status.h"


class Status;
class User;

class FanPage
{
public:

	bool setFanPageName(char* name);
	char* getFanPageName() const;
	void setFanPageStatus(Status* status);
	void addFanToPage(User* new_fan);
	bool removeFanFromPage(User* fan);
	void showFanPageFans() const;
	void showAllFanPageStatuses() const;
	void showsFansOfFanPage();



private:
	char* name_;
	Status** status_list_fan_page_;
	int statuses_physical_size_ = 1;
	int statuses_logical_size_ = 0;
	User** fans_;
	int fans_physical_size_ = 1;
	int fans_logical_size_ = 0;

};

#endif // !FAN_PAGE_H

