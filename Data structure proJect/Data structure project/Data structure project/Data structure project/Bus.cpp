class Busses
{
    string type;
    int capacity;
    int checkupInterval;
    int checkupTime;
    int journeysCompleted;

public:

    string getType() { return type; }
    int getCapacity() { return capacity; }
    int getCheckupInterval() { return checkupInterval; }
    int getCheckupTime() { return checkupTime; }
    int getJourneysCompleted() { return journeysCompleted; }

    void setType(string newType) { type = newType; }
    void setCapacity(int newCapacity) { capacity = newCapacity; }
    void setCheckupInterval(int newInterval) { checkupInterval = newInterval; }
    void setCheckupTime(int newTime) { checkupTime = newTime; }
    void setJourneysCompleted(int newJourneys) { journeysCompleted = newJourneys; }



};