#include "User.h"
using namespace std;
#pragma warning (disable: 4996)
#include "Fan_Page.h"

/// <summary>
/// The constractor of a user class
/// </summary>
User::User(string name, int day, int month, int year) 
{
	setName(name);
	date_of_birth_ = Date(day, month, year);
}

/// <summary>
/// destructor
/// </summary>
User::~User()
{
	
}

/// <summary>
/// Setting a wanted name to a user
/// </summary>
/// <param name="name">The wanted name</param>
void User::setName(const string new_name)
{
	name_ = new_name;
}

/// <summary>
/// Getting a user name
/// </summary>
/// <returns>The name</returns>
string User::getName() const
{
	return this->name_;

}

/// <summary>
/// Set a status for a given user
/// </summary>
/// <param name="status">status</param>
void User::setUserStatus(Status& new_status)
{
	statuses_.push_back(new_status);
}

/// <summary>
/// Prints all the statuses of a user
/// </summary>
void User::showStatuses() const
{
	cout << endl << "below are the statuses of " << getName() << ":" << endl;
	list<Status>::const_iterator itr = statuses_.end();
	for (int i = 0; i < statuses_.size(); ++i, --itr) {
		itr->show();
		cout << endl;
	}
}

/// <summary>
/// Present all/10 statuses of the friends of a single user
/// </summary>
void User::showFriendsStatuses() const
{
	for (int i = 0; i < friends_.size(); i++)
	{
		cout << "Statuses of: " << friends_[i]->getName() << endl;
		friends_[i]->showStatuses();
		for (int j = 0; j < friends_[i]->statuses_.size() && j < 10; j++)
		{
			cout << j+1 << " - ";
			friends_[i]->statuses_;
			cout << endl;
		}
	}
}

/// <summary>
/// Adding the user to be in the friends list of another user
/// </summary>
/// <param name="new_friend">The wanted user</param>
void User::makeFriendship(User& new_friend)
{
	int index = findFriend(new_friend);

	
	if (index != NOT_FOUND)
	{
		cout << "This friend is already exist" << endl;
		return;
	}
	friends_.push_back(&new_friend);
}

/// <summary>
/// Prints all the friends of a user
/// </summary>
void User::showFriends() const
{
	int index;
	if (friends_.size() != 0) 
	{
		cout << "All friends: " << endl;
		for (index = 0; index < friends_.size(); index++)
			if (friends_[index] != NULL)
				cout << index + 1 << " - " << friends_[index]->getName() << endl;
	}
	else 
		cout << "The user " << this->getName() << " has no friends to show." << endl;
}


/// <summary>
/// Cancel friendship between a user and a given user
/// </summary>
/// <param name="index">Index at the friend's list of the other friend</param>
void User::friendshipCancelation(int index)
{
	int this_index = friends_[index]->findFriend(*this); //in this case allways find the user
	friends_[index]->friends_[this_index] = friends_[index]->friends_[friends_.size()-1];
	friends_[index] = friends_[friends_.size()-1];
	friends_.pop_back();
	friends_[index]->friends_.pop_back();
}

/// <summary>
/// Locate a friend of user in his friend's pointer array and returns it's index
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
int User::findFriend(User& user) const 
{
	int index;
	for (index = 0; index < friends_.size(); index++)
	{
		if (&user == friends_[index])
			return index;
	}
	return NOT_FOUND;
}

/// <summary>
/// Remove a fan page from liked pages of a user
/// </summary>
/// <param name="name">The page we want to remove</param>
void User::removeLikedPage(FanPage& liked_page)
{
	int foundIndex = findLikedPage(liked_page);
	liked_pages_[foundIndex] = liked_pages_[liked_pages_.size() - 1];
	liked_pages_.pop_back();
}

/// <summary>
/// Getting the index of a fan page in a user's fan pages list
/// </summary>
/// <param name="name">The wanted fan page</param>
/// <returns>The index</returns>
int User::findLikedPage(FanPage& liked_page) const
{
	int index;
	for (index = 0; index < liked_pages_.size(); index++)
	{
		if (&liked_page == liked_pages_[index])
			return index;
	}
	return NOT_FOUND;
}

/// <summary>
/// Adding a fan page to be in the liked fan pages of a user
/// </summary>
/// <param name="new_page">name of page to add</param>
void User::addLikedFanPage(FanPage* new_page)
{
	liked_pages_.push_back(new_page);
}

/// <summary>
/// Getting the amount of friends of a user
/// </summary>
/// <returns>The amount of friends</returns>
int User::getFriendsSize()
{
	return friends_.size();
}

/// <summary>
/// Prints the names of the page a single user likes
/// </summary>
void User::showAllLikesPages() const
{
	cout << "User's liked pages are:" << endl;
	for (int i = 0; i < liked_pages_.size(); i++)
		cout << liked_pages_[i]->getName() << endl << endl;
}

User& User::operator+=(User& other)
{
	makeFriendship(other);
	other.makeFriendship(*this);
	return *this;
}

bool User::operator==(User other)
{
	return name_ == other.name_;
}

bool User::operator>(User other)
{
	return friends_.size() > other.friends_.size();
}
