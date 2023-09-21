#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "LeagueTeam.h"
using namespace std;
class League
{
public:
	string leagueName;

    vector<LeagueTeam> clubs;

	League();
	
	void displayleague();
};

