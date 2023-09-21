#include "Admin.h"
#include "Global.h"
#include "LeagueTeam.h"
#include "Footballer.h"
#include "League.h"
#include "Competition.h"
#include "User.h"

Admin::Admin()
{
}

string Admin::getAdminName()
{
	cin>> adminName;
	return adminName;
}

void Admin::getPassword()
{
	cin>> password;
}

void Admin::addFootballer()
{
	string teamName;
	League lg;
	Footballer fb;
	char answer;
	lg.displayleague();
	cout << "which team you want to add a footballer to: ";
	std::cin>> teamName;
	for (int i = 0; i < league[current_league].clubs.size(); i++) {
		if (teamName == league[current_league].clubs[i].leagueTeam_name) {
			cout << "Team Found <3" << endl << endl;
			
				cout << "Footballer Name: " << endl; std::cin >> fb.Name;
				for (auto it = footballer.begin(); it != footballer.end(); ++it) {
					if (it->second.Name == fb.Name) {
						cout << "This player is already existed" << endl;
						cout << "Do you want to try again?(y/n)" << endl;
						cin >> answer;
						if (answer == 'y' || answer == 'Y')
							continue;
						else if (answer == 'n' || answer == 'N')
							return;
					}
				}

					cout << "Position: " << endl; cin >> fb.Position;
					cout << "Price: " << endl; cin >> fb.price;
					fb.leagueTeam_name = league[current_league].clubs[i].leagueTeam_name;
					fb.leagueTeam_id = league[current_league].clubs[i].leagueTeam_id;
					footballer[fb.Name] = fb;
					league[current_league].clubs[i].leageTeam_Members.push_back(&footballer[fb.Name]);
					cout << "Footballer " << fb.Name << " is added succefully to " << league[current_league].clubs[i].leagueTeam_name << endl;
				
			return;

		}
	}
	cout << "This team doesn't exist!" << endl;
}

void Admin::addTeam()
{
	
	int choic;
	bool exit = false;
	while (!exit) {
		std::cout << "1- Premier League" << endl;
		std::cout << "2- La Liga" << endl;
		std::cout << "3- Exit" << endl;
		std::cin >> choic;
		current_league = choic - 1;
		switch (choic) {
		case 1:
			chooseleague();
			break;
		case 2:
			chooseleague();
			break;
		case 3:
			exit = true;
			break;
		}
	}
	
}

void Admin::chooseleague()  {
	LeagueTeam lTeam;
	League lg;
	char answer;

	std::cout << "Enter team name: " << endl;
	lTeam.leagueTeam_name = lTeam.getName();
	for (int i = 0; i < league[current_league].clubs.size(); i++) {
		if (league[current_league].clubs[i].leagueTeam_name == lTeam.leagueTeam_name) {
			cout << "This team is already existed" << endl;
			cout << "Do you want to try again?(y/n)" << endl;
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
				continue;
			else if (answer == 'n' || answer == 'N')
				return;
		}
	}
	lTeam.leagueTeam_id = auto_id_team;
	auto_id_team++;
	league[current_league].clubs.push_back(lTeam);
	
	
}

void Admin::removeTeam()
{
	std::string lteam;
	int choic;
	std::cout << "1- Premier League" << endl;
	std::cout << "2- La Liga" << endl;
	std::cin >> choic;
	current_league = choic - 1;

	// Iterate over the teams in the selected league and display their names
	for (auto lg : league[current_league].clubs) {
		cout << lg.leagueTeam_name << endl;
	}

	std::cout << "Enter team name to be removed: ";
	std::cin >> lteam;

	// Find the team with the specified name and remove it from the league
	auto it = std::find_if(league[current_league].clubs.begin(), league[current_league].clubs.end(), [&](const auto& t) {
		return t.leagueTeam_name == lteam;
		});

	if (it != league[current_league].clubs.end()) { // Check if the team was found
		league[current_league].clubs.erase(it); // Remove the team from the league
		cout << lteam << " is removed successfully" << endl;
	}
	else {
		std::cout << "Team not found" << endl;
	}
}

void Admin::adminMenu()
{
	int choic;
	Footballer fb;
	LeagueTeam lTeam;
	Competition com;
	bool exit = false;
	while (!exit) {
		std::cout << "1- Add Footballer" << endl;
		std::cout << "2- Remove Footballer" << endl;
		std::cout << "3- Set points" << endl;
		std::cout << "4- Reset points" << endl;
		std::cout << "5- Add team" << endl;
		std::cout << "6- Remove team" << endl;
		std::cout << "7- Display teams" << endl;
		std::cout << "8- Exit" << endl;
		std::cin >> choic;
		switch (choic) {
		case 1:
			addFootballer();
			break;
		case 2:

			removeFootballer();
			break;
		case 3:
			    srand(time(NULL));
				for (auto it = footballer.begin(); it != footballer.end(); ++it) {
					it->second.point = fb.setPoints();
					it->second.totalPoint += it->second.point;
				}
				violation();
				com.calcPoint();

			break;
		case 4:
			for (auto footb = footballer.begin(); footb != footballer.end();++footb) {
				
					footb->second.totalPoint = fb.resetPoints();
				
			}
			
			break;
		case 5:
			addTeam();
			break;
		case 6:
			removeTeam();
			break;
		case 7:
			lTeam.display();
			break;
		case 8:
			exit = true;
			break;
		}

	}
}

void Admin::removeFootballer()
{
	string team_name, player_name;
	League lg;
	lg.displayleague();
	cout << "Enter team and player name: ";
	cin>>team_name ;
	cin>> player_name;
	for (int i = 0; i < league[current_league].clubs.size(); i++) {
		if (league[current_league].clubs[i].leagueTeam_name == team_name) {
			for (int j = 0; j < league[current_league].clubs[i].leageTeam_Members.size(); j++) {
				if (league[current_league].clubs[i].leageTeam_Members[j]->Name == player_name) {
					league[current_league].clubs[i].leageTeam_Members.erase(league[current_league].clubs[i].leageTeam_Members.begin() + j);
					footballer.erase(player_name);
				}
			}

		}
	}

}

void Admin::violation() {
	for (auto & fb : footballer)
	{
		
		if (fb.second.point == 1) {
			//player has taken a yellow card (-1 point)
			cout << fb.first << " has taken a yellow card, his points = " <<fb.second.point<< endl;
			fb.second.point = fb.second.point - 1;
			cout << "after minus his points became = " << fb.second.point << endl;


		}
		else if (fb.second.point == 0)
		{
			//player has taken a red card (-3 point)
			cout << fb.first << " has taken a red card, his points = " << fb.second.point << endl;
			fb.second.point = fb.second.point - 3;
			cout << "after minus his points became = " << fb.second.point << endl;

		}
		else if (fb.second.point == 2)
		{
			//player has missed a penalty (-3 point)
			cout << fb.first << " has missed a penalty, his points = " << fb.second.point << endl;
			fb.second.point = fb.second.point - 3;
			cout << "after minus his points became = " << fb.second.point << endl;

		}
	}

}

