#include "Company.h"
#include <Queue>
using namespace std;
#include<Queue>


Company::Company(int startHour, int startMin, int timeBetweenStations ) {
    hour = startHour;
    min = startMin;
    time_between_stations = timeBetweenStations;
 
}

void Company::Read_File() {
    ifstream file("random_file.txt");
    if (!file.is_open()) {
        std::cout << "File not found or unable to open.\n";
        return;
    }

    // Read the file header
    string line;
    int stationCount, timeBetweenStation, wbusCount, mbusCount ;

    if (getline(file, line)) {
        istringstream iss(line);
        iss >> stationCount >> timeBetweenStation;
        
        this->hour = 4; // Assign start hour
        this->min = 0; // Assign start minute
        this->time_between_stations = timeBetweenStation; // Assign time between stations
    }


    // Process events from the file
    while (getline(file, line)) {
        istringstream iss(line);
        char eventType;
        iss >> eventType;
        if (eventType == 'A') {
            char passengerType;
            int eventHour, eventMin, id, srcStation, dstStation;
            string extraInfo;

            iss >> passengerType >> eventHour >> eventMin >> id >> srcStation >> dstStation;
            if (passengerType == 'SP') {
                iss >> extraInfo;
            }

            // Create an Event object 
            Event newEvent(passengerType, eventHour, eventMin, id, srcStation, dstStation, extraInfo);
            Events_List.push_back(newEvent); // Add the Event object to Events_List
        }
        else if (eventType == 'L') {
            int eventHour, eventMin, id, srcStation;
            iss >> eventHour >> eventMin >> id >> srcStation;
            // Handle Leave Event (remove passenger from relevant data structures)
        }
    }
    file.close();
}

void Company::Check_For_Arrived_Events() {
    int current_hour = // get current hour ;
    int current_minute = // get current minute ;

    while (!Events_Queue.empty()) {
        Event current_event = Events_Queue.front();
        if (current_event.event_hour <= current_hour && current_event.event_minute <= current_minute) {
            if (current_event.eventType == 'A') {
                Moving_Queue.push(current_event); // Assuming Moving_Queue is used to process arrived events
            }
            else if (current_event.eventType == 'L') {
                // Handle Leave Event
            }
            Events_Queue.pop();
        }
        else {
            break;
        }
    }
}

void Company::Update_Moving_List() {
    for (auto it = Moving_List.begin(); it != Moving_List.end();) {
        Bus* bus = *it;

       

        if (
            it = Moving_List.erase(it );                   // condition to check if the bus has reached ) {
                                                         // Update station and bus statuses
                                                         // Move passengers from bus to the station
                                                          // Add new passengers to the bus

        }
        else {
                                                   // If the bus hasn't reached its destination yet, move it closer
          ++it;
        }
    }
}

void Company::Update_Stations() {
    while (!Stations_Queue.empty()) {
        Station* current_station = Stations_Queue.front();
 
 // Update the station's status or perform necessary operations

        Move_Bus_To_Station();

        Stations_Queue.pop();
        Stations_Queue.push(current_station);
    }
}

void Company::Start() {
    Read_File(); 

    while () {
        Check_For_Arrived_Events();
        Update_Stations();                         // condition to continue simulation 

     // Other operations

        this_thread::sleep_for(std::chrono::milliseconds());
    }

    // Cleanup after end .
}