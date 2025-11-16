#include <bits/stdc++.h>
using namespace std;

// ------------ DOUBLY LINKED LIST -------------
class Node {
    public:
    int data;
    Node* back;
    Node* next;

    public: 
    Node(int datal, Node* backl = nullptr, Node* nextl = nullptr) {
        data = datal;
        back = backl;
        next = nextl;
    }
};

// print Dll
void print(Node* head) {
    while (head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

// convert list ot Dll
Node* arr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i=1; i<arr.size(); i++) {
        Node* temp = Node(arr[i], prev, nullptr);
        prev -> next = temp;
        prev = temp;
        // (or) prev = prev -> next
    }
    return head;
}


// ----------------- DELETION -------------
// head
Node* delHead(Node* head) {
    if (head == NULL || head -> next == NULL) return NULL;

    // Node* prev = head;
    head = head -> next;
    head -> back = nullptr;
    // prev -> next = nullptr;
    // delete prev; 
    return head;
}

// tail
// similar to SLL
Node* delTail(Node* head) {
    if (head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    while (temp -> next -> next) {
        temp = temp -> next;
    }
    
    temp -> next = nullptr;
    return head;
}

// DLL
Node* delTail(Node* head) {
    if (head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    while (temp -> next) {
        temp = temp -> next;
    }
    
    Node* newTail = temp -> back
    newTail -> next = nullptr;

    temp -> back = nullptr;
    delete temp;

    return head;
}

// kth
Node* delKth(Node* head, int k) {
    if (head == NULL) return NULL;

    int pos = 0;
    Node* temp = head;

    while (temp) {
        pos++; 
        if (pos == k) break;
        temp = temp -> next;
    }

    Node* prev = temp -> back;
    Node* front = temp -> next;

    // edge cases
    // DLL has only 1 elemtn - which is head
    if (prev == NULL && front == NULL) {
        delete temp;
        return NULL:
    }
    // standing at head
    else if (prev == NULL) {
        return delHead(head);
    } 
    // standing at tail
    else if (front == NULL) {
        return delTail(head);
    }

    prev -> next = front;
    front -> back = prev;

    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;

    return head;
}

// node
// constrain : node != head
Node* delNode(Node* temp) {
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if (front == NULL) {
        prev -> next = nullptr;
        temp -> back = nullptr;
        free(temp);
        return;
    }

    prev -> next = front;
    front -> back = prev;

    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;

    return temp;
}


int main() {


    return 0;
}