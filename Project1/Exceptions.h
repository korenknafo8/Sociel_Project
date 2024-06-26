#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class SystemException : public std::exception
{
public:
	virtual const char* what() const noexcept(true) override { return "System Failure.\n"; }
};
	
class selectionOutOfRangeException : public SystemException
{
public:
	virtual const char* what() const noexcept(true) override { return "Selection was out of range.\n"; }
};

class FriendHimselfException : public SystemException
{
public:
	virtual const char* what() const noexcept(true) override { return "User cannot be a friend of himself.\n"; }
};

class lonelyException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "User has no friends to cancel\n"; }
};

class alreadyFriendsException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "Selected users are already friends.\n"; }

};class alreadyFanException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "Selected user is already a fan of this page.\n"; }
};

class nameExistException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "Name is already exist.\n"; }
};

class unvalidDateException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "Unvalid date.\n"; }
};

class dateOldException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "None is this old.\n"; }
};

class futureDateException : public SystemException
{
public:
	virtual const char* what () const noexcept(true) override { return "Create user when you will be born\n"; }
};
#endif // !EXCEPTIONS_H
