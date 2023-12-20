#ifndef EVENTLISH_H
#define EVENTLISH_H
#include "myDLL.h"


enum EventType {
    PKT_ARRIVAL = 0,
    PKT_DEPARTURE,
};

struct EventNode {
    EventType event_type;
    double event_time;
    int event_id;
    EventNode(EventType event_type, double event_time, int event_id) 
        :   event_type(event_type),
            event_time(event_time),
            event_id(event_id) {}
};

class EventList {
public:
    EventList();
    void insertEventNode(EventNode* event);
    void insertEventNodeAtTail(EventNode* event);
    EventNode* removeEventNode();
    double getMasterTime();
    void updateMasterTime(double);
    void print();
    unsigned int get_listSize();
private:
    double MasterClockTime;
    myDLL* list;
};

#endif
