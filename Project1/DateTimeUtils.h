#ifndef DATE_TIME_UTILS_H
#define DATE_TIME_UTILS_H
#include <ctime>
#include <iostream>
#include "Exceptions.h"
using namespace std;

class Clock
{
public:
	Clock();
	Clock(const int& seconds, const int& minutes, const int& hours) { seconds_ = seconds; minutes_ = minutes; hours_ = hours; };
	
	void showTime() const;
	friend ostream& operator<<(std::ostream& os, const Clock& clock);
private:
	int seconds_, minutes_, hours_;
};

class Date
{
public:
	Date();
	Date(const int& day, const int& month, const int& year);
	void showDate() const;
	friend ostream& operator<<(std::ostream& os, const Date& date);
private:
	int day_,month_, year_;
};

#endif // !GENERAL_FUNCTIONS_H
