#include "PKTArrivalEventGenerator.h"



PKTArrivalEventGenerator::PKTArrivalEventGenerator(EventList* global_event_list){
    this->lambda = 0.05; 
    this->packet_id = 0;
    this->global_event_list = global_event_list;
    exp_rand = new exponentialRand(0, lambda);
    
    // generate an event and put it into global event list
    EventNode* new_event = new EventNode(PKT_ARRIVAL, exp_rand->eRand(), this->packet_id);
    this->global_event_list->insertEventNode(new_event);
}

PKTArrivalEventGenerator::PKTArrivalEventGenerator(EventList* global_event_list, double lambda, int packet_id){
    this->lambda = lambda; 
    this->packet_id = packet_id;
    this->global_event_list = global_event_list;
    exp_rand = new exponentialRand(0, lambda);
    
    // generate an event and put it into global event list
    EventNode* new_event = new EventNode(PKT_ARRIVAL, exp_rand->eRand(), this->packet_id);
    this->global_event_list->insertEventNode(new_event);
}


void PKTArrivalEventGenerator::createNewArrival(EventNode* event){
    int event_time = event->event_time + exp_rand->eRand();
    EventNode* new_event = new EventNode(PKT_ARRIVAL, event_time, this->packet_id);
    this->global_event_list->insertEventNode(new_event);
}
