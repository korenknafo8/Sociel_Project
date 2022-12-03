#ifndef DATE_TIME_UTILS_H
#define DATE_TIME_UTILS_H

class Clock
{
public:
	Clock();
	/*
	* Function that show the time in HH:mm:ss Format
	*/
	void showTime() const;

	//Ctor
	Clock();
private:
	int seconds;
	int minutes;
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
	int day_,month_, year_;
};

//void* myRealloc(void* source, int newSize);


#endif // !GENERAL_FUNCTIONS_H
