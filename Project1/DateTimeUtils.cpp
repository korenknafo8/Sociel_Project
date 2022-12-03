#include "DateTimeUtils.h"
#include <stdio.h>

Date::Date()
{
	day_ = month_ = 2;
	year_ = 1922;
}

Date::Date(const int& day, const int& month, const int& year)
{
	day_ = day;
	month_ = month;
	year_ = year_;
}

bool Date::setDay(const int& day)
{
	this->day_ = day;
	return true;
}

bool Date::setMonth(const int& month)
{
	this->month_ = month;
	return true;
}

bool Date::setYear(const int& year)
{
	this->year_ = year;
	return true;
}

int Date::getDay()
{
	return this->day_;
}

int Date::getMonth()
{
	return this->month_;
}

int Date::getYear()
{
	return this->year_;
}

/*void* myRealloc(void* source, int newSize)
{
	void* newArr;
	int i;
	for (i = 0; i < newSize; i++)
	{
		memcpy(newArr[i]) 
	}
}*/