#ifndef COMPANY_H
#define COMPANY_H
#include <Queue> 
#include <vector>
#include "Station.h"
#include "Bus.h"
#include "Event.h"
using namespace std;

class Company {
private:
    int hour;
    int min;
    int time_between_stations;
    queue<Bus> Busses_Queue; // Queue for buses
    queue<Station> Stations_Queue; // Queue for stations
    queue<Station> Stations_Queue;
    queue<Bus> Busses_Queue;
    queue<Event> Events_Queue;
    queue<Event> Moving_Queue;
    queue<Event> Finished_Events_Queue;
public:
    Company(int startHour, int startMin, int timeBetweenStations);
    void Read_File();
    void Print_Station(Station* station);
    void Move_Bus_To_Station();
    void Check_For_Arrived_Events();
    void Update_Moving_List();
    void Update_Stations();
    void Start();
};

#endif /* COMPANY_H */