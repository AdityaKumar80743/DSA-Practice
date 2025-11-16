// -------- Sort a Linked List -------

// brute force
Node* sortLL(Node* head) {
    vector<int> nodeVals;
    Node* temp = head;

    while(temp) {
        nodeVals.push_back(temp->data);
        temp = temp -> next;
    }

    sort(nodeVals.begin(), nodeVals.end());
    temp = head;

    for (int it:nodeVals) {
        temp -> data = it;
        temp = temp -> next;
    }
    return head;
}    
// TC - O(nlogn + 2n) 
// SC - (n)



// --- optimal 
// by merge sort algorithm

// find middle node
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

// merge nodes
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result;

    if (left->data <= right->data) {
        result = left;
        result -> next = merge(left->next, right);
    }
    else {
        result  = right;
        result -> next = merge(left, right->next);
    }
    return result;
}

Node* sortLL(Node* head) {
    // base case
    if (!head || !head -> next) return head;

    // get middle node
    Node* mid = findMiddle(head);
    // get head of right node
    Node* right = mid->next;
    // split left and right halves
    mid->next = nullptr; 

    // divide the left and right halves further 
    // till all nodes become single
    Node* leftSorted = sortLL(head);
    Node* rightSorted = sortLL(right);

    // merge left and right halves in sorted order
    return merge(leftSorted, rightSorted);
}
