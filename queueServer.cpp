#include "queueServer.h"
#include <iostream>

queueServer::queueServer(int n, double mu, EventList* global_event_list) {
    this->mu = mu;
    this->busy = false;
    this->queue = new EventList();
    this->global_event_list = global_event_list; 
    this->exp_rand = new exponentialRand();

    this->n = n;
    complete_packet = new ll[n];
    accumulate_time = new double[n];
    for (int i = 0; i < n; i++) {
        accumulate_time[i] = 0.0;
        complete_packet[i] = 0;
    }
}

void queueServer::enQueue(EventNode* event) {
    if (event->event_type != PKT_ARRIVAL) {
        std::cerr << "(enQueue) ERROR!! There is an invalid type packet, instead of PKT_ARRIVAL!" << std::endl;
        exit(0);
    }
    
    this->queue->insertEventNodeAtTail(event);
    
    if (this->busy == false) {
        this->deQueue();
    }
}

void queueServer::deQueue() {
    if (queue->get_listSize() == 0) {     // the queue is empty
        this->busy = false;
        return;
    }
    
    EventNode* event = (EventNode*)queue->removeEventNode();
    
    if (event->event_type != PKT_ARRIVAL) {
        std::cerr << "(deQueue) ERROR!! There is an invalid type packet, instead of PKT_ARRIVAL!" << std::endl;
        exit(0);
    }

    double waiting_time = global_event_list->getMasterTime() - event->event_time;
    if (waiting_time < 0) std::cout << "Warning!!!" << std::endl;
    event->event_time = global_event_list->getMasterTime() + exp_rand->eRand();
    
    global_event_list->insertEventNode(event);
    this->busy = true;
    
    complete_packet[event->event_id] += 1;
    accumulate_time[event->event_id] += waiting_time;
}
