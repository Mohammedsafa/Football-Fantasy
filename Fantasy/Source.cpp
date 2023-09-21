#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Admin.h"
#include "LeagueTeam.h"
#include "League.h"
#include "Global.h"
#include "Competition.h"
#include <string>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

//##bouns
//#function
//gehad marwan
//void luckyWheel();
//#gui
//Safa - Cover - Osama
//
//#Marwan
//void sell_footballer(string footballerName);
//void replace_footballer();
//void displayMyteam();
//void displayleague();
//void display();
//
//#Safa
//void sortFootballer();
//void readFile();
//void removeTeam();
//int setPoints();
//void userMenu();
//
//#Gehad
//void writeFile();
//void createTeam();
//void buy_footballer();
//void adminMenu();
//void Start();
//
//#Cover
//Footballer* getFootballer(string name);
//void addFootballer();
//void removeFootballer();
//void resetPoints();
//
//#osama
//void addTeam();
//void chooseleague();
//void calcPoint();
//void top3();
//void signUpUser();
//void signInUser();
//
//#Youssef
//void accountUser();
//void accountAdmin();
//void sort();
//void top1();
//void signInAdmin();
//void signUpAdmin();





//files
void readFile();
void writeFile();



//Start....
void signInUser();
void signInAdmin();
void signUpUser();
void signUpAdmin();
void accountUser();
void accountAdmin();
void Start();


int main() {
	
	readFile();
	Start();
	writeFile();
 }

//Function signin and signup
void accountUser() {
	string response;
	std::cout << "Do You have an account? " << endl;
	std::cin>>response;
	if (response == "Yes" || response == "yes" || response == "Y" || response == "y") {
		signInUser();
	}
	else if (response == "No" || response == "no" || response == "N" || response == "n") {
		signUpUser();
	}

}
void accountAdmin() {
	string response;
	cout << "Do You have an account? " << endl;
	std::cin>> response;
	if (response == "Yes" || response == "yes" || response == "Y" || response == "y") {
		signInAdmin();
	}
	else if (response == "No" || response == "no" || response == "N" || response == "n") {
		signUpAdmin();
	}

}
void Start() {
	//start welcome
	std::cout << ".........Welcome to Fantasy......." << endl;

	//Admin or User	
	string response;
	std::cout << "Do you like Sign in as an Admin or as a User? (quit or Quit to exit) " << endl;
	std::cin>> response;
	if (response == "Admin" || response == "admin") {\
		Admin adm;
		accountAdmin();
		adm.adminMenu();
	}
	else if (response == "User" || response == "user") {
		accountUser();
		User u;
		std::string ans;
		cout << "Do you have a team: " << endl;
		std::cin >> ans;
		if (ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes") {
			u.userMenu();
		}
		else if (ans == "N" || ans == "n" || ans == "No" || ans == "no") {
			User u;
			u.createTeam();
			u.userMenu();
		}
	}
	else if (response == "Quit" || response == "quit") {
		return;
	}
}
void signUpUser() {
	User uss;
	string response;
	string name;
	cout << "let's make a new account" << endl;
	cout << "User Name: ";
	bool found;
	do {
		name = uss.getUserName();
		found = false;
		for (int i = 0; i < user.size() ; i++) {
			if (name == user[i].userName) {
				found = true;
				cout << "this user is taken, try another one" << endl;
				break;
			}
		}
	} while (found == true);

	cout << "Password: ";
	uss.getPassword();

	uss.id = auto_id_user;
	auto_id_user++;

	user.push_back(uss);

	cout << "Created successfully" << endl;
	cout << "Now you're signed up, do you like to sign in (y/n)? " << endl;
	cin >> response;
	if (response == "y" || response == "Y" || response == "yes" || response == "Yes") {
		signInUser();
	}
	else if (response == "N" || response == "n" || response == "No" || response == "no"){
		Start();
	}
}
void signUpAdmin() {
	Admin adm;
	string response;
	string name;
	cout << "let's make a new account" << endl;
	cout << "User Name: ";
	bool found;

	do {
		name = adm.getAdminName();
		found = false;
		for (int i = 0; i < admin.size(); i++) {
			if (name == admin[i].adminName) {
				found = true;
				cout << "this user is taken, try another one" << endl;
				break;
			}
		}
	} while (found == true);


	cout << "Password: ";
	adm.getPassword();
	admin.push_back(adm);

	cout << "Created successfully" << endl;
	cout << "Now you're signed up, do you like to sign in (y/n)? " << endl;
	std::cin>> response;
	if (response == "y" || response == "Y" || response == "yes" || response == "Yes") {
		signInAdmin();
	}
	else if (response == "N" || response == "n" || response == "No" || response == "no"){
		Start();
	}
}
void signInUser() {
	string name, password, response;
	bool found;

	do {

		cout << "User Name: ";
		std::cin >>name;
		cout << "Password: ";
		std::cin>>password;
		found = false;
		for (int i = 0; i < user.size(); i++) {
			if (name == user[i].userName && password == user[i].password) {
				found = true;
				cout << "Login succeeded " << endl;
				current_user = i;
				break;
			}
		}
		if (!found) {

			cout << "Sorry!Login Failed.Do you want to try again." << endl;
			std::cin>>response;
			if (response == "Yes" || response == "yes" || response == "Y" || response == "y") {
				continue;
			}
			else if(response == "N" || response == "n" || response == "No" || response == "no") {
				Start();
			}

		}
		break;
	} while (true);
}
void signInAdmin() {
	string name, password, response;
	bool found;

	do {
		cout << "User Name: ";
		std::cin>> name;
		cout << "Password: ";
		std::cin>> password;
		found = false;
		for (int i = 0; i < admin.size(); i++) {
			if (name == admin[i].adminName && password == admin[i].password) {
				found = true;
				cout << "Login succeeded " << endl;
				break;
			}
		}
		if (!found) {

			cout << "Sorry!Login Failed.Do you want to try again." << endl;
			std::cin>> response;
			if (response == "Yes" || response == "yes" || response == "Y" || response == "y") {
				continue;
			}
			else if(response == "N" || response == "n" || response == "No" || response == "no") {
				Start();
			}

		}
		break;
	} while (true);

}

void readFile() {
	//Read data from admin file

	Admin temp;
	fstream adminFile("adminData.txt", ios::in);
	if (!adminFile) {
		cout << "Admin File not found" << endl;
		return;
	}
	for (int i = 0; !adminFile.eof(); i++) {
		admin.push_back(temp);
		adminFile >> admin[i].adminName;
		adminFile >> admin[i].password;
	}
	adminFile.close();

	
	//read footballer data

	std::fstream fbFile("footballerData.txt",ios::in);
	if (!fbFile.is_open()) {
		std::cerr << "Failed to open footballer file." << std::endl;
		return ;
	}
	Footballer fb;
	while (fbFile) {
		fbFile >> fb.Name;
		fbFile >> fb.Position;
		fbFile >> fb.leagueTeam_name;
		fbFile >> fb.leagueTeam_id;
		fbFile >> fb.price;
		fbFile >> fb.point;
		fbFile >> fb.totalPoint;

		footballer.insert({ fb.Name,fb });
	}
	fbFile.close();
	
	//Read data from team file
	nlohmann::json jason_teamFile;
	
	std::fstream teamFile("teams.jason", ios::in);
	if (!teamFile) {
		return;
	}
	string league_content((istreambuf_iterator<char>(teamFile)), istreambuf_iterator<char>());
	jason_teamFile = nlohmann::json::parse(league_content);
	for (auto jason_league = jason_teamFile.begin(); jason_league != jason_teamFile.end(); ++jason_league) {
		League lg;
		lg.leagueName = (*jason_league)["Name"];
		for (auto jason_team = (*jason_league)["Teams"].begin(); jason_team != (*jason_league)["Teams"].end(); ++jason_team) {
			LeagueTeam lTeam;
			lTeam.leagueTeam_name = (*jason_team)["Team_name"];
			lTeam.leagueTeam_id = (*jason_team)["team_id"];
			lg.clubs.push_back(lTeam);
		}
		league.push_back(lg);
	
	}
	
	teamFile.close();

	auto_id_team = league[0].clubs.size() + league[1].clubs.size();
	for (int i = 0; i < league.size();i++) {
		for (int j = 0; j < league[i].clubs.size();j++) {
			for (auto it = footballer.begin(); it != footballer.end(); ++it) {
				if (league[i].clubs[j].leagueTeam_name == it->second.leagueTeam_name) {
					league[i].clubs[j].leageTeam_Members.push_back(&(it->second));
				}
			}
		}
	}
	
	//Read data from user file 
	User u;
	fstream userFile("userData.txt", ios::in);
	if (!userFile) {
		cout << "User File not found" << endl;
		return;
	}
	while (userFile >> u.userName >> u.password >> u.id) {
		userFile >> u.totalPoint >> u.budget >> u.customName >> u.choose;
		std::string s;
		while (userFile >> s && s != "###") {
			u.members.push_back(s);
		}
		user.push_back(u);
		u.members.clear();

	}
	userFile.close();

	auto_id_user = user.size() + 1;
	//nlohmann::json jason_userFile;
	//std::fstream userFile("user.jason", ios::in);
	//if (!userFile) {
	//	return;
	//}
	//string user_content((istreambuf_iterator<char>(userFile)), istreambuf_iterator<char>());
	//jason_userFile = nlohmann::json::parse(user_content);
	//for (auto jason_user = jason_userFile.begin(); jason_user != jason_userFile.end(); ++jason_user) {
	//	User us;
	//	us.userName= (*jason_user)["Name"];
	//	us.userName = (*jason_user)["Id"];
	//	us.userName = (*jason_user)["Point"];
	//	us.userName = (*jason_user)["Password"];
	//	us.userName = (*jason_user)["choose"];
	//	us.userName = (*jason_user)["Budget"];
	//	us.userName = (*jason_user)["CutomName"];
	//	for (auto member = (*jason_user)["Members"].begin(); jason_user != (*jason_user)["Members"].end(); ++jason_user) {
	//		std::string mem;
	//		mem = (*member)["name"];
	//		us.members.push_back(mem);
	//	}
	//	user.push_back(us);
	//
	//}
	//userFile.close();
	auto_id_user = user.size() + 1;

}
void writeFile() {
	//Write data into admin file 

	fstream adminFile("adminData.txt", ios::out);
	if (!adminFile) {
		cout << "Admin file not found" << endl;
		return;
	}
	for (int i = 0; i < admin.size(); i++) {
		adminFile << admin[i].adminName << endl;
		adminFile << admin[i].password << endl;
	}
	adminFile.close();

	//write footballer data
	fstream fbFile("footballerData.txt", ios::out);
	if (!fbFile) {
		cout << "Footballer file not found" << endl;
		return;
	}
	for (const auto& [key, value] : footballer) {
		fbFile << key << endl;
		fbFile << value.Position << endl; 
		fbFile << value.leagueTeam_name << endl; 
		fbFile << value.leagueTeam_id << endl;
		fbFile << value.price << endl;
		fbFile << value.point << endl;
		fbFile << value.totalPoint << endl;
	}
	
	fbFile.close();

	//Write data into team data
	
	//created a json object to handle writing vectors like "league" .
	nlohmann::json jason_teamFile;
	for (auto lg : league) {
		nlohmann::json league_jason;
		league_jason["Name"] = lg.leagueName;
		// Convert the team vector of objects to a JSON array
		nlohmann::json lteam_jason;
		for (auto lTeam : lg.clubs) {
			nlohmann::json team_gason;
			team_gason["Team_name"] = lTeam.leagueTeam_name;
			team_gason["team_id"] = lTeam.leagueTeam_id;
			lteam_jason.push_back(team_gason);
		}
		league_jason["Teams"] = lteam_jason;
		jason_teamFile.push_back(league_jason);
	}
	std::fstream teamFile("teams.jason", ios::out);
	if (!teamFile) {
		cout << "Faild to store team data" << endl;
		teamFile.close();
		return;
	}
	teamFile << jason_teamFile.dump(4);
	teamFile.close();

	//Write data into user file
	fstream userFile("userData.txt", ios::out);
	if (!userFile) {
		cout << "User file not found" << endl;
		return;
	}
	for (int i = 0; i < user.size(); i++) {
		userFile << user[i].userName << endl;
		userFile << user[i].password << endl;
		userFile << user[i].id << endl;
		userFile << user[i].totalPoint << endl;
		userFile << user[i].budget << endl;
		userFile << user[i].customName << endl;
		userFile << user[i].choose << endl;
		for (int j = 0; j < user[i].members.size(); j++) {
			userFile << user[i].members[j] << endl;
		}
		userFile << "###" << endl;
	}
	userFile.close();
	//nlohmann::json jason_userFile;
	//for (auto u = user.begin(); u != user.end(); ++u) {
	//	nlohmann::json user_jason;
	//	user_jason["Name"] = u->userName;
	//	user_jason["Id"] = u->id;
	//	user_jason["Point"] = u->totalPoint;
	//	user_jason["Password"] = u->password;
	//	user_jason["choose"] = u->choose;
	//	user_jason["Budget"] = u->budget;
	//	user_jason["CutomName"] = u->customName;
	//	nlohmann::json jason_members;
	//	for (auto fb = u->members.begin(); fb != u->members.end();++fb) {
	//		nlohmann::json jason_member;
	//		jason_member["name"] = *fb;
	//		jason_members.push_back(jason_member);
	//	}
	//	user_jason["Members"] = jason_members;
	//	jason_userFile.push_back(user_jason);
	//}
	//std::fstream userFile("user.jason", ios::out);
	//if (!userFile) {
	//	cout << "Faild to store user data" << endl;
	//	userFile.close();
	//	return;
	//}
	//userFile << jason_userFile.dump(4);
	//userFile.close();

}


