#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = -1; 
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == MAX - 1;
}

void Stack::push(const TreatmentRecord& record) {
    if (isFull()) {
        cout << "error: Cannot add record. Stack is full.\n";
        return;
    }
    records[++top] = record;
}

TreatmentRecord Stack::pop() {
    if (isEmpty()) {
        cout << "error: Cannot undo. Stack is empty.\n";
        return TreatmentRecord(); // return empty record
    }
    return records[top--];
}

TreatmentRecord Stack::peek() const {
    if (isEmpty()) {
        cout << "error: No records to view.\n";
        return TreatmentRecord();
    }
    return records[top];
}
