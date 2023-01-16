#include "Fan_Page.h"

/// <summary>


/// <summary>
/// constractor of a FanPage class
/// </summary>
/// <param name="name">wanted name</param>
FanPage::FanPage(string name)
{
	setFanPageName(name);
}

/// <summary>
/// destructor
/// </summary>
FanPage::~FanPage()
{
}

/// <summary>
/// Setting the wanted name of a fan page
/// </summary>
/// <param name="name">Wanted name</param>
void FanPage::setFanPageName(const string name)
{
	name_ = name;
}

/// <summary>
/// Adding a wanted status to a fan page
/// </summary>
/// <param name="status">The status</param>
void FanPage::setFanPageStatus(Status& new_status)
{
	statuses_.push_back(new_status);
}

void FanPage::setFanPageStatus(Status_Picture& new_status)
{
	statuses_.push_back(new_status);
}

void FanPage::setFanPageStatus(Status_Video& new_status)
{
	statuses_.push_back(new_status);
}

/// <summary>
/// Prints all statuses of a fan page
/// </summary>
void FanPage::showStatuses() const
{
	cout << endl << "below are the statuses of " << getName() << ":" << endl;
	list<Status>::const_iterator itr = statuses_.end();
	for (int i = 0; i < statuses_.size(); ++i) {
		(--itr)->show();
		cout << endl;
	}
}

/// <summary>
/// Getting a fan page's name
/// </summary>
/// <returns>The name</returns>
string FanPage::getName() const
{
	return name_;
}

/// <summary>
/// Adding a user to be a fan of a fan page
/// </summary>
void FanPage::addFanToPage(User& new_fan) noexcept(false)
{
	int index = findFan(&new_fan);
	if (index != NOT_FOUND)
		throw alreadyFanException();
	fans_.push_back(&new_fan);
}

/// <summary>
/// Removing a fan to be a fan of a fan page
/// </summary>
/// <param name="index">The index of the fan in 'fans_' array</param>
void FanPage::removeFanFromPage(int index)
{
	if(fans_.size()>1)
		fans_[index] = fans_[fans_.size() - 1];
	fans_.pop_back();
}

/// <summary>
/// Prints all fan page's fans
/// </summary>
void FanPage::showFanPageFans() const
{
	int index;
		cout << "All fans: " << endl;
		for (index = 0; index < fans_.size(); index++)
		{
			if (fans_[index] != NULL)
				cout << index + 1 << " - " << fans_[index]->getName() << endl;
		}
}

/// <summary>
/// Getting the amount of fan of a fan page
/// </summary>
/// <returns>The amount</returns>
int FanPage::getFansSize() const
{
	return fans_.size();
}

int FanPage::findFan(User* fan) const
{
	int index;
	for (index = 0; index < fans_.size(); index++)
		if (fan == fans_[index])
			return index;
	return NOT_FOUND;
}

int FanPage::findFan(const User* fan) const
{
	int index;
	for (index = 0; index < fans_.size(); index++)
		if (fan == fans_[index])
			return index;
	return NOT_FOUND;
}

User* FanPage::getFan(int index) const
{
	return fans_[index];
}

FanPage& FanPage::operator+=(User& other)
{
	addFanToPage(other);
	other.addLikedFanPage(this);
	return *this;
}
