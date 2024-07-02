#pragma once
#include <string>
#include "Time.h"
using namespace std;

// parent class : Passenger
class Passenger {
protected:
	Time AT; // arrival time
	Time LT; // leave time
	Time WT; // waiting time
	int start_station;
	int end_station;
	int Get_on_time;
	int Get_off_time;
	string passtype; // Passenger type
	string SPtype; //  Special Passenger type


public:

	void set_start_station(int start_s);
	int get_start_station();
	void set_end_station(int end_s);
	int get_end_station();
	void set_Get_on_time(int Get_on_t);
	int get_Get_on_time();
	void set_Get_off_time(int Get_off_t);
	int get_Get_off_time();
};
