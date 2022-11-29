#include"Status.h"
#include <string.h>
#include <iostream>
#pragma warning (disable: 4996)

void Status::set_content(char* input) 
{
	strcpy(this->content, input);
	//date
}
void Status::show_status()
{
	//cout << this->content << endl;
}
