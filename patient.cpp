#include "patient.h"
#include <iostream>
using namespace std;

void addPatient(Patient patient[], int& count, int max_num_of_patients) {
    char choice;
    do {
        if (count == max_num_of_patients) {
            cout << "ERROR. Can't exceed max number of patients\n";
        } else {
            cout << "ID: ";
            cin >> patient[count].patient_id;

            cout << "Age: ";
            cin >> patient[count].patient_age;

            cin.ignore(); // clear leftover newline

            cout << "Name: ";
            getline(cin, patient[count].patient_name);

            cout << "Diagnosis: ";
            getline(cin, patient[count].diagnosis);

            count++;
            cout << "Add another patient? (y/n): ";
            cin >> choice;
        }
    } while (choice == 'y' || choice == 'Y');
}

void displayPatients(const Patient patient[], int count) {
    for (int i = 0; i < count; i++) {
        cout << patient[i].patient_id << " - "
             << patient[i].patient_name << " - "
             << patient[i].patient_age << " - "
             << patient[i].diagnosis << endl;
    }
}
