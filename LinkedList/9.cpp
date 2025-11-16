
// -------------------- reverse LL ------------------
// iterative appraoch
Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* temp = head;

    while (temp) {
        next = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

// TC - O(n) 
// SC - O(1)


// recursive approach
Node* reverseRecursive(Node* head) {
    if (head == NULL || head -> next ++ NULL) return head;

    Node* newHead = reverseRecursive(head -> next);
    Node* front = head -> next;

    front -> next = head;
    head -> next = NULL;

    return newHead;
}

// TC - O(n)
// sc - O(1)

