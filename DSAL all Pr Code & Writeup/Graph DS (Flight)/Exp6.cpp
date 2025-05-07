#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// Node structure for adjacency list
struct node {
    string vertex;
    int time;
    node *next;
};

class adjmatlist {
    int m[20][20];       // Adjacency matrix
    int n, i, j;         // Number of cities, loop counters
    char ch;
    string v[20];        // City names
    node *head[20];      // Array of pointers to head of each adjacency list
    node *temp = NULL;

public:
    // Constructor to initialize heads and matrix
    adjmatlist() {
        for (i = 0; i < 20; i++) {
            head[i] = NULL;
            for (j = 0; j < 20; j++) {
                m[i][j] = 0;
            }
        }
    }

    void getgraph();     // Input graph
    void adjlist();      // Create adjacency list
    void displaym();     // Display adjacency matrix
    void displaya();     // Display adjacency list with times
};

// Input the graph data
void adjmatlist::getgraph() {
    cout << "\nEnter number of cities (max 20): ";
    cin >> n;

    cout << "\nEnter names of cities:\n";
    for (i = 0; i < n; i++)
        cin >> v[i];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nIs there a path from " << v[i] << " to " << v[j] << "? (y/n): ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y') {
                cout << "Enter time (in minutes) to go from " << v[i] << " to " << v[j] << ": ";
                cin >> m[i][j];
            } else if (ch == 'n' || ch == 'N') {
                m[i][j] = 0;
            } else {
                cout << "Invalid input. Assuming no path.\n";
                m[i][j] = 0;
            }
        }
    }

    adjlist(); // After matrix is filled, build the list
}

// Create adjacency list from adjacency matrix
void adjmatlist::adjlist() {
    for (i = 0; i < n; i++) {
        // Create head node for each vertex
        node *p = new node;
        p->vertex = v[i];
        p->next = NULL;
        head[i] = p;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                // Create new node for adjacent city
                node *p = new node;
                p->vertex = v[j];
                p->time = m[i][j];
                p->next = NULL;

                // Append to adjacency list
                if (head[i]->next == NULL) {
                    head[i]->next = p;
                } else {
                    temp = head[i]->next;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = p;
                }
            }
        }
    }
}

// Display adjacency matrix
void adjmatlist::displaym() {
    cout << "\nAdjacency Matrix:\n\t";
    for (j = 0; j < n; j++) {
        cout << v[j] << "\t";
    }
    cout << "\n";

    for (i = 0; i < n; i++) {
        cout << v[i] << "\t";
        for (j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Display adjacency list and time to reach
void adjmatlist::displaya() {
    cout << "\nAdjacency List:\n";
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "\nAdjacency list not present.\n";
            break;
        } else {
            cout << head[i]->vertex;
            temp = head[i]->next;
            while (temp != NULL) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    // Display paths and corresponding times
    cout << "\nPaths and Time Required to Reach Cities:\n";
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "\nAdjacency list not present.\n";
            break;
        } else {
            temp = head[i]->next;
            while (temp != NULL) {
                cout << "\n" << head[i]->vertex << " -> " << temp->vertex;
                cout << "   [Time: " << temp->time << " min]";
                temp = temp->next;
            }
        }
    }
}

// Main menu-driven interface
int main() {
    int m;
    adjmatlist a;

    while (1) {
        cout << "\n\n--- Graph Menu ---";
        cout << "\n1. Enter Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Display Adjacency List";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> m;

        switch (m) {
        case 1:
            a.getgraph();
            break;
        case 2:
            a.displaym();
            break;
        case 3:
            a.displaya();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nUnknown choice. Please try again.";
        }
    }

    return 0;
}

