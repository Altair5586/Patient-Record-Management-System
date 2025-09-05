#include <iostream>
#include <string>

using namespace std;

const int MAX_PATIENTS = 100; // Maximum number of patients

struct Patient {
    string name;
    int age;
    string gender;
};

void addPatient(Patient patients[], int& count) {
    if (count >= MAX_PATIENTS) {
        cout << "Cannot add more patients. Maximum limit reached." << endl;
        return;
    }

    Patient newPatient;
    cout << "Enter patient name: ";
    cin >> newPatient.name;
    cout << "Enter patient age: ";
    cin >> newPatient.age;
    cout << "Enter patient gender: ";
    cin >> newPatient.gender;

    patients[count] = newPatient;
    count++;

    cout << "Patient added successfully!" << endl;
}

void displayPatients(const Patient patients[], int count) {
    if (count == 0) {
        cout << "No patients in the system." << endl;
        return;
    }

    cout << "\nList of patients:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << endl;
    }
}

int searchPatient(const Patient patients[], int count, const string& name) {
    for (int i = 0; i < count; i++) {
        if (patients[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deletePatient(Patient patients[], int& count, const string& name) {
    int index = searchPatient(patients, count, name);
    if (index == -1) {
        cout << "Patient not found." << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        patients[i] = patients[i + 1];
    }
    count--;

    cout << "Patient record deleted successfully!" << endl;
}

int main() {
    Patient patients[MAX_PATIENTS];
    int count = 0;
    int choice;

    do {
        cout << "\tHospital Management System\n" << endl;
        cout << "1. Add patient" << endl;
        cout << "2. Display patients" << endl;
        cout << "3. Search patient" << endl;
        cout << "4. Delete patient record" << endl;
        cout << "5. Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients, count);
                break;
            case 2:
                displayPatients(patients, count);
                break;
            case 3: {
                string name;
                cout << "Enter the name of the patient to search: ";
                cin >> name;
                int index = searchPatient(patients, count, name);
                if (index == -1) {
                    cout << "Patient not found." << endl;
                } else {
                    cout << "Patient found at index " << index + 1 << "." << endl;
                    cout << "Name: " << patients[index].name << endl;
                    cout << "Age: " << patients[index].age << endl;
                    cout << "Gender: " << patients[index].gender << endl;
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter the name of the patient to delete: ";
                cin >> name;
                deletePatient(patients, count, name);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}