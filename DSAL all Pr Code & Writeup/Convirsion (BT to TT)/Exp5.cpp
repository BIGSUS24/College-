#include <iostream>
using namespace std;

// Node definition for the Threaded Binary Tree
class node {
public:
    int data;
    int lbit, rbit;   // Left and right bit flags (0 = thread, 1 = child)
    node *left, *right;

    node() {
        data = 0;
        lbit = rbit = 0;
        left = right = nullptr;
    }
};

// Threaded Binary Tree class
class TBT {
private:
    node *root;
    node *dummy;

public:
    TBT() {
        root = nullptr;
        dummy = nullptr;
    }

    void create(int num);                // Insert node
    void insert(node *trav, node *temp); // Helper for recursive insert
    void preorder();                     // Preorder traversal
    void display();                      // User input + display
};

// Create a node and insert it into the TBT
void TBT::create(int num) {
    node *trav, *temp;
    temp = new node();
    temp->data = num;
    temp->lbit = 0;
    temp->rbit = 0;

    if (root == nullptr) {
        // Create dummy node
        dummy = new node();
        dummy->data = -9999;
        dummy->left = temp;
        dummy->right = dummy;

        // Setup root
        temp->left = dummy;
        temp->right = dummy;
        root = temp;
    } else {
        trav = root;
        insert(trav, temp);  // Recursively insert into correct position
    }
}

// Insert a new node into the TBT maintaining threads
void TBT::insert(node *trav, node *temp) {
    if (temp->data < trav->data) {
        if (trav->lbit == 0) {
            // Insert as left child with thread updates
            temp->left = trav->left;
            temp->right = trav;
            trav->left = temp;
            trav->lbit = 1;
        } else {
            insert(trav->left, temp);
        }
    } else if (temp->data > trav->data) {
        if (trav->rbit == 0) {
            // Insert as right child with thread updates
            temp->right = trav->right;
            temp->left = trav;
            trav->right = temp;
            trav->rbit = 1;
        } else {
            insert(trav->right, temp);
        }
    }
    // Duplicates are ignored
}

// Preorder traversal using threads
void TBT::preorder() {
    node *trav = root;

    while (trav != dummy) {
        // Visit node
        cout << trav->data << " ";

        // Move to left child if exists
        if (trav->lbit == 1) {
            trav = trav->left;
        } else {
            // Otherwise follow threads until right child found
            while (trav->rbit == 0 && trav->right != dummy) {
                trav = trav->right;
            }
            trav = trav->right;
        }
    }
    cout << endl;
}

// Handles user input and calls traversal
void TBT::display() {
    int n, i, data;
    cout << "\nEnter the number of nodes: ";
    cin >> n;

    cout << "Enter the data in the nodes:\n";
    for (i = 0; i < n; i++) {
        cin >> data;
        create(data);
    }

    cout << "\nPreorder Traversal:\n";
    preorder();
}

// Main function to execute TBT operations
int main() {
    TBT T;
    T.display();
    return 0;
}

