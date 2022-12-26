#include"System.h"


void main()
{
	int selection;
	System Facebook;
	Facebook.initiateCreation(); //initiate first users, fan pages and statuses
	while (!Facebook.getExit())
	{
	Facebook.showMenu(); // still does not set users and statuses into 'all_users' and 'all statuses'
	cin >> selection;
	Facebook.menuSelection(selection);
	}
}