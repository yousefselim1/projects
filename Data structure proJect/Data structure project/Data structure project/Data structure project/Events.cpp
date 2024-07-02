#ifndef _Event
#define _Event
#include <iostream>
#include"PriorityQueue.h"
using namespace std;


class Event
{
protected:
	string EventType;
	int EventHours;
	int EventMinuts;
	int Id;
	int Hours;
	int Minuts;
	int Seconds;
	string ArrivalTime;
	int StartStation;
	int EndStation;
	int GetOnOff;
	string Type;
	int maxWait;
	string SpType;

public:

	string getSp() { return SpType; }
	string getEventType() { return EventType; }
	int getID() { return Id; }
	string getArrTime() { return ArrivalTime; }
	string getType() { return Type; }
	int getStart() { return StartStation; }
	int getEnd() { return EndStation; }
	int getOnTime() { return GetOnOff; }
	int getWait() { return maxWait; }
	int getHours() { return EventHours; }
	int getMinuts() { return EventMinuts; }

	void setSp(string Sp) { SpType = Sp; }
	void setEventType(string et) { EventType = et; }
	void setID(int id) { Id = id; }
	void setArrTime(string arrive) { ArrivalTime = arrive; }
	void setType(string type) { Type = type; }
	void setStart(int start) { StartStation = start; }
	void setEnd(int end) { EndStation = end; }
	void setOnTime(int ontime) { GetOnOff = ontime; }
	void setWait(int wait) { maxWait = wait; }
	void setHours(int hours) { EventHours = hours; }
	void setMinuts(int minuts) { EventMinuts = minuts; }

	Event(int hours, int minuts, int id)
	{
		EventHours = hours;
		EventMinuts = minuts;
		Id = id;
	}
	virtual void Execute() = 0;
};



template<typename y>
class ArrivalEvent : public Event
{
public:
	ArrivalEvent(int hours, int minuts, string id) : Event(hours, minuts, id) {}
	PQueue <y>* SPlist;
	Queue <y>* NPlist;
	Queue <y>* WPlist;

	ArrivalEvent()
	{

	}

	void Execute() override {
		// Create a new passenger and add it to the appropriate list
		if (getEventType() == "A")
		{
			Passenger* p = new Passenger;
			p->setID(getID());
			p->setArrTime(getArrTime());
			p->setStart(getStart());
			p->setEnd(getEnd());
			p->setType(getType());

			if (p->getType() == "NP")
			{
				NPlist->enqueue(p)
			}

			if (p->getType() == "WP")
			{
				WPlist->enqueue(p)
			}

			if (p->getType() == "SP")
			{
				SPlist->enqueue(p)
			}
		}


	}
};

template<typename y>
class LeaveEvent : public Event {
public:
	LeaveEvent(int hours, int minuts, string id) : Event(hours, minuts, id) {}

	void Execute() override
	{
		ArrivalEvent <y> arr;
		if (getEventType() == "L")
		{
			arr.NPlist->deleteByKey(getID());
			arr.SPlist->deleteByKey(getID());
			arr.WPlist->deleteByKey(getID());
		}
	}
};



#endif