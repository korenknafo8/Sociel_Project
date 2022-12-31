#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class SystemException : public std::exception
{
public:
	virtual const char* what() const override { return "System Failure.\n"; }
};
	
class selectionOutOfRangeException : public SystemException
{
public:
	virtual const char* what() const override { return "Selection was out of range.\n"; }
};

class FriendHimselfException : public SystemException
{
public:
	virtual const char* what() const override { return "User cannot be a friend of himself.\n"; }
};

class lonelyException : public SystemException
{
public:
	virtual const char* what() const override { return "User has no friends to cancel\n"; }
};

class alreadyFriendsException : public SystemException
{
public:
	virtual const char* what() const override { return "Selected users are already friends.\n"; }
};

class nameExistException : public SystemException
{
public:
	virtual const char* what() const override { return "Name is already exist.\n"; }
};

class unvalidDateException : public SystemException
{
public:
	virtual const char* what() const override { return "Unvalid date.\n"; }
};

class dateOldException : public SystemException
{
public:
	virtual const char* what() const override { return "None is this old.\n"; }
};

class futureDateException : public SystemException
{
public:
	virtual const char* what() const override { return "Create user when you will be born\n"; }
};
#endif // !EXCEPTIONS_H
