#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Footballer.h"
using namespace std;
class Admin
{
public:
	string adminName;
	string password;

	Admin();
	string getAdminName();
	void getPassword();
	void removeFootballer();
	void addFootballer();
	void addTeam();
	void chooseleague();
	void removeTeam();
	void adminMenu();
	void violation();
};

