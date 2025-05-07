#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Node structure for the BST
struct Bstnode {
    int data;
    Bstnode *left;
    Bstnode *right;

    // Constructor to initialize node
    Bstnode(int val) {
        data = val;
        left = right = NULL;
    }
};

// BST class encapsulating operations
class Btree {
    int n;  // number of nodes
    int x;  // input value

public:
    Bstnode *root;

    // Constructor
    Btree() {
        root = NULL;
    }

    // Insert function to add nodes recursively
    Bstnode *insert(Bstnode *temp, int in_data) {
        if (temp == NULL) {
            return new Bstnode(in_data);
        }
        if (in_data < temp->data) {
            temp->left = insert(temp->left, in_data);
        } else {
            temp->right = insert(temp->right, in_data);
        }
        return temp;
    }

    // Function to take user input and build BST
    void input() {
        cout << "ENTER NUMBER OF ELEMENTS IN THE BST: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "NUMBER = ";
            cin >> x;
            root = insert(root, x);
        }
    }

    // Search for a value in BST
    int search(Bstnode *temp, int in_data) {
        if (temp == NULL) {
            return 0; // Not found
        } else if (temp->data == in_data) {
            return 1; // Found
        } else if (in_data < temp->data) {
            return search(temp->left, in_data);
        } else {
            return search(temp->right, in_data);
        }
    }

    // Find and print the minimum value in BST
    void minvalue(Bstnode *temp) {
        if (temp == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        while (temp->left != NULL) {
            temp = temp->left;
        }
        cout << "MINIMUM VALUE = " << temp->data << endl;
    }

    // Convert tree to its mirror
    void mirror(Bstnode *temp) {
        if (temp == NULL) return;

        // Mirror left and right subtrees recursively
        mirror(temp->left);
        mirror(temp->right);

        // Swap left and right children
        Bstnode *ptr = temp->left;
        temp->left = temp->right;
        temp->right = ptr;
    }

    // Display all traversals
    void display() {
        cout << "\n--- INORDER TRAVERSAL ---\n";
        inorder(root);
        cout << endl;

        cout << "\n--- POSTORDER TRAVERSAL ---\n";
        postorder(root);
        cout << endl;

        cout << "\n--- PREORDER TRAVERSAL ---\n";
        preorder(root);
        cout << endl;
    }

    // Inorder traversal: Left, Root, Right
    void inorder(Bstnode *temp) {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    // Postorder traversal: Left, Right, Root
    void postorder(Bstnode *temp) {
        if (temp != NULL) {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    // Preorder traversal: Root, Left, Right
    void preorder(Bstnode *temp) {
        if (temp != NULL) {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    // Calculate the depth (height) of the tree
    int depth(Bstnode *temp) {
        if (temp == NULL)
            return 0;
        return max(depth(temp->left), depth(temp->right)) + 1;
    }
};

// Main function to demonstrate functionality
int main() {
    Btree obj;
    int searchvalue;

    obj.input();            // Build the tree
    obj.display();          // Show traversals

    // Search for a value
    cout << "\nEnter the data to be searched: ";
    cin >> searchvalue;
    int found = obj.search(obj.root, searchvalue);
    if (found)
        cout << "ELEMENT FOUND\n";
    else
        cout << "ELEMENT NOT FOUND\n";

    // Find minimum value
    cout << "\nMinimum value in the Tree: ";
    obj.minvalue(obj.root);

    // Mirror the tree and display inorder
    cout << "\nMirror of Tree (Inorder Traversal): ";
    obj.mirror(obj.root);
    obj.inorder(obj.root);
    cout << endl;

    // Display depth
    cout << "\nDepth (Height) of Tree: " << obj.depth(obj.root) << endl;

    return 0;
}

