#ifndef DATE_TIME_UTILS_H
#define DATE_TIME_UTILS_H

class Clock
{
public:
	int getMinutes();
	int getHours();
	bool setMinutes(int m);
	bool setHours(int h);
	void show();
private:
	int hours, minutes;
};
class Date
{
public:
	Date();
	Date(const int& day, const int& month, const int& year);
	bool setDay(const int& day);
	bool setMonth(const int& month);
	bool setYear(const int& year);
	int getDay();
	int getMonth();
	int getYear();


private:
	int day_;
	int month_;
	int year_;
};

//void* myRealloc(void* source, int newSize);


#endif // !GENERAL_FUNCTIONS_H
