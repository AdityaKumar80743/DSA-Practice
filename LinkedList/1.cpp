#include <iostream>

using namespace std;

// struct are by default public 
// unlike class which are private by default
// struct is used to store collect of variables and data
// can consider it as simple type of classes
struct Node {
    // stores the data
    int data; 
    // store the memory adress to the next element
    Node* next;
};


int main { 
    // what does new do ????
    // ans - creates a object dynamically in the heap not stack memory
    // stack memory location are destroyed when the functions ends
    // but in heap memory - we have manually create it - (using new) 
    // and manually delete is - (delete) 

    // what does Node* do ??
    // ans - it stores the pointer to next memory location


    // create 3 nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // assign data 
    head -> data = 10;
    second -> data = 20;
    third -> data = 30;

    // connect the nodes 
    head -> next = second;
    second -> next = third;
    third -> next = NULL;

    // print the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    return 0;
}