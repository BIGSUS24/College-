#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;

struct node {
    char name[20];
    node *next;  // Points to the next node (siblings)
    node *down;  // Points to the next level (children)
    int flag;    // To check if there's any child (used for chapters, sections, subsections)
};

class Gll {
    char ch[20]; 
    int n, i;    
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;
    
public:
    node *create();
    void insertBook();
    void insertChapter();
    void insertSection();
    void insertSubsection();
    void displayBook();
};

node* Gll::create() {
    node *p = new node;  // Dynamically allocate memory for a new node
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin >> p->name;
    return p;
}

void Gll::insertBook() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists.\n";
    }
}

void Gll::insertChapter() {
    if (head == NULL) {
        cout << "\nThere is no book.\n";
    } else {
        cout << "\nHow many chapters you want to insert: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Gll::insertSection() {
    if (head == NULL) {
        cout << "\nThere is no book.\n";
    } else {
        cout << "\nEnter the name of the chapter where you want to insert the section: ";
        cin >> ch;
        
        temp = head;
        if (temp->flag == 0) {
            cout << "\nThere are no chapters in the book.\n";
        } else {
            temp = temp->down;
            while (temp != NULL) {
                if (!strcmp(ch, temp->name)) {
                    cout << "\nHow many sections you want to insert: ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        t1 = create();
                        if (temp->flag == 0) {
                            temp->down = t1;
                            temp->flag = 1;
                            t2 = temp->down;
                        } else {
                            while (t2->next != NULL)
                                t2 = t2->next;
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void Gll::insertSubsection() {
    if (head == NULL) {
        cout << "\nThere is no book.\n";
    } else {
        cout << "\nEnter the name of the chapter where you want to insert the subsection: ";
        cin >> ch;
        
        temp = head;
        if (temp->flag == 0) {
            cout << "\nThere are no chapters in the book.\n";
        } else {
            temp = temp->down;
            while (temp != NULL) {
                if (!strcmp(ch, temp->name)) {
                    cout << "\nEnter the name of the section where you want to insert the subsection: ";
                    cin >> ch;
                    
                    if (temp->flag == 0) {
                        cout << "\nThere are no sections in the chapter.\n";
                    } else {
                        temp = temp->down;
                        while (temp != NULL) {
                            if (!strcmp(ch, temp->name)) {
                                cout << "\nHow many subsections you want to insert: ";
                                cin >> n;
                                for (i = 0; i < n; i++) {
                                    t1 = create();
                                    if (temp->flag == 0) {
                                        temp->down = t1;
                                        temp->flag = 1;
                                        t2 = temp->down;
                                    } else {
                                        while (t2->next != NULL)
                                            t2 = t2->next;
                                        t2->next = t1;
                                    }
                                }
                                break;
                            }
                            temp = temp->next;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void Gll::displayBook() {
    if (head == NULL) {
        cout << "\nBook does not exist.\n";
    } else {
        temp = head;
        cout << "\nNAME OF BOOK: " << temp->name;
        if (temp->flag == 1) {
            temp = temp->down;
            while (temp != NULL) {
                cout << "\n\t\tNAME OF CHAPTER: " << temp->name;
                t1 = temp;
                if (t1->flag == 1) {
                    t1 = t1->down;
                    while (t1 != NULL) {
                        cout << "\n\t\t\t\tNAME OF SECTION: " << t1->name;
                        t2 = t1;
                        if (t2->flag == 1) {
                            t2 = t2->down;
                            while (t2 != NULL) {
                                cout << "\n\t\t\t\t\t\tNAME OF SUBSECTION: " << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main() {
    Gll g;
    int x;
    while (1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Insert Book";
        cout << "\n2. Insert Chapter";
        cout << "\n3. Insert Section";
        cout << "\n4. Insert Subsection";
        cout << "\n5. Display Book";
        cout << "\n6. Exit";
        cin >> x;
        
        switch (x) {
            case 1: g.insertBook(); break;
            case 2: g.insertChapter(); break;
            case 3: g.insertSection(); break;
            case 4: g.insertSubsection(); break;
            case 5: g.displayBook(); break;
            case 6: exit(0); break;
            default: cout << "\nInvalid Choice\n"; break;
        }
    }
    return 0;
}

