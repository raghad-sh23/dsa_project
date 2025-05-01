#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient {
    string patient_name;
    long long patient_id;
    int patient_age;
    string diagnosis;
    int priority;
};

struct Node {
    Patient data;
    Node* next;

    Node(Patient p) {
        data = p;
        next = nullptr;
    }
};

// Array for general patients (with appointments)
void addPatient(Patient patient[], int& count, int max_num_of_patients);
void displayPatients(const Patient patient[], int count);

// Linked list for walk-in patients (no appointments)
void insertPatient(Node*& head, const Patient& p);
void displayPatients(Node* head);

#endif
