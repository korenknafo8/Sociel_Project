#define _CRT_SECURE_NO_WARNINGS
#include "DateTimeUtils.h"

/// <summary>
/// ctor
/// </summary>
Clock::Clock()
{
	//using ctime function to set time as current time of the machine
	time_t curr_time;
	curr_time = time(NULL);
	char* timeText = ctime(&curr_time);
	sscanf(timeText + 11, " %d:%d:%d", &hours_, &minutes_, &seconds_);
}

/// <summary>
/// Prints the time with '0' betwing hours/minuts/second if needed
/// </summary>
void Clock::showTime() const
{
	if (hours_ < 10)
		cout << "0";
	cout << hours_ << ":";
	if(minutes_ < 10)
		cout << "0";
	cout << minutes_ << ":";
	if (seconds_ < 10)
		cout << "0";
	cout << seconds_;
}

/// <summary>
/// ctor
/// </summary>
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

/// <summary>
/// constractor of the Date class
/// </summary>
Date::Date(const int& day, const int& month, const int& year)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm* ltm = localtime(&curr_time);
	int curr_day = ltm->tm_mday;
	int curr_month = ltm->tm_mon + 1;
	int curr_year = ltm->tm_year + 1900;

	day_ = day;
	month_ = month;
	year_ = year;
	if (day > 30 || day < 1 || month > 12 || month < 1)
		throw unvalidDateException();	
	if (year < 1902)
		throw dateOldException();
	if (year > curr_year)
		throw futureDateException();
	else if (year ==  curr_year && month > curr_month)
		throw futureDateException();
	else if (year == curr_year && month == curr_month && day > curr_day)
		throw futureDateException();
}

/// <summary>
/// prints the given date
/// </summary>
void Date::showDate() const
{
	if (month_ < 10)
		cout << "0";
	cout << month_ << "/";
	if (day_ < 10)
		cout << "0";
	cout << day_ << "/";
	cout << year_;
}

ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.day_ << " " << date.month_ << " " << date.year_;
	return os;
}

ostream& operator<<(std::ostream& os, const Clock& clock)
{
	os << clock.seconds_ << " " << clock.minutes_ << " " << clock.hours_;
	return os;
}