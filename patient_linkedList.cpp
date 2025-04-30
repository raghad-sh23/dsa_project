#include "patient.h"
#include <iostream>
using namespace std;


Node::Node(Patient p) {
    data = p;
    next = nullptr;
}

void insertPatient(Node*& head) {
    Patient p;

    cout << "Enter Patient ID: ";
    cin >> p.patient_id;

    cout << "Enter Age: ";
    cin >> p.patient_age;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, p.patient_name);

    cout << "Enter Diagnosis: ";
    getline(cin, p.diagnosis);

    Node* newNode = new Node(p);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayPatients(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data.patient_id << " - "
             << current->data.patient_name << " - "
             << current->data.patient_age << " - "
             << current->data.diagnosis << endl;
        current = current->next;
    }
}

