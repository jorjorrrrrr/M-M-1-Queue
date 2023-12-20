#include <iostream>
#include "myDLL.h"
#include "exponentialRand.h"
#include "EventList.h"
#include "PKTArrivalEventGenerator.h"
#include "queueServer.h"

struct CSTYLE{
    char* str;
    int index;
    CSTYLE(char* str, int index) :str(str), index(index) {}
};

int main() {

    int n = 2;
    double mu = 0.5;
    ll total_count = 10000000;

    double lambda;
    ll count = 0;
    int i;
    EventNode* event;

    EventList* global_event_list;
    queueServer* server;
    PKTArrivalEventGenerator** generators;

    global_event_list = new EventList();
    server = new queueServer(n, mu, global_event_list);
    generators = new PKTArrivalEventGenerator*[n];
    for (i = 0; i < n; i++) {
        lambda = 0.2;
        generators[i] = new PKTArrivalEventGenerator(global_event_list, lambda, i);
    }

    for (count = 0; count < total_count; count++) {
        event = global_event_list->removeEventNode();
        std::cout << "-------------- loop " << count+1 << " -----------------" << std::endl;
        std::cout << "Remove (" << event->event_id << ", " << event->event_time << ", " << ((event->event_type) ? "PKT_DEPARTURE":"PKT_ARRIVAL") << ") from global_event_list\n"; 
        global_event_list->updateMasterTime(event->event_time);
        if (event->event_type == PKT_ARRIVAL) {
            generators[event->event_id]->createNewArrival(event);
            server->enQueue(event);
        }
        else {
            delete event;
            server->deQueue();
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << i << " : " << server->calc_averagetime(i) << "\t" << server->calc_throughput(i) << std::endl;
    }

    return 0;

}

