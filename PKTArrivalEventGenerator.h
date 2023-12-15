#ifndef PKTARRIVALEVENTGENERATOR_H
#define PKTARRIVALEVENTGENERATOR_H

#include "EventList.h"
#include "exponentialRand.h"

class PKTArrivalEventGenerator{
public:
    PKTArrivalEventGenerator(EventList* global_event_list);
    PKTArrivalEventGenerator(EventList* global_event_list, double lambda, int packet_id);
    void createNewArrival(EventNode* event);
private:
    double lambda;
    int packet_id;
    EventList* global_event_list;
    exponentialRand* exp_rand;
};


#endif
