#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include"DateTimeUtils.h"
#include "User.h"

class FanPage
{
public:
	FanPage(const char* name);
	FanPage(char* name);
	~FanPage();
	void setFanPageName(const char* name);
	char* getFanPageName() const;
	void setFanPageStatus(Status* status);
	void addFanToPage(User* new_fan);
	void removeFanFromPage(int index);
	void showFanPageFans() const;
	void showAllFanPageStatuses() const;
	int getFansLogSize() const;

private:
	char* name_;
	Status** status_list_fan_page_;
	int statuses_physical_size_ = 1;
	int statuses_logical_size_ = 0;
	User** fans_;
	int fans_physical_size_ = 3;
	int fans_log_size_ = 0;

};

#endif // !FAN_PAGE_H