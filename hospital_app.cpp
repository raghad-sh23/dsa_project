#include "patient.h"
#include "queue.h"
#include "stack.h"
#include "priorityqueue.h"
#include <iostream>
using namespace std;

// Linked list functions
void insertPatient(Node*& head, const Patient& p);
void displayPatients(Node* head);

// Array functions
void displayPatients(const Patient patient[], int count);

// Input function
Patient inputPatient() {
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

    return p;
}

int main() {
    const int MAX = 100;
    Patient patient[MAX];  // Array-based patient storage
    int patientCount = 0;

    Node* head = nullptr;  // Linked list for critical patients

    PriorityQueue erQueue;  // For managing critical patients using priority

    Stack undoStack;

    int choice;
    do {
        cout << "\n--- Hospital Patient Record System ---\n";
        cout << "1. Add New Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Add Treatment Record\n";
        cout << "4. Undo Last Treatment\n";
        cout << "5. View Last Treatment\n";
        cout << "6. Add Critical Patient to Priority Queue\n";
        cout << "7. Serve Critical Patient from Priority Queue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                char isCritical;
                cout << "Is the patient critical? (y/n): ";
                cin >> isCritical;
                cin.ignore();

                Patient p = inputPatient();

                if (isCritical == 'y' || isCritical == 'Y') {
                    insertPatient(head, p);
                    cout << "Critical patient added.\n";
                } else {
                    if (patientCount < MAX) {
                        patient[patientCount++] = p;
                        cout << "Regular patient added.\n";
                    } else {
                        cout << "ERROR: Max number of patients reached.\n";
                    }
                }
                break;
            }

            case 2:
                cout << "\n--- Regular Patients (Array) ---\n";
                displayPatients(patient, patientCount);
                cout << "\n--- Critical Patients (Linked List) ---\n";
                displayPatients(head);
                break;

            case 3: {
                TreatmentRecord newRecord;
                cout << "Enter patient name for treatment: ";
                getline(cin, newRecord.patientName);
                cout << "Enter treatment details: ";
                getline(cin, newRecord.treatmentDetails);
                undoStack.push(newRecord);
                cout << "Treatment record added.\n";
                break;
            }

            case 4: {
                TreatmentRecord undone = undoStack.pop();
                if (!undone.patientName.empty()) {
                    cout << "Undone treatment for: " << undone.patientName
                         << " - " << undone.treatmentDetails << endl;
                }
                break;
            }

            case 5: {
                TreatmentRecord topRecord = undoStack.peek();
                if (!topRecord.patientName.empty()) {
                    cout << "Last treatment: " << topRecord.patientName
                         << " - " << topRecord.treatmentDetails << endl;
                }
                break;
            }

            case 6: {
                Patient p = inputPatient();  // reuse your input function
                erQueue.insert(p);
                cout << "Patient added to priority queue.\n";
                break;
            }
            
            case 7: {
                if (erQueue.isEmpty()) {
                    cout << "No patients in the priority queue.\n";
                } else {
                    Patient served = erQueue.removeHighestPriority();
                    cout << "Serving critical patient: " << served.patient_name
                         << " - " << served.diagnosis << " (Priority " << served.priority << ")\n";
                }
                break;
            }
            
            case 8:
                cout << "Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
