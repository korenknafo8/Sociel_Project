#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

void Status::setContent(char* input) 
{
	this->content_ = new char[101];
	strcpy(this->content_, input);
	//date
}
void Status::showStatus()
{
	cout << this->content_ << endl;
	//show date
}
