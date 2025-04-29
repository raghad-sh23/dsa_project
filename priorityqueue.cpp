#include "priorityqueue.h"
#include "patient.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() {
    size = 0;
}

bool PriorityQueue::isFull() {
    return size == MAX;
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

void PriorityQueue::insert(Patient p) {
    if (isFull()) {
        cout << "Priority queue is full!\n";
        return;
    }

    int i = size - 1;
    while (i >= 0 && queue[i].priority > p.priority) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = p;
    size++;
    cout << "Critical Patient added: " << p.patient_name << " (" << p.diagnosis << ", Priority " << p.priority << ")\n";
}

Patient PriorityQueue::removeHighestPriority() {
    if (isEmpty()) {
        cout << "No critical patients to attend.\n";
        return Patient();
    }
    Patient highest = queue[0];
    for (int i = 1; i < size; ++i) {
        queue[i - 1] = queue[i];
    }
    size--;
    return highest;
}

void PriorityQueue::display() {
    if (isEmpty()) {
        cout << "No critical patients waiting.\n";
        return;
    }

    cout << "\n--- Critical Patients Queue (by priority) ---\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << queue[i].patient_name << " (" << queue[i].diagnosis << ", Priority " << queue[i].priority << ")\n";
    }
}
