#include "patient.h"
#include "queue.h"
#include "stack.h"
#include "priorityqueue.h"
#include <iostream>
#include <vector>

using namespace std;

// Linked list functions
void insertPatient(Node*& head, const Patient& p);
void displayPatients(Node* head);

// Array functions
void displayPatients(const Patient patient[], int count);

// Input function (used for both general and emergency patients)
Patient inputPatient(bool includePriority = false) {
    Patient p;

    cout << "ID: ";
    cin >> p.patient_id;

    cout << "Age: ";
    cin >> p.patient_age;
    cin.ignore();

    cout << "Name: ";
    getline(cin, p.patient_name);

    cout << "Diagnosis: ";
    getline(cin, p.diagnosis);

    if (includePriority) {
        cout << "Priority (1 = High, 2 = Medium, 3 = Low): ";
        cin >> p.priority;
        cin.ignore();
    }

    return p;
}

int main() {
    const int MAX = 100;
    Patient patient[MAX];
    int patientCount = 0;

    Node* head = nullptr;         
    PriorityQueue erQueue;        
    Stack undoStack;              
    int choice;
    do {
        cout << "\n--- Hospital Patient Record System ---\n";
        cout << "1. Register Patient with Appointment (Array)\n";
        cout << "2. Register Walk-In Patient (No Appointment / Waitlist)\n";
        cout << "3. Display All Patients\n";
        cout << "4. Admit Emergency Patient (Priority Queue)\n";
        cout << "5. Serve Emergency Patient\n";
        cout << "6. Display Emergency Room Patients\n";
        cout << "7. Add Treatment Record\n";
        cout << "8. Undo Last Treatment\n";
        cout << "9. View Last Treatment\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (patientCount < MAX) {
                    Patient p = inputPatient();
                    patient[patientCount++] = p;
                    cout << "General patient added.\n";
                } else {
                    cout << "ERROR: Maximum number of patients reached.\n";
                }
                break;
            }

            case 2: {
                Patient p = inputPatient();
                insertPatient(head, p);
                cout << "Walk-in patient added to waitlist.\n";
                break;
            }

            case 3:
                cout << "\n Patients with Appointments \n";
                displayPatients(patient, patientCount);

                cout << "\n Walk-In Patients (No Appointments) \n";
                displayPatients(head);
                break;

            case 4: {
                Patient p = inputPatient(true);  // includes priority
                erQueue.insert(p);
                cout << "Emergency patient added to priority queue.\n";
                break;
            }

            case 5: {
                if (erQueue.isEmpty()) {
                    cout << "No patients in emergency queue.\n";
                } else {
                    Patient served = erQueue.removeHighestPriority();
                    cout << "Serving emergency patient: " << served.patient_name
                         << " - " << served.diagnosis << " (Priority " << served.priority << ")\n";
                }
                break;
            }

            case 6: {
                cout << "\n--- Emergency Room Patients by Priority ---\n";
            
                PriorityQueue tempQueue = erQueue;
            
                vector<Patient> priorityList[3]; // 0: priority 1, 1: priority 2, 2: priority 3
            
                while (!tempQueue.isEmpty()) {
                    Patient p = tempQueue.removeHighestPriority();
                    if (p.priority >= 1 && p.priority <= 3)
                        priorityList[p.priority - 1].push_back(p);
                }
            
                string labels[3] = {"HIGH (1)", "MEDIUM (2)", "LOW (3)"};
            
                for (int i = 0; i < 3; ++i) {
                    cout << "\n[ " << labels[i] << " Priority ]\n";
                    for (const auto& p : priorityList[i]) {
                        cout << "Name: " << p.patient_name
                             << ", ID: " << p.patient_id
                             << ", Diagnosis: " << p.diagnosis << endl;
                    }
                }
            
                break;
            }            

            case 7: {
                TreatmentRecord newRecord;
                cout << "Enter patient name for treatment: ";
                getline(cin, newRecord.patientName);
                cout << "Enter treatment details: ";
                getline(cin, newRecord.treatmentDetails);
                undoStack.push(newRecord);
                cout << "Treatment record added.\n";
                break;
            }

            case 8: {
                TreatmentRecord undone = undoStack.pop();
                if (!undone.patientName.empty()) {
                    cout << "Undone treatment for: " << undone.patientName
                         << " - " << undone.treatmentDetails << endl;
                }
                break;
            }

            case 9: {
                TreatmentRecord topRecord = undoStack.peek();
                if (!topRecord.patientName.empty()) {
                    cout << "Last treatment: " << topRecord.patientName
                         << " - " << topRecord.treatmentDetails << endl;
                }
                break;
            }

            case 0:
                cout << "Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
