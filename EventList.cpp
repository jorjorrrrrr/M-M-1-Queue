#include "EventList.h"
#include <iostream>

EventList::EventList() {
    this->MasterClockTime = 0;
    list = new myDLL();
}

void EventList::insertEventNode(EventNode* event) {
    this->list->insertSortData((void*)event, event->event_time);
}

void EventList::insertEventNodeAtTail(EventNode* event) {
    this->list->insertDataAtTail((void*)event);
}

EventNode* EventList::removeEventNode() {
    EventNode* event = (EventNode*)(this->list->removeDataFromHead());
    this->updateMasterTime(event->event_time);
    return event;
}


double EventList::getMasterTime() {
    return this->MasterClockTime;
}

void EventList::updateMasterTime(double event_time) {
    this->MasterClockTime = event_time;
}
    
void EventList::print() {
    EventNode* event;
    for (unsigned int i = 0; i < this->get_listSize(); i++) {
        event = (EventNode*)(this->list->removeDataFromHead());
        std::cout << "(" << event->event_id << ", " << event->event_time << ", ";
        if (event->event_type == PKT_ARRIVAL)  std::cout << "PKT_ARRIVAL)->";
        else                                    std::cout << "PKT_DEPARTURE)->";
        this->list->insertDataAtTail((void*)event);
    }
    std::cout << std::endl;
}

unsigned int EventList::get_listSize() {
    return this->list->get_listSize();
}
