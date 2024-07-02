#ifndef _Station
#define _Station
#include <iostream>
#include<Queue>
using namespace std;

enum Direction { forward, backward };
class Station
{
private:
	Direction direction;
	int numStations;
	int currentStation;
	int checkupTime;

public:

	queue<Busses> ForwardBuses;
	queue<Busses> BackwardBuses;
	queue<Busses> Wbuses;
	queue<Busses> Mbuses;
	queue <Passenger> SPlist;
	queue <Passenger> NPlist;
	queue <Passenger> WPlist;

	Direction getDirection() { return direction; }
	int getnumStations() { return numStations; }
	int getcurrentStatin() { return currentStation; }
	int getcheckupTime() { return checkupTime; }

	void setDirection(Direction dir) { direction = dir; }
	void setnumStation(int numStation) { numStations = numStation; }
	void setcurStation(int curStation) { currentStation = curStation; }
	void setcheckUp(int check) { checkupTime = check; }
};

#endif