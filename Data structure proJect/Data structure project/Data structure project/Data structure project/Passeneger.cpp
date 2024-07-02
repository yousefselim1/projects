#include "Passenger.h"
#include <iostream>
using namespace std;
#include <string>

//functions of Passenger class
void Passenger::set_start_station(int start_s) {
	start_station = start_s;
}

int Passenger::get_start_station() {
	return start_station;
}

void Passenger::set_end_station(int end_s) {
	end_station = end_s;
}

int Passenger::get_end_station() {
	return end_station;
}

void Passenger::set_Get_on_time(int Get_on_t) {
	Get_on_time = Get_on_t;
}

int Passenger::get_Get_on_time() {
	return Get_on_time;
}

void Passenger::set_Get_off_time(int Get_off_t) {
	Get_off_t = Get_off_t;
}

int Passenger::get_Get_off_time() {
	return Get_off_time;
}


