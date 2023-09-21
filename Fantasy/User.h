#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Footballer.h"

using namespace std;


class User
{
public:
	string userName;
	string password;
	int id;
	int totalPoint = 0;
	int choose;
	float budget = 100000;
	string customName;
	vector<string> members;


	User();
	string getUserName();
	void getPassword();
	void createTeam();
	void buy_footballer();
	Footballer* getFootballer(string name);
	void sell_footballer(string footballerName);
	void replace_footballer();
	void displayMyteam();
	void userMenu();
	void luckyWheel();
	void sortFootballer();
};

