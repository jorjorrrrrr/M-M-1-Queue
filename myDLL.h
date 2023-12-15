#ifndef MYDLL_H
#define MYDLL_H

struct myDLL_node {
    myDLL_node* next;	    // pointing to the next node in the list
    myDLL_node* prev;		// pointing to the previous node in the list
    void* dataPtr;	        // pointing to a c-style string
    int index;	            // used for insertion sort
    myDLL_node(void* dataPtr, int index) : next(nullptr),
                                            prev(nullptr),
                                            dataPtr(dataPtr),
                                            index(index) {}
};


class myDLL {
public:
    myDLL();	            // constructor
    void insertDataAtTail(void* dataStr_in);
    void* removeDataFromHead();
    void insertSortData(void* dataStr_in, int index_in);
    void print();
private:
    myDLL_node* head;	    //pointing to the 1st node in the list
    myDLL_node* tail;		// pointing to the last node in the list
    unsigned int listSize;  // number of nodes in the list
};



#endif
