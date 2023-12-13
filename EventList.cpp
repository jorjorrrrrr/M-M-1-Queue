#include "EventList.h"


EventList::EventList() {
    this->MasterClockTime = 0;
    list = new myDLL();
}

void EventList::insertEventNode(EventNode* event) {
    this->list->insertSortData((void*)event, event->event_time);
}

EventNode* EventList::removeEventNode() {
    EventNode* event = (EventNode*)(this->list->removeDataFromHead());
    this->updateMasterTime(event->event_time);
    return event;
}


const long long EventList::getMasterTime() {
    return this->MasterClockTime;
}

void EventList::updateMasterTime(long long event_time) {
    this->MasterClockTime = event_time;
}
