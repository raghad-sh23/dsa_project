#ifndef STACK_H
#define STACK_H

#include "patient.h"
#include <iostream> 
using namespace std;

struct TreatmentRecord {
    string patientName;
    string treatmentDetails;
};

class Stack {
private:
    static const int MAX = 100;  // Maximum size of the stack
    TreatmentRecord records[MAX];
    int top; 

public:
    Stack(); 
    bool isEmpty() const; 
    bool isFull() const;  
    void push(const TreatmentRecord& record); // add a new record
    TreatmentRecord pop(); // undo last treatment (pop record)
    TreatmentRecord peek() const; // view top record without removing
};

#endif 
