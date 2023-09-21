#pragma once
#include <iostream>
#include <string>
#include "Footballer.h"
#include <vector>
#include <unordered_map>
using namespace std;
class LeagueTeam
{
public:
	string leagueTeam_name;
	int leagueTeam_id;
	vector<Footballer*> leageTeam_Members;

	LeagueTeam();
	string getName();
	void display();
};

