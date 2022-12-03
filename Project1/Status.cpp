#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

void Status::setContent(const char* input) 
{
	this->content_ = new char[strlen(input) + 1];
	strcpy(this->content_, input);
	//date
}
void Status::showStatus()
{
	cout << this->content_ << endl;
	//show date
}

Status::Status(const char* text)
{
	setContent(text);
	date_of_Status_ = Date();

}
