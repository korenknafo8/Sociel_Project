#include"Status.h"
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning (disable: 4996)

void Status::set_content(char* input) 
{
	strcpy(this->content_, input);
	//date
}
void Status::show_status()
{
	cout << this->content_ << endl;
	//show date
}
