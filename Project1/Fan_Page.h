#ifndef FAN_PAGE_H
#define FAN_PAGE_H
#include <fstream>
#include"DateTimeUtils.h"
#include "User.h"

class FanPage
{
private:
	vector<User*>fans_;
	list<Status>statuses_;
	vector<Status*>all_statuses_;
	string name_;
	const int NOT_FOUND = -1;
	
public:
	FanPage(string name);
	~FanPage();
	void setFanPageName(const string name);
	User* getFan(int index) const;
	string getName() const;
	void setFanPageStatus(Status* status);
	void setFanPageStatus(Status_Picture* status);
	void setFanPageStatus(Status_Video* status);
	void addFanToPage(User& new_fan) noexcept(false);
	void removeFanFromPage(int index);
	void showFanPageFans() const;
	void showStatuses() const;
	int getFansSize() const;
	int findFan(User* fan) const;
	int findFan(const User* fan) const;
	FanPage& operator+=(User& other);
	bool operator>(FanPage& other);
	bool operator>(User& user);
	friend ostream& operator<<(std::ostream& os, const FanPage& fanpage);
	
};

#endif // !FAN_PAGE_H