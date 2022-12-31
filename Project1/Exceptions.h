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

class futureDateException : public SystemException
{
public:
	virtual const char* what() const override { return "Create user when you will be born\n"; }
};
#endif // !EXCEPTIONS_H
