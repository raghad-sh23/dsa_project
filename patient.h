#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient {
    string patient_name;
    long long patient_id; // Allows long IDs
    int patient_age;
    string diagnosis;
    int priority;
};

void addPatient(Patient patient[], int& count, int max_num_of_patients);

void displayPatients(const Patient patient[], int count);

#endif 
