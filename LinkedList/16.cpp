// ------- Delete the Middle Node of the Linked List -------

Node* delMid(Node* head) {
    if (!head || !head -> next) return NULL;

    // initialise show at head
    Node* slow = head;
    // initialise head 2 steps ahead of slow
    Node* fast = head -> next -> next;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // slow is at one node before middle node

    // Node* middle = slow -> next;
    // slow -> next = middle -> next;
    // delete middle;

    // --- (or)
    slow -> next = slow -> next -> next;
    return head;
}
// TC - O(n)