#include"System.h"


void main()
{
	int selection;
	System Facebook;
	Facebook.initiateCreation(); //initiate first users, fan pages and statuses
	string file_name = "RecoverBackUp.txt";
	Facebook.saveToFile(file_name);
	while (!Facebook.getExit())
	{
		Facebook.showMenu(); // still does not set users and statuses into 'all_users' and 'all statuses'
		cin >> selection;
		Facebook.menuSelection(selection);
	}
}