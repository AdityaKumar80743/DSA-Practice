// ------------------------ middle of LL --------------------

// --- brute force
Node* middleOfLL(Node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) return head;

    // get the length of the LL 
    int len = 0;
    Node* temp = head;

    while(temp) {
        len++;
        temp = temp -> next;
    }

    // get the middle node
    int mid = (len / 2) + 1;
    temp = head;
    for (int i = 1; i < mid; i++) temp = temp -> next;
    
    // return middle node
    return temp;
}
// TC - O(n + n/2)
// sc - O(1) 



// --- optimal
Node* middleOfLL2(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}
// TC - O(n / 2) 
// sc - O(1)