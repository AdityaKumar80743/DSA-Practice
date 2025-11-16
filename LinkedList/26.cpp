// ---------- Rotate a Linked List --------

// --- brute
//  tip - use for loop instead of while loop
Node* rotate(Node* head, int k) {
    // edge cases
    if (!head) return NULL;
    if (!head->next) return head;

    // rotate until k becomes zero
    while (k > 0) {
        Node* temp = head;
        // get second last node
        while (temp->next->next) {
            temp = temp -> next;
        } 
        // last element becomes the new head
        Node* newHead = temp -> next;
        // disconnect second last element from last element
        temp -> next = nullptr;
        // change the new head to last elemnet
        newHead -> next = head;
        // update new head
        head = newHead;
        // reduce the rotation left
        k--;
    }
    return head;
}
// Tc - O(n x k)
// sc - O(1)



// --- better
Node* rotate2(Node* head, int k) {
    if (!head || k == 0) return NULL;

    Node* temp = head;
    // hash vector to store all nodes for easy access
    vector<Node*> hash;

    // add all nodes to the hash map
    while (temp) {
        hash.push_back(temp);
        temp = temp -> next;
    }

    int sizeL = hash.size();
    // modulus of k
    k = sizeL % k;
    // return if no rotation
    if (k == 0) return head;

    // size of hash map - k (becomes the new head)
    Node* newHead = hash[sizeL - k];
    // node before newhead is now the last node
    Node* lastNode = hash[sizeL - k - 1];

    // disconnect last node and new head
    lastNode -> next = nullptr;
    // comment last node of new head to head
    hash.back() -> next = head;

    // return the head in rotated linked list
    return newHead;
}
// TC - O(n)
// SC - O(n)



// --- optimal
Node* rotate3(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find the length and the tail
    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    temp -> next = head;
    int end = len - k;
    while (end--) temp = temp -> next;

    head = temp -> next;
    temp -> next = nullptr;

    return head;
}
// tc - O(n)
// sc - O(1)