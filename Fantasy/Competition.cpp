#include "Competition.h"
#include "Global.h"
#include "User.h"
#include <vector>


Competition::Competition()
{

}

void Competition::calcPoint()
{
	for (int i = 0; i < user.size(); i++) {
		for (int j = 0; j < user[i].members.size(); j++) {

			user[i].totalPoint +=  footballer.find(user[i].members[j])->second.point;

		}
	}
	

}

void Competition::sort() {
	for (int i = 0; i < user.size()-1; i++) {
		int max_index = i;
		for (int j = i+1; j < user.size(); j++) {
			
			if (user[j].totalPoint > user[max_index].totalPoint) {
				max_index = j;
			}
		}
		if (max_index != i) {
			swap(user[i], user[max_index]);
		}
	}
}

void Competition::top3()
{

	sort();
	bool exit = 0;
	int choic;
	while (!exit) {
		std::cout << "1- Premier League" << endl;
		std::cout << "2- La Liga" << endl;
		std::cout << "3- Exit" << endl;
		cin >> choic;

		switch (choic) {
		case 1:
			for (int i = 0; i < 3; i++) {
				if (user[i].choose - 1) {
					cout << i + 1 << "- " << user[i].userName << "\t" << user[i].totalPoint << endl;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 3; i++) {
				if (user[i].choose - 1) {
					cout << i + 1 << "- " << user[i].userName << "\t" << user[i].totalPoint << endl;
				}
			}
			break;
		case 3:
			exit = true;
			break;
		}
	}

}

void Competition::top1()
{
	sort();
	bool exit = 0;
	int choic;
	while (!exit) {
		std::cout << "1- Premier League" << endl;
		std::cout << "2- La Liga" << endl;
		std::cout << "3- Exit" << endl;
		cin >> choic;

		switch (choic) {
		case 1:
			for (int i = 0; i < 1; i++) {
				if (user[i].choose - 1) {
					cout << "................The Winnerrrrr................" << endl;
					cout << i + 1 << "- " << user[i].userName << " " << "points: " << user[i].totalPoint << endl;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 1; i++) {
				if (user[i].choose - 1) {
					cout << "................The Winnerrrrr................" << endl;
					cout << i + 1 << "- " << user[i].userName << " " << "points: " << user[i].totalPoint << endl;
				}
			}
			break;
		case 3:
			exit = true;
			break;
		}
	}
	
}

