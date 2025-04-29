#include "queue.h"
#include "patient.h"
#include <iostream>
using namespace std;

EmergencyQueue::EmergencyQueue() {
    size = 0;
}

bool EmergencyQueue::isFull() {
    return size == MAX;
}

bool EmergencyQueue::isEmpty() {
    return size == 0;
}

void EmergencyQueue::enqueue(Patient p) {
    if (isFull()) {
        cout << "Emergency room queue is full!\n";
        return;
    }

    int i = size - 1;
    while (i >= 0 && queue[i].priority > p.priority) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = p;
    size++;
    cout << "Patient added: " << p.patient_name << " (" << p.diagnosis << ", Priority " << p.priority << ")\n";
}

void EmergencyQueue::dequeue() {
    if (isEmpty()) {
        cout << "No patients to attend.\n";
        return;
    }
    cout << "Attending to: " << queue[0].patient_name << " (" << queue[0].diagnosis << ")\n";
    for (int i = 1; i < size; ++i) {
        queue[i - 1] = queue[i];
    }
    size--;
}

void EmergencyQueue::display() {
    if (isEmpty()) {
        cout << "No patients waiting.\n";
        return;
    }

    cout << "\n--- Emergency Room Queue (by priority) ---\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << queue[i].patient_name << " (" << queue[i].diagnosis << ", Priority " << queue[i].priority << ")\n";
    }
}
