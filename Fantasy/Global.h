#pragma once
#include <iostream>
#include <string>
#include "Footballer.h"
#include "LeagueTeam.h"
#include "User.h"
#include <unordered_map>
#include "Admin.h"
#include "League.h"

inline unordered_map <string, Footballer> footballer;
inline vector<User> user;
inline vector<Admin> admin;
inline vector <League> league;

inline int current_user;
inline int auto_id_user;
inline int auto_id_team;
inline int current_league;
inline int luckywheel_counter = 0;

