#include<vector>
#include "LeagueTeam.h"
#include "League.h"
#include "Global.h"

League::League()
{
}

void League::displayleague() {
	int choic;
	
		std::cout << "1- Premier League" << endl;
		std::cout << "2- La Liga" << endl;
		std::cin >> choic;
		current_league = choic - 1;
		switch (choic) {
		case 1:
			cout << "(Premier league)" << endl;
			for (int i = 0; i < league[current_league].clubs.size(); i++) {
				cout << league[current_league].clubs[i].leagueTeam_name <<"  " << league[current_league].clubs[i].leagueTeam_id +1<< endl;
			}

			break;
		case 2:
			cout << "(La Liga)" << endl;
			for (int i = 0; i < league[current_league].clubs.size(); i++) {
				cout << league[current_league].clubs[i].leagueTeam_name << "  " << league[current_league].clubs[i].leagueTeam_id+1 << endl;
			}
			break;
		}
	}
	
