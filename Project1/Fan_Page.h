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
	FanPage(string name);
	~FanPage();
	void setFanPageName(const string name);
	User* getFan(int index) const;
	string getName() const;
	void setFanPageStatus(Status& status);
	void addFanToPage(User& new_fan) noexcept(false);
	void removeFanFromPage(int index);
	void showFanPageFans() const;
	void showStatuses() const;
	int getFansSize() const;
	int findFan(User* fan) const;
	int findFan(const User* fan) const;
	FanPage& operator+=(User& other);
};

#endif // !FAN_PAGE_H