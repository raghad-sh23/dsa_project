#include "patient.h"
#include <iostream>
using namespace std;


void insertPatient(Node*& head, const Patient& p) {
    Node* newNode = new Node(p);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Walk-in patient added to waitlist.\n";
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

