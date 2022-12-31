#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class SystemException : public std::exception
{
public:
	virtual const char* what() const override { return "System Failure.\n"; }
};
	
class IndexOutOfRange : public SystemException
{
public:
	virtual const char* what() const override { return "Input was not a number in range.\n"; }
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

class userFindException : public SystemException
{
public:
	virtual const char* what() const override { return "User was not found.\n"; }
};

class fanPageFindException : public SystemException
{
public:
	virtual const char* what() const override { return "fan Page was not found.\n"; }
};


class futureDateException : public SystemException
{
public:
	virtual const char* what() const override { return "Create user when you will be born\n"; }
};
#endif // !EXCEPTIONS_H
