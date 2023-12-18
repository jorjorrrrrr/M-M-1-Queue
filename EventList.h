#ifndef EVENTLISH_H
#define EVENTLISH_H
#include "myDLL.h"

typedef long long ll;

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
    EventNode* removeEventNode();
    ll getMasterTime();
    void updateMasterTime(ll);
private:
    double MasterClockTime;
    myDLL* list;
};

#endif
