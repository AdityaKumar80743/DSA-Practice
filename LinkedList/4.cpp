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

// ---------------------- INSERTION ---------------------
// head
Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

// tail
Node* insertTail(Node* head, int val) {
    Node* newTail = new Node(val);
    if (head == NULL) return newTail;

    Node* temp = head;
    while (temp.next) {
        temp = temp -> next;
    }
    temp -> next = newTail;

    return head;
}

// position
Node* insertPos(Node* head,int val, int k) {
    if (head == NULL) {
        if (k == 0) return new Node(val);
        else return NULL:
    }
    if (k == 0) return new Node(val, head);

    int pos = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        pos++;
        if (pos == k) {
            Node* newNode = new Node(val);
            prev -> next = newNode;
            newNode -> next = temp;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}


Node* insertPos2(Node* head, int val, int k) {
    // edge cases

    int pos = 0;
    Node* temp = head;

    while(temp) {
        pos++;
        if (pos == k - 1) {
            Node* n = new Node(val, temp -> next);
            temp -> next = n;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// value
// insert the value to the ll before the x - x will be in ll
Node* insertVal(Node* head, int val, int x) {
    // edge cases
    if (head == NULL) return NULL:
    if (val == head -> data) return new Node(val, head);

    Node* temp = head;

    while(temp -> next) {
        if (temp -> next -> data == x) {
            Node* n = new Node(val, temp -> next);
            temp -> next = n;
            break;
        }
        temp = temp -> next;
    }
    return head;
}


int main() {



    return 0;
}