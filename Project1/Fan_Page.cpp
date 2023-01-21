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
void FanPage::setStatus(Status* new_status)
{
	statuses_.push_back(new_status);
}

void FanPage::setStatus(Status_Picture* new_status)
{
	statuses_.push_back(new_status);
}

void FanPage::setStatus(Status_Video* new_status)
{
	statuses_.push_back(new_status);
}

/// <summary>
/// Prints all statuses of a fan page
/// </summary>
void FanPage::showStatuses() const
{
	if (statuses_.size() == 0)
		cout << "No statuses to show." << endl;
	else
	{
		cout << endl << "below are the statuses of " << getName() << ":" << endl;
		for (int i = 0; i < statuses_.size(); ++i)
		{
			statuses_[i]->show();
			cout << endl;
		}
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
	other.addLikedPage(this);
	return *this;
}

bool FanPage::operator>(FanPage& other)
{

	return fans_.size() > other.fans_.size();
	
}

bool FanPage::operator>(User& user)
{
	return fans_.size() > user.getFriendsSize();
}

ostream& operator<<(std::ostream& os, const FanPage& fanpage)
{
	os << fanpage.name_ << endl;
	int statuses_size = fanpage.statuses_.size();
	os << statuses_size << endl;
	for (int i = 0; i < statuses_size; i++)
	{
		os << *(fanpage.statuses_[i]) << endl;
	}
	return os;
}
