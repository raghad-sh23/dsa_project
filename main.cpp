#include "patient.h"
#include "queue.h"
#include "stack.h"
#include "priorityqueue.h" 

#include <string>
using namespace std;
#include <iostream>

int main() {
    const int MAX = 100;
    Patient patient[MAX];
    int patientCount = 0;

    Stack undoStack;

    int choice;
    do {
        cout << "\n--- Hospital Patient Record System ---\n";
        cout << "1. Add New Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Add Treatment Record\n";
        cout << "4. Undo Last Treatment\n";
        cout << "5. View Last Treatment\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addPatient(patient, patientCount, MAX);
                break;
            case 2:
                displayPatients(patient, patientCount);
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
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
