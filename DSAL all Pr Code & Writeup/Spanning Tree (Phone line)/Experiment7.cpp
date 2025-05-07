#include <iostream>
using namespace std;

const int INF = 9999; // A large constant representing no direct connection (infinity)

class Tree {
    int a[20][20];      // Adjacency matrix to store connection costs between offices
    int visited[20];    // Array to track visited offices
    int v, e;           // v = number of offices, e = number of connections

public:
    void input();       // Function to input the graph data
    void display();     // Function to display the adjacency matrix
    void minimum();     // Function to compute the minimum cost to connect all offices (Prim's Algorithm)
};

// Function to take input of offices and connection costs
void Tree::input() {
    cout << "Enter the number of offices: ";
    cin >> v;

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < v; i++) {
        visited[i] = 0; // Mark all offices as unvisited initially
        for (int j = 0; j < v; j++) {
            a[i][j] = INF; // No connection initially (infinity)
        }
    }

    cout << "Enter the number of connections (edges): ";
    cin >> e;

    // Take each connection as input
    for (int i = 0; i < e; i++) {
        int src, dest, cost;
        cout << "Enter the two offices to connect (1-based index): ";
        cin >> src >> dest;

        // Validate input range
        if (src < 1 || src > v || dest < 1 || dest > v) {
            cout << "Invalid office number. Try again.\n";
            i--; // Retry the same connection
            continue;
        }

        cout << "Enter the phone company charge for this connection: ";
        cin >> cost;

        // Store the cost in both directions (undirected graph)
        a[src - 1][dest - 1] = a[dest - 1][src - 1] = cost;
    }
}

// Function to display the adjacency matrix
void Tree::display() {
    cout << "\nAdjacency Matrix (Office-to-Office Connection Cost):\n\n";

    // Print column headers
    cout << "     ";
    for (int j = 0; j < v; j++) {
        cout << "O" << j + 1 << "   ";
    }
    cout << "\n";

    // Print separator
    cout << "   ";
    for (int j = 0; j < v; j++) {
        cout << "-----";
    }
    cout << "\n";

    // Print each row with row headers
    for (int i = 0; i < v; i++) {
        cout << "O" << i + 1 << " | ";
        for (int j = 0; j < v; j++) {
            if (a[i][j] == INF)
                cout << "INF ";
            else
                cout.width(3), cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}


// Function to calculate and display minimum cost connections using Prim's Algorithm
void Tree::minimum() {
    visited[0] = 1; // Start from the first office
    int total = 0;  // Total minimum cost

    cout << "\nMinimum cost connections using Prim's Algorithm:\n";

    // Repeat until all offices are connected (v - 1 edges)
    for (int count = 0; count < v - 1; count++) {
        int min = INF; // Initialize minimum to a large number
        int u = -1, v_ = -1;

        // Find the edge with minimum cost from visited to unvisited vertex
        for (int i = 0; i < v; i++) {
            if (visited[i]) {
                for (int j = 0; j < v; j++) {
                    if (!visited[j] && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v_ = j;
                    }
                }
            }
        }

        // If a valid edge was found
        if (u != -1 && v_ != -1) {
            visited[v_] = 1; // Mark the new office as visited
            total += min;    // Add to the total cost

            // Output this connection
            cout << "Connection: Office " << (u + 1) << " -> Office " << (v_ + 1)
                 << " | Charge: " << min << endl;
        }
    }

    // Display the final minimum total cost
    cout << "Total Minimum Cost to Connect All Offices: " << total << endl;
}

// Main function with a menu to drive the program
int main() {
    Tree t;
    int ch;

    do {
        // Display menu
        cout << "\n=========== MENU ===========\n";
        cout << "1. Input Data\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Find Minimum Cost Connection\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        // Handle menu choices
        switch (ch) {
        case 1:
            t.input(); // Input office and connection data
            break;
        case 2:
            t.display(); // Display the adjacency matrix
            break;
        case 3:
            t.minimum(); // Compute and display MST
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 4); // Loop until the user exits

    return 0;
}

