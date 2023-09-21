#pragma once
#include <iostream>
#include <string>
using namespace std;
class Footballer
{
public:
	string Name;
	string Position;
	string leagueTeam_name;
	int leagueTeam_id;
	float price;
	int point =0;
	int totalPoint = 0;


	//Constructors
	Footballer();
	int resetPoints();
	int setPoints();

};


