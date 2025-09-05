Hospital Management System (C++)

This project is a simple Hospital Management System built using C++.  
It allows basic management of patient records including adding, displaying, searching, and deleting patient data.  
The system is console-based and menu-driven, making it easy to use.

Features

1. Add Patient
   - Allows the user to enter patient details such as name, age, and gender.
   - Stores new patient records until the maximum limit is reached.

2. Display Patients
   - Displays a list of all patients currently stored in the system.
   - Shows patient name, age, and gender.

3. Search Patient
   - Lets the user search for a patient by name.
   - If found, displays the patient details and index in the list.

4. Delete Patient
   - Removes a patient record from the system by name.
   - Automatically shifts remaining records to maintain order.

5. Exit
   - Provides an option to quit the system.

How It Works

- The system uses a structure `Patient` to store patient information.
- Patient records are stored in an array with a maximum capacity of 100 patients.
- Functions are implemented to handle each menu option:
  - `addPatient()`
  - `displayPatients()`
  - `searchPatient()`
  - `deletePatient()`
The program runs in a loop until the user chooses to exit.