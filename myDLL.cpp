#include "myDLL.h"
#include <iostream>

myDLL::myDLL(){
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

void myDLL::insertDataAtTail(void* dataStr_in){
    myDLL_node* node = new myDLL_node(dataStr_in, this->listSize);

    if (this->listSize == 0) {
        this->head = node;
        this->tail = node;
    }
    else if (this->listSize == 1) {
        node->prev = this->head;
        this->head->next = node;
        this->tail = node;
    }
    else {
        node->prev = this->tail;
        this->tail->next = node;
        this->tail = node;
    }
    this->listSize++;
}

void* myDLL::removeDataFromHead(){
    if (this->listSize == 0) {
        std::cerr << "ERROR !! No element can be removed !!\nExiting..." << std::endl;
        exit(-1);
    }
    
    myDLL_node* node = this->head;
    this->listSize--;
    if (this->listSize != 0) {
        this->head = this->head->next;
        this->head->prev = nullptr;
    }

    return node->dataPtr;
}

void myDLL::insertSortData(void* dataStr_in, double index_in){
    
    /* INSERT SORT : compare current node with new node from tail to head*/

    myDLL_node* node = new myDLL_node(dataStr_in, index_in);
    if (this->listSize == 0) {
        this->head = node;
        this->tail = node;
    }
    else if (this->listSize == 1) {
        // index_in < head->index : insert at head
        // index_in >= head->index : insert at tail
        if (index_in < this->head->index) { // insert at head
            node->next = this->tail;
            this->tail->prev = node;
            this->head = node;
        }
        else {                              // inset at tail
            node->prev = this->head;
            this->head->next = node;
            this->tail = node;
        }
    }
    else {
        // index_in < head->index   : insert at head
        // index_in > tail->index   : insert at tail
        // else                     : insert sort
        if (index_in < this->head->index) {         // insert at head
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
        }
        else if (index_in > this->tail->index) {    // insert at tail
            node->prev = this->tail;
            this->tail->next = node;
            this->tail = node;
        }
        else {
            myDLL_node* cnode = this->tail->prev;   // current node
            myDLL_node* lnode = this->tail;         // last node

            for (unsigned i = 0; i < this->listSize - 1; i++) {
                if (index_in > cnode->index) {
                    node->next = lnode;
                    node->prev = cnode;
                    cnode->next = node;
                    lnode->prev = node;
                    break;
                }
                lnode = cnode;
                cnode = cnode->prev;
            }
            /*
            myDLL_node* cnode = this->head->next;   // current node
            myDLL_node* pnode = this->head;         // previous node

            for (unsigned i = 0; i < this->listSize; i++) {
                if (index_in < cnode->index) {
                    node->next = cnode;
                    node->prev = pnode;
                    cnode->prev = node;
                    pnode->next = node;
                    break;
                }
                pnode = cnode;
                cnode = cnode->next;
            }
            */
        }
    }
    this->listSize++;
}

void myDLL::print(){
    myDLL_node* node = this->head;
    for (unsigned i = 0; i < this->listSize; i++) {
        std::cout << (char*)node->dataPtr;
        if (i != this->listSize - 1) std::cout << " ";
        node = node->next;
    }
    std::cout << " | ";
    node = this->tail;
    for (unsigned i = 0; i < this->listSize; i++) {
        std::cout << (char*)node->dataPtr;
        if (i != this->listSize - 1) std::cout << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

unsigned int myDLL::get_listSize(){
    return this->listSize;
}
