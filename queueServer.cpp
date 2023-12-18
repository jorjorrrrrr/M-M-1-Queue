#include "queueServer.h"

queueServer::queueServer(int n, double mu, EventList* global_event_list){
    this->mu = mu;
    this->busy = false;
    this->queue = new EventList();
    this->global_event_list = global_event_list; 
    this->exp_rand = new exponentialRand();

    complete_packet = new ll[n];
    accumulate_time = new double[n];
    for (int i = 0; i < n; i++) {
        accumulate_time[i] = 0.0;
        complete_packet[i] = 0;
    }
}

//void enQueue(EventNode* event);
