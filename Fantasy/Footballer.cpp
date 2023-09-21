#include <iostream>
#include <string>
#include "Footballer.h"
#include <cstdlib>
#include <time.h>
#include "Global.h"

using namespace std;



Footballer::Footballer()
{
}

int Footballer::setPoints()
{
	
	point = (rand() % 10);
	return point;
}

int Footballer::resetPoints()
{
	totalPoint = 0;
	return totalPoint;
}

