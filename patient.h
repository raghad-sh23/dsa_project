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

#endif
