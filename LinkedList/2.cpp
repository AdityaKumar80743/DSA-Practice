#include <bits/stdc++.h>

using namespace std;

struct Node {
    public:
    // insted of int data we can write - T data 
    // so it can used for any data type

    int data;
    Node* next;

    public:
    // constructor
    Node(int datal, Node* nextl) {
        data = datal;
        next = nextl;
    }
    // constructor
    Node(int datal) {
        data = datal;
        next = nullptr;
    }
};

// convert array to linked list
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
        // mover = mover -> next
    }
    return head;
}

// print all element in linked list
void printll(Node* head) {
    // iterate through the linked list
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// length or size of linked list
int lengthll(Node* head) {
    int size = 0;
    // iterate through the linked list
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
        size++;
    }
    return size;
}


// find a target in linked list
bool isPresent(Node* head, int target) {
    Node* temp = head;
    while (temp) 
        if (temp -> data == target) return true;
        temp = temp -> next;
    }
    return false;
}


int main {
    vector<int> arr = {1,2,3,4,5};

    Node* y = new Node(arr[0], nullptr);
    cout << y;
    // output : memory adress to the new Node created     

    // -----------------------------
    Node* head = convertArr2LL(arr);
    cout << head -> data;

    // --------------- ------------
    
    



    return 0;
}