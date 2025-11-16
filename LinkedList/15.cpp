// ------ Remove N-th node from the end of a Linked List -------

// get the length of linked list 
// calculate the nth nodes positon by (size of ll - n)
// call the delete node by postion function

Node* deletePosLL(Node* head, int index) {
    if (head == NULL) return NULL;

    if (index == 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    int pos = 0;
    Node* temp = head;

    while (temp && pos < index - 1) {
        temp = temp -> next;
        pos++;
    }   

    // temp is at node before target node
    if (!temp || !temp -> next) return head;

    Node* delNode = temp -> next;
    temp -> next = delNode -> next;

    delete delNode;
    return head;
}

Node* removeNth(Node* head, int n) {
    Node* temp = head;
    int len = 0;

    while (temp) {
        len++;
        temp = temp -> next;
    }
    return deletePosLL(head, len - n);
}
// TC - O(n)


// --- optimal
Node* removeNth2(Node* head, int n) {
    Node* dummy = new Node(0, head);

    Node* slow = dummy;
    Node* fast = dummy;

    // move fast pointer n + 1 steps ahead
    for (int i=0; i<n; i++) {
        fast = fast -> next;
    }

    while (fast) {
        fast = fast -> next;
        slow = slow -> next;
    }

    // Node* delNode = slow -> next;
    // slow -> next = delNode -> next;
    // delete delNode

    // Node* newHead = dummy -> next;
    // delete dummy;
    // return newHead;

    // ---- (or) 
    slow -> next = slow -> next -> next;
    return dummy -> next;
}

// TC - O(n)