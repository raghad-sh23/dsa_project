#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {  //Constructor
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == MAX - 1;
}

void Stack::push(TreatmentRecord record) {  //adding a new treatment record to top of the stack
    if (isFull()) {
        cout << "error: Cannot add record. Stack is full.\n";
        return;
    }
    records[++top] = record; // increase top and add record
}

TreatmentRecord Stack::pop() {  //removing and returning last added treatment record
    if (isEmpty()) {
        cout << "error: Cannot undo. Stack is empty.\n";
        return TreatmentRecord(); 
    }
    return records[top--];  // return record and decrease top
}

TreatmentRecord Stack::peek() {    //view top treatment record
    if (isEmpty()) {
        cout << "error: No records to view.\n";
        return TreatmentRecord();
    }
    return records[top]; //returns top record
}
