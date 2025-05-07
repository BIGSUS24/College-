#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class student {
    string name, div, address;
    int roll;

public:
    void getdata();
    void displayAll();
    void insert_record();
    void delete_record();
    void search_record();
};

void student::getdata() {
    // Accepting student data from the user
    cout << "\nEnter Roll No, Division, Name and Address of Student: ";
    cin >> roll;
    cin.ignore();  // To ignore any leftover newline characters
    getline(cin, div);
    getline(cin, name);
    getline(cin, address);
}

void student::insert_record() {
    fstream out;
    out.open("Record11.txt", ios::app | ios::binary);  // Open the file in append binary mode

    student s1;
    s1.getdata();  // Get student data

    out.write((char*)&s1, sizeof(s1));  // Write the student object to the file

    out.close();
}

void student::displayAll() {
    fstream out;
    out.open("Record11.txt", ios::in | ios::binary);  // Open the file in input binary mode

    if (!out) {
        cout << "\nUnable to open the file.\n";
        return;
    }

    cout << "\nThe Contents of file are.......\n\n";
    cout << "ROLL" << setw(15) << "Division" << setw(15) << "NAME" << setw(15) << "ADDRESS\n";

    student s2;
    while (out.read((char*)&s2, sizeof(s2))) {
        // Display each student's details
        cout << s2.roll << setw(15) << s2.div << setw(15) << s2.name << setw(15) << s2.address << endl;
    }

    out.close();
}

void student::delete_record() {
    fstream out, temp;
    student s2;
    int item;

    out.open("Record11.txt", ios::in | ios::binary);  // Open the original file for reading
    temp.open("temp.txt", ios::out | ios::binary);  // Open a temporary file for writing

    cout << "\nEnter Roll_No to delete: ";
    cin >> item;

    bool found = false;
    while (out.read((char*)&s2, sizeof(s2))) {
        if (s2.roll != item) {
            temp.write((char*)&s2, sizeof(s2));  // Write all records except the one to be deleted
        } else {
            found = true;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    } else {
        cout << "Record deleted successfully." << endl;
    }

    out.close();
    temp.close();

    remove("Record11.txt");  // Remove the original file
    rename("temp.txt", "Record11.txt");  // Rename the temporary file to the original name
}

void student::search_record() {
    int item;
    bool found = false;

    cout << "\nEnter Roll_No to search: ";
    cin >> item;

    fstream out;
    out.open("Record11.txt", ios::in | ios::binary);  // Open the file in binary read mode

    student s2;
    while (out.read((char*)&s2, sizeof(s2))) {
        if (s2.roll == item) {
            cout << "\nRecord found:\n";
            cout << "Roll No: " << s2.roll << "\nDivision: " << s2.div << "\nName: " << s2.name << "\nAddress: " << s2.address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No such record found.\n";
    }

    out.close();
}

int main() {
    student t1;
    int ch;

    fstream out;
    out.open("Record11.txt", ios::out | ios::binary);  // Initialize the file if not already created
    out.close();

    while (1) {
        cout << "\n*******  SEQUENTIAL ACCESS FILE PROGRAM USING C++ **********\n\n";
        cout << "1.INSERT RECORD\n2.DISPLAY All Records\n3.SEARCH\n4.DELETE\n5.EXIT\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t1.insert_record();
                cout << "\nRecord Inserted..\n\n";
                break;
            case 2:
                t1.displayAll();
                break;
            case 3:
                t1.search_record();
                break;
            case 4:
                t1.delete_record();
                break;
            case 5:
                exit(0);
        }
    }

    return 0;
}

