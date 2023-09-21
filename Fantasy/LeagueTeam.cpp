#include "Global.h"
#include "LeagueTeam.h"
#include "Footballer.h"
#include "League.h"
#include <string>

LeagueTeam::LeagueTeam()
{
}


string LeagueTeam::getName()
{
	string value;
	std::cin >> value;
	return value;
}


void LeagueTeam::display()
{
	int choic;

	std::cout << "1- Premier League" << endl;
	std::cout << "2- La Liga" << endl;
	std::cin >> choic;
	current_league = choic - 1;
	for (int i = 0; i < league[current_league].clubs.size(); i++) {
		cout << "Team name: " << league[current_league].clubs[i].leagueTeam_name << "  " << "Team ID: " <<
			league[current_league].clubs[i].leagueTeam_id << endl << endl;
		cout << "Name\t\tPosition\tPrice\tPoints:"<< endl;
		for (int j = 0; j < league[current_league].clubs[i].leageTeam_Members.size(); j++) {
			
			cout<< league[current_league].clubs[i].leageTeam_Members[j]->Name <<"\t"
			 << league[current_league].clubs[i].leageTeam_Members[j]->Position << "\t\t"
			 << league[current_league].clubs[i].leageTeam_Members[j]->price << "\t\t"
			 << league[current_league].clubs[i].leageTeam_Members[j]->totalPoint << endl;
		}
	 }
}




