/***********************************************************************
Program for performing various operations on
Index Sequential File organization using binary files in C++.
************************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

class EMP_CLASS {
    // Structure to hold employee record
    typedef struct EMPLOYEE {
        char name[10];  // Employee name (limited to 9 characters + null terminator)
        int emp_id;     // Employee ID
        int salary;     // Salary
    } Rec;

    // Structure to hold index information
    typedef struct INDEX {
        int emp_id;     // Employee ID (acts as key)
        int position;   // Position of the record in the employee file
    } Ind_Rec;

    Rec Records;         // One employee record
    Ind_Rec Ind_Records; // One index record

public:
    EMP_CLASS() {
        // Constructor initializes employee record with default (empty) values
        strcpy(Records.name, "");
        Records.emp_id = -1;
        Records.salary = -1;
    }

    // Member functions
    void Create();
    void Display();
    void Delete();
    void Add();
    void Search();
};

// Function to create new employee and index files
void EMP_CLASS::Create() {
    int i = 0;
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;

    // Open files in binary output mode
    indexfile.open("IND.DAT", ios::out | ios::binary);
    seqfile.open("EMP.DAT", ios::out | ios::binary);

    // Input loop for adding records
    do {
        cout << "\n Enter Name: ";
        cin >> Records.name;
        cout << " Enter Emp_ID: ";
        cin >> Records.emp_id;
        cout << " Enter Salary: ";
        cin >> Records.salary;

        // Write to employee file
        seqfile.write((char*)&Records, sizeof(Rec));

        // Prepare and write index record
        Ind_Records.emp_id = Records.emp_id;
        Ind_Records.position = i;
        indexfile.write((char*)&Ind_Records, sizeof(Ind_Rec));

        i++; // increment position
        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    // Close files
    seqfile.close();
    indexfile.close();
}

// Function to display all valid employee records
void EMP_CLASS::Display() {
    fstream seqfile, indexfile;
    seqfile.open("EMP.DAT", ios::in | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::binary);

    cout << "\n The Contents of file are ...\n";

    // Read each index and fetch corresponding employee record
    while (indexfile.read((char*)&Ind_Records, sizeof(Ind_Rec))) {
        int pos = Ind_Records.position * sizeof(Rec);
        seqfile.seekg(pos, ios::beg);
        seqfile.read((char*)&Records, sizeof(Rec));

        // Display only valid (non-deleted) records
        if (Records.emp_id != -1) {
            cout << "\nName: " << Records.name;
            cout << "\nEmp_ID: " << Records.emp_id;
            cout << "\nSalary: " << Records.salary << "\n";
        }
    }

    seqfile.close();
    indexfile.close();
}

// Function to logically delete an employee record by emp_id
void EMP_CLASS::Delete() {
    int id, pos = -1;
    cout << "\n For deletion, enter the Emp_ID: ";
    cin >> id;

    // Open files for update
    fstream seqfile("EMP.DAT", ios::in | ios::out | ios::binary);
    fstream indexfile("IND.DAT", ios::in | ios::out | ios::binary);

    // Find matching emp_id in index file
    while (indexfile.read((char*)&Ind_Records, sizeof(Ind_Rec))) {
        if (id == Ind_Records.emp_id) {
            pos = Ind_Records.position;
            Ind_Records.emp_id = -1; // Logical deletion in index
            break;
        }
    }

    if (pos == -1) {
        cout << "\n The record is not present in the file";
        return;
    }

    // Logical deletion in employee file
    int offset = pos * sizeof(Rec);
    seqfile.seekp(offset);
    strcpy(Records.name, "");
    Records.emp_id = -1;
    Records.salary = -1;
    seqfile.write((char*)&Records, sizeof(Rec));

    // Rewrite deleted index entry
    offset = pos * sizeof(Ind_Rec);
    indexfile.seekp(offset);
    indexfile.write((char*)&Ind_Records, sizeof(Ind_Rec));

    seqfile.close();
    indexfile.close();

    cout << "\n The record is Deleted!!!";
}

// Function to add a new employee record to the end of the files
void EMP_CLASS::Add() {
    fstream seqfile("EMP.DAT", ios::app | ios::binary);
    fstream indexfile("IND.DAT", ios::in | ios::binary);

    // Calculate new position for index
    indexfile.seekg(0, ios::end);
    int pos = indexfile.tellg() / sizeof(Ind_Rec);
    indexfile.close();

    // Reopen index file in append mode
    indexfile.open("IND.DAT", ios::app | ios::binary);

    // Get new employee data
    cout << "\n Enter the record for appending";
    cout << "\nName: ";
    cin >> Records.name;
    cout << "Emp_ID: ";
    cin >> Records.emp_id;
    cout << "Salary: ";
    cin >> Records.salary;

    // Append to files
    seqfile.write((char*)&Records, sizeof(Rec));
    Ind_Records.emp_id = Records.emp_id;
    Ind_Records.position = pos;
    indexfile.write((char*)&Ind_Records, sizeof(Ind_Rec));

    seqfile.close();
    indexfile.close();

    cout << "\n The record is Appended!!!";
}

// Function to search for a record by emp_id
void EMP_CLASS::Search() {
    fstream seqfile("EMP.DAT", ios::in | ios::binary);
    fstream indexfile("IND.DAT", ios::in | ios::binary);

    int id, pos = -1;
    cout << "\n Enter the Emp_ID for searching the record: ";
    cin >> id;

    // Search index file for the given emp_id
    while (indexfile.read((char*)&Ind_Records, sizeof(Ind_Rec))) {
        if (id == Ind_Records.emp_id) {
            pos = Ind_Records.position;
            break;
        }
    }

    if (pos == -1) {
        cout << "\n Record is not present in the file";
        return;
    }

    // Fetch record from employee file using position
    int offset = pos * sizeof(Rec);
    seqfile.seekg(offset, ios::beg);
    seqfile.read((char*)&Records, sizeof(Rec));

    if (Records.emp_id == -1) {
        cout << "\n Record is not present in the file";
    } else {
        cout << "\n The Record is present in the file and it is...";
        cout << "\n Name: " << Records.name;
        cout << "\n Emp_ID: " << Records.emp_id;
        cout << "\n Salary: " << Records.salary;
    }

    seqfile.close();
    indexfile.close();
}

// Main function to present menu and perform user-selected operations
int main() {
    EMP_CLASS List;
    char ans = 'y';
    int choice;

    do {
        cout << "\n Main Menu :- ";
        cout << "\n 1. Create";
        cout << "\n 2. Display";
        cout << "\n 3. Delete";
        cout << "\n 4. Add";
        cout << "\n 5. Search";
        cout << "\n 6. Exit";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: List.Create(); break;
            case 2: List.Display(); break;
            case 3: List.Delete(); break;
            case 4: List.Add(); break;
            case 5: List.Search(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice!";
        }

        cout << "\n\nDo you want to go back to Main Menu? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}

