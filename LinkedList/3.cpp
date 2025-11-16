#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    public:
    Node(int datal, Node* nextl) {
        data = datal;
        next = nextl;
    }
    public:
    Node(int datal) {
        data = datal;
        next = nullptr;
    }
};

// -------------------  DELETION ---------------------
// head
Node* deleteHeadLL(Node* head) {
    if (head == NULL) return head;

    Node* temp = head;
    head = head -> next;
    delete temp;

    return head;
}

// position
Node* deletePosLL(Node* head, int index) {
    if (head == NULL) return NULL;

    if (index == 0) {
        // Node* temp = head;
        head = head -> next;
        // delete temp;
        return head;
    }

    int pos = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        pos++:
        if (index == pos) {
            prev -> next = temp -> next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}


// value
Node* deleteValueLL(Node* head, int value) {
    if (head == NULL) return NULL;

    if (head -> data == value) {
        // Node* temp = head;
        head = head -> next;
        // delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        if (temp -> data == value) {
            prev -> next = temp -> next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}


// last (or) tail
Node* deleteTailLL(Node* head) {
    if (head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    delete (temp -> next);
    temp -> next = NULL;

    return head;
}



int main {



    return 0;
}