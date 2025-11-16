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


// ----------------- INSERTION -------------
// before head
Node* insertHead(Node* head, int val) {
    Node* newHead = new Node(val,nullptr, head);

    head -> back = newHead;
    return newHead;
}

// before tail
Node* insertTail(Node* head, int val) {
    if (head == NULL) return new Node(val);

    Node* temp = head;
    while(temp -> next) {
        temp = temp -> next;
    }

    Node* prev = temp -> back;
    Node* newTail = new Node(val, prev, temp);

    prev -> next = newTail;
    temp -> back = newTail;

    return head;
}

// kth
Node* insertKth(Node* head, int k, int val) {
    if (k == 1) insertHead(head, val);
    
    int pos = 0;
    Node* temp = head;
    while (temp) {
        pos++;
        if (pos == k) break;
        temp = temp -> next;
    }

    Node* newNode = new Node(val, temp -> back, temp);
    temp -> back -> next = newNode;
    temp -> back = newNode; 

    return head;
}

// node
void insertNode(Node* node, int val) {
    Node* prev = node -> back;
    Node* newNode = new Node(val, prev, node);

    prev -> next = newNode;
    node -> back = newNode;
}


int main() {

    return 0;
}