#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include"DateTimeUtils.h"
#include "User.h"

class FanPage
{
private:
	string name_;
	list<Status>statuses_;
	vector<User*>fans_;
	const int NOT_FOUND = -1;

public:
	FanPage(const string name);
	FanPage(string name);
	~FanPage();
	void setFanPageName(const string name);
	string getName() const;
	void setFanPageStatus(Status& status);
	void addFanToPage(User* new_fan);
	void removeFanFromPage(int index);
	void showFanPageFans() const;
	void showStatuses() const;
	int getFansLogSize() const;
	int findFan(User* fan) const;
};

#endif // !FAN_PAGE_H