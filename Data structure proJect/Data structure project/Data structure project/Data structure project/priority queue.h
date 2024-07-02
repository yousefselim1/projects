#pragma once
#ifndef _UI
#define _UI
#include <iostream>
using namespace std;
#include <iostream>
#include <cstdlib> 
#include "Company.h"


class UI
{

public:



    void simpleSimulator(Company& company) {

        company.loadFromFile("");

        // Simulation loop
        for (int timestep = 0; timestep < 1080; ++timestep) {

            Queue<Event*> currentEvents = company.EventList.getEventsAtTimestep(timestep);


            while (!currentEvents.isEmpty()) {
                Event* event = currentEvents.Edequeue();

                if (event->getEventType() == "A")
                {
                    ArrivalEvent <Passenger> arrive;
                    arrive.Execute();

                }
                else if (event->getEventType() == "L")
                {
                    LeaveEvent<Passenger> leave;
                    leave.Execute();
                }
            }


            for (int stationIndex = 0; stationIndex < company.getNumStations(); ++stationIndex) {
                int randomNumber = rand() % 100 + 1;


                Event* event;
                if (randomNumber >= 1 && randomNumber <= 25)
                {

                    event->SPlist->Edequeue();
                    company.FinishedEventsList.enqueue(event);
                }
                else if (randomNumber >= 20 && randomNumber <= 30)
                {
                    event->WPlist->Edequeue();
                    company.FinishedEventsList.enqueue(event);
                }
                else if (randomNumber >= 50 && randomNumber <= 60)
                {
                    event->NPlist->Edequeue();
                    company.FinishedEventsList.enqueue(event);
                }
            }

            company.FinishedEventsList.display();
        }
    }

};

#endif