#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // For system()
using namespace std;

// Constants
const int maxrow = 10;

// Arrays to store employee data
string EmpName[maxrow] = {};
string EmpId[maxrow] = {};

// Load existing records from file
void OpenFile() {
    string line;
    ifstream myfile("E:\\employee.txt");
    if (myfile.is_open()) {
        int x = 0;
        while (getline(myfile, line) && x < maxrow) {
            // Split by comma
            size_t pos = line.find(',');
            if (pos != string::npos) {
                EmpId[x] = line.substr(0, pos);
                EmpName[x] = line.substr(pos + 1);
                // Remove leading space from name
                if (!EmpName[x].empty() && EmpName[x][0] == ' ')
                    EmpName[x] = EmpName[x].substr(1);
                x++;
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open the file.\n";
    }
}

// Add new employee record
void AddRecord() {
    char name[50];
    char empno[5];
    cin.ignore();  // Clear input buffer

    cout << "Employee Id: ";
    cin.getline(empno, 5);

    cout << "Employee Name: ";
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++) {
        if (EmpId[x].empty()) {
            EmpId[x] = empno;
            EmpName[x] = name;
            break;
        }
    }
}

// Display all employee records
void ListRecord() {
    system("CLS");
    cout << "Current Records\n";
    cout << "===========================================\n";
    cout << "No.     |  ID    |  NAME\n";
    cout << "-----------------------------------------\n";
    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (!EmpId[x].empty()) {
            counter++;
            cout << "  " << counter << "     |  " << EmpId[x] << "  |  " << EmpName[x] << "\n";
        }
    }
    if (counter == 0) {
        cout << "No records to display\n";
    }
    cout << "-----------------------------------------\n";
}

// Search employee by ID
void searchRecord(string search) {
    system("CLS");
    cout << "Search Result\n";
    cout << "=====================================\n";
    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (EmpId[x] == search) {
            counter++;
            cout << "Found: ID = " << EmpId[x] << ", Name = " << EmpName[x] << "\n";
            break;
        }
    }
    if (counter == 0) {
        cout << "No records found.\n";
    }
    cout << "----------------------------------\n";
}

// Delete employee by ID
void DeleteRecord(string search) {
    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (EmpId[x] == search) {
            EmpId[x] = "";
            EmpName[x] = "";
            counter++;
            cout << "Record deleted successfully.\n";
            break;
        }
    }
    if (counter == 0) {
        cout << "ID not found!\n";
    }
}

// Save all records to file
void SaveToFile() {
    ofstream myfile("E:\\employee.txt");
    for (int x = 0; x < maxrow; x++) {
        if (!EmpId[x].empty()) {
            myfile << EmpId[x] << ", " << EmpName[x] << "\n";
        }
    }
    myfile.close();
}

// Main Menu
int main() {
    string eId;
    int option;

    system("CLS");
    OpenFile();  // Load file data on start

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. Search Record\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "=========================\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1:
            AddRecord();
            system("CLS");
            break;

        case 2:
            cin.ignore();
            cout << "Enter Employee ID to delete: ";
            getline(cin, eId);
            DeleteRecord(eId);
            break;

        case 3:
            cin.ignore();
            cout << "Enter Employee ID to search: ";
            getline(cin, eId);
            searchRecord(eId);
            break;

        case 4:
            ListRecord();
            break;

        case 5:
            SaveToFile();
            cout << "Data saved. Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (option != 5);

    return 0;
}

