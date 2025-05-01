# dsa_project
# Hospital Patient Record Management System

##  Project Overview

This C++ application simulates a hospital management system that supports patient registration, emergency handling, treatment tracking, and undo functionality. It demonstrates the use of multiple data structures:
- Arrays for patients with appointments
- Linked lists for walk-in patients (without appointments)
- Priority queues for emergency critical cases
- Stacks for treatment history with undo functionality

---

##  Features

-  Register patients with appointments (stored in array)
-  Register walk-in patients without appointments (stored in linked list)
-  View all patients by category
-  Admit and serve emergency patients using a priority queue
-  Display emergency patients grouped by priority level
-  Add treatment records and undo them via stack operations

---

##  File Breakdown

| File Name                | Purpose                                                           |
|-------------------------|-------------------------------------------------------------------|
| `hospital_app.cpp`      | Main logic and user interface for the system                      |
| `patient.h`             | Core patient structure and linked list/array function headers     |
| `patient_array.cpp`     | Implements array-based patient handling                           |
| `patient_linkedList.cpp`| Implements linked list for walk-in patients                       |
| `priorityqueue.h/cpp`   | Handles emergency patients using a priority queue                 |
| `queue.cpp`             | (Optional) Supports basic queue implementation                    |
| `stack.h/cpp`           | Stack for storing and undoing treatment records                   |

---

##  Data Structures Used

- **Array**: Fixed-size storage for patients with appointments
- **Linked List**: Flexible storage for walk-in patients without appointments
- **Priority Queue**: Manages emergency patients based on priority
- **Stack**: Records treatments and allows undo functionality

---
##  How to Compile and Run

Make sure you have a C++ compiler (e.g. g++) installed.

bash
g++ -std=c++17 hospital_app.cpp patient_array.cpp patient_linkedList.cpp priorityqueue.cpp queue.cpp stack.cpp -o hospital_app
./hospital_app


---

##  Menu Options

1. Register Patient with Appointment (Array)
2. Register Walk-In Patient (Linked List)
3. Display All Patients
4. Admit Emergency Patient (Priority Queue)
5. Display Emergency Patients by Priority
6. Serve Emergency Patient
7. Add Treatment Record
8. Undo Last Treatment
9. View Last Treatment
0. Exit


