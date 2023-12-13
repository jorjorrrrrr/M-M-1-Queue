#ifndef MYDLL_H
#define MYDLL_H

struct myDLL_node {
    myDLL_node* next;	    // pointing to the next node in the list
    myDLL_node* prev;		// pointing to the previous node in the list
    char* dataPtr;	        // pointing to a c-style string
    int index;	            // used for insertion sort
    myDLL_node(char* dataPtr, int index) :dataPtr(dataPtr), 
                                            index(index),
                                            next(nullptr),
                                            prev(nullptr) {}
};


class myDLL {
public:
    myDLL();	            // constructor
    void insertDataAtTail(char* dataStr_in);
    char* removeDataFromHead();
    void insertSortData(char* dataStr_in, int index_in);
    void print();
private:
    myDLL_node* head;	    //pointing to the 1st node in the list
    myDLL_node* tail;		// pointing to the last node in the list
    unsigned int listSize;  // number of nodes in the list
};



#endif