#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "patient.h"
#include <iostream>
using namespace std;

class PriorityQueue {
private:
    static const int MAX = 100;
    Patient queue[MAX];
    int size;

public:
    PriorityQueue();
    bool isFull();
    bool isEmpty();
    void insert(Patient p);
    Patient removeHighestPriority();
    void display();
};

#endif 
