#ifndef EVENTLISH_H
#define EVENTLISH_H
#include "myDLL.h"

enum EventType {
    PKT_ARRIVAL = 0,
    PKT_DEPARTURE,
};

struct EventNode {
    EventType event_type;
    long long event_time;
    int event_id;
};

class EventList {
public:
    EventList();
    void insertEventNode(EventNode* event);
    EventNode* removeEventNode();
    const long long getMasterTime();
    void updateMasterTime(long long);
private:
    long long MasterClockTime;
    myDLL* list;
};

#endif