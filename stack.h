#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

struct TreatmentRecord {
    string patientName;
    string treatmentDetails;
};

class Stack {
private:
    static const int MAX = 100;
    TreatmentRecord records[MAX];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(TreatmentRecord record);
    TreatmentRecord pop();
    TreatmentRecord peek();
};

#endif

