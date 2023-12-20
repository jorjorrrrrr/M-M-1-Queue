#ifndef QUEUESERVER_H
#define QUEUESERVER_H

#include "EventList.h"
#include "exponentialRand.h"

typedef long long ll;

class queueServer{
public:
    queueServer(int n, double mu, EventList* global_event_list);
    void enQueue(EventNode* event);
    void deQueue();
private:
    double mu;
    bool busy;
    EventList* queue;
    EventList* global_event_list;
    exponentialRand* exp_rand;
    int n;
    ll* complete_packet;
    double* accumulate_time;
};

#endif
