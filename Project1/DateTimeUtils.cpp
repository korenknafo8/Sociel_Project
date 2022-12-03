#include "DateTimeUtils.h"
#include <stdio.h>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS


Clock::Clock()
{
	//using ctime function to set time as current time of the machine
	time_t curr_time;
	curr_time = time(NULL);
	char* timeText = ctime(&curr_time);
	sscanf(timeText + 11, " %d:%d:%d", &hours, &minutes, &seconds);

}


void Clock::showTime() const
{
	printf("%02d:%02d:%02d", hours, minutes, seconds);
}
Date::Date()
{
	//sets the current time of the creation
	time_t curr_time;
	curr_time = time(NULL);
	tm* ltm = localtime(&curr_time);
	month_ = ltm->tm_mon + 1;	
	year_ = ltm->tm_year + 1900;
	day_ = ltm->tm_mday;
}

Date::Date(const int& day, const int& month, const int& year)
{
	day_ = day;
	month_ = month;
	year_ = year;
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