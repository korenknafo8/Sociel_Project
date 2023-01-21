#include"System.h"


void main()
{
	int selection;
	System Facebook;
	string file_name = "RecoverBackUp.txt";
	Facebook.initializeSystem(file_name);
	while (!Facebook.getExit())
	{
		Facebook.showMenu(); // still does not set users and statuses into 'all_users' and 'all statuses'
		cin >> selection;
		Facebook.menuSelection(selection);
	}
	Facebook.dataToFile(file_name);
}