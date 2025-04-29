#ifndef QUEUE_H
#define QUEUE_H

#include "patient.h"
#include <iostream>
using namespace std;

class EmergencyQueue {
private:
    static const int MAX = 100;
    Patient queue[MAX];
    int size;

public:
    EmergencyQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(Patient p);
    void dequeue();
    void display();
};

#endif 
