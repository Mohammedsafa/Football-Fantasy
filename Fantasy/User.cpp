#pragma once
#include <iostream>
#include <string>
#include "Global.h"
#include <vector>
#include"Footballer.h"
#include "User.h"
#include "LeagueTeam.h"
#include "League.h"
#include "Competition.h"


using namespace std;

User::User()
{
}

string User::getUserName()
{
	cin>>userName;
    return userName;
}

void User::getPassword()
{
	cin>>password;
}

void User::createTeam() {
	int choic;

	std::cout << "1- Premier League" << endl;
	std::cout << "2- La Liga" << endl;
	std::cin >> choic;
	current_league = choic - 1;
	user[current_user].choose = choic - 1;
	cout << "Enter the name of the team: ";
	std::cin>>user[current_user].customName;
	
	cout << "You need to at least have 5 footballers to be able to join the competition." << endl;
	buy_footballer();
}

Footballer* User::getFootballer(string name) {
	if (footballer.find(name) == footballer.end()) {
		cout << "This player doesn't exist." << endl;
		return NULL;
	}

	Footballer value = footballer.find(name)->second;
	cout << "Name: " << value.Name << "\t\t Team: " << value.leagueTeam_name << endl;
	cout << "Position: " << value.Position << "\t\t TeamId: " << value.leagueTeam_id << endl;
	cout << "Price: " << value.price << endl;
	cout << "Total Points: " << value.totalPoint << endl;
	return &footballer.find(name)->second;
}

void User::buy_footballer() {
	string name;
	char answer;
	while (true) {
		    
			sortFootballer();
			cout << "Name" << "\t\t" << "Position" <<"\t"<<"Point" << endl;
			for (auto lg : league[user[current_user].choose].clubs) {

				cout << "Team name: " << lg.leagueTeam_name << endl;
					for (auto fb : lg.leageTeam_Members) {
						cout << fb->Name << "\t" << fb->Position<<"\t"<<fb->totalPoint << endl;
					}
			}
		
		
		cout << "Your budget is: $" << user[current_user].budget << endl;
		cout << "Enter player name: ";
		cin>> name;

		Footballer* fb = getFootballer(name);
		if (fb == NULL) {

			cout << "Try again!" << endl;

			continue;
		}

		cout << "Add him to your team (Y/N)" << endl;

		cin >> answer;


		if (answer == 'y' || answer == 'Y') {
			for (int i = 0; i < user[current_user].members.size(); i++) {
				if (user[current_user].members[i] == name) {
					cout << "The player you want to buy is already existed" << endl;
					cout << "Do you want to try again?" << endl;
					cin >> answer;
					if (answer == 'y' || answer == 'Y')
						continue;
					else if (answer == 'n' || answer == 'N')
						return;
				}
			}

				//Checking budget before buying
				if (user[current_user].budget < fb->price) { //if condition true means budget not enough.
					cout << "You don't have enough credit to buy this player." << endl;
					cout << "Do you want to try again?" << endl;
					cin >> answer;
					if (answer == 'y' || answer == 'Y')
						continue;
					else if (answer == 'n' || answer == 'N')
						break;
				}

				user[current_user].members.push_back(fb->Name);
				user[current_user].budget -= fb->price;
			
			break;
		}

		cout << "Do you want to do another operation?"<<endl;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			continue;
		else if (answer == 'n' || answer == 'N')
			break;
	}
}

void User::replace_footballer()
{
	
	string footballerName;
	cout << "Enter the player to sell" << endl;
	cin >> footballerName;
	sell_footballer(footballerName);

	buy_footballer();


}

void User::sell_footballer(string footballerName) {
	
	
	// Find the team with the specified name and remove it from the league
	auto it = std::find_if(user[current_user].members.begin(), user[current_user].members.end(), [&](const auto& t) {
		return t == footballerName;
		});

	if (it != user[current_user].members.end()) { // Check if the team was found
		user[current_user].budget += footballer.find(footballerName)->second.price;
		user[current_user].members.erase(it); // Remove the team from the league
		cout << footballerName << " is removed successfully" << endl;
	}
	else {
		std::cout << "Player not found" << endl;
	}
}

void User::displayMyteam()
{

	cout <<"Team name: " <<user[current_user].customName <<"\t"
     "Ponint: "  <<user[current_user].totalPoint << endl;
	cout << "Name\tPositin\n";
	for (int i = 0; i < user[current_user].members.size(); i++) {
		cout << user[current_user].members[i] <<"\t"
			<<footballer.find(user[current_user].members[i])->second.Position << endl;
	}

}

void User::userMenu()
{
	int choic;
	string ans;
	Competition competition;
	std::string name;
	bool exit = false;
	while (!exit) {
		std::cout << "1- Buy another player" << endl;
		std::cout << "2- Sell player" << endl;
		std::cout << "3- Replace player" << endl;
		std::cout << "4- Display My team" << endl;
		std::cout << "5- Display top 3" << endl;
		std::cout << "6- Display the winner " << endl;
		std::cout << "7- Lucky Wheel" << endl;
		std::cout << "8- exit" << endl;
		std::cin >> choic;
		switch (choic) {
		case 1:
			buy_footballer();
			break;

		case 2:
			std::cout << "Enter the player to sell" << endl;
			std::cin >> name;
			sell_footballer(name);
			break;
		case 3:
			replace_footballer();
			break;
		case 4:
			displayMyteam();
			break;
		case 5:
			if (user[current_user].members.size() < 5) {
				cout << "your team doesn't complete" << endl;
				char ans;
				cout << "you want to buy?(y/n)" << endl;
				cin >> ans;
				if (ans == 'y' || ans == 'Y') {
					buy_footballer();
				}
				else if(ans == 'n' || ans == 'N') {
					userMenu();
				}
			}
			else {
				competition.top3();
			}
			break;
		case 6:
			if (user[current_user].members.size() < 5) {
				cout << "your team doesn't complete" << endl;
				char asn;
				cout << "you want to buy?(y/n)" << endl;
				cin >> ans;
				if (ans == "y" || ans == "Y") {
					buy_footballer();
				}
				else if (ans == "n" || ans == "N") {
					userMenu();
				}
			}
			else {
				competition.top1();
			}
			break;
		case 7:
			luckyWheel();
			break;
		case 8:
			exit = true;
			break;
		}
	}
}

void User::luckyWheel() {
	srand(time(NULL));
	int Bouns_choice = (rand() % 4 + 1);
	string reward_choice;
	if (luckywheel_counter == 1) {
		cout << "Sorry, you have used your luckwheel. Luckywheel can be used only one time. " << endl;
		return;
	}
	else
	{
		cout << "Welcome...Lucky wheel offers you many rewards but you can only win one reward !" << endl;
		cout << "The rewards are : 10 bouns points , 10k free budget , remove yellow card , remove red card or none ! " << endl;
		cout << "Do you want to claim your reward ? " << endl;
		cin >> reward_choice;
		if (reward_choice == "yes" || reward_choice == "Yes" || reward_choice == "Y" || reward_choice == "y") {
			if (Bouns_choice == 1) {
				cout << "Sorry ! You ran out of luck today...you earned nothing." << endl;
				luckywheel_counter++;
				return;
			}
			else if (Bouns_choice == 2) {
				cout << "Congrats ! You won a yellow card removal" << endl;
				user[current_user].totalPoint = user[current_user].totalPoint + 1;
				luckywheel_counter++;
				return;
			}
			else if (Bouns_choice == 3) {
				cout << "Congrats ! You won 10k free budget " << endl;
				user[current_user].budget = user[current_user].budget + 10000;
				luckywheel_counter++;
				return;
			}
			else if (Bouns_choice == 4) {
				cout << "Congrats ! You won 10 bouns points added to your total points " << endl;
				user[current_user].totalPoint = user[current_user].totalPoint + 10;
				luckywheel_counter++;
				return;
			}
			else if (Bouns_choice == 5) {
				cout << "Congrats ! You won a red card removal " << endl;
				user[current_user].totalPoint = user[current_user].totalPoint + 3;
				luckywheel_counter++;
				return;
			}
		}
	}

}

void User::sortFootballer() {
	for (auto club = league[current_league].clubs.begin(); club != league[current_league].clubs.end(); ++club) {
		for (int i = 0; i < club->leageTeam_Members.size()-1;i++) {
			int max_index = i;
			for (int j = i+1; j < club->leageTeam_Members.size(); j++) {
				if (club->leageTeam_Members[j]->totalPoint > club->leageTeam_Members[max_index]->totalPoint) {
					max_index = j;
				}
			}
			if (max_index != i) {
				swap(club->leageTeam_Members[i] , club->leageTeam_Members[max_index]);
			}
		}
	}
}

