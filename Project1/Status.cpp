#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

/// <summary>
/// Enters content into status
/// </summary>
/// <param name="input">header-line input</param>
void Status::setContent(const char* input) 
{
	this->content_ = new char[strlen(input) + 1];
	strcpy(this->content_, input);
}

//prints status
void Status::showStatus()
{
	cout << this->content_ << "    ";
	date_of_Status_.showDate();
	cout << " ";
	time_of_Status_.showTime();
}

//ctr
Status::Status(const char* text)
{
	setContent(text);
}

//destructor
Status::~Status()
{
	delete[] content_;
}