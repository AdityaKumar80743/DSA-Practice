// ------- Segregate even and odd nodes in LinkedList ----

// --- brute 
Node* segregate2(Node* head) {
    Node* temp = head;
    vector<int> even, odd;

    while (temp) {
        if (temp -> data % 2 == 0) {
            even.push_back(temp -> data);
        }
        else odd.push_back(temp -> data);

        temp = temp -> next;
    }

    temp = head;
    for (int i=0; i<even.size(); i++) {
        temp -> data = even[i];
        temp = temp -> next;
    }
    for (int i=0; i<odd.size(); i++) {
        temp -> data = odd[i];
        temp = temp -> next;
    }
    return head;
}
// TC - O(2n) 
// SC - O(n) 

// --- optimal
Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    Node *evenHead = nullptr, *evenTail = nullptr;
    Node *oddHead = nullptr, *oddTail = nullptr;

    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data % 2 == 0) { 
            // Even node
            if (!evenHead) {
                evenHead = evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        } else {
            // Odd node
            if (!oddHead) {
                oddHead = oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }

    // No evens -> return odds only
    if (!evenHead) return oddHead;
    // No odds -> return evens only
    if (!oddHead) return evenHead;

    // Connect even ll to odd ll
    evenTail->next = oddHead;
    oddTail->next = nullptr; // important to terminate list

    return evenHead;
}

// TC - O(n) 
// SC - O(1)


// if have to segregate the odd and even nodes based on postion
Node* segregate3(Node* head) {
    if (head == NULL || head -> next == NULL) return NULL;

    Node* odd = head;
    Node* even = head -> next;
    Node* evenHead = head -> next;

    while (even && even -> next) {
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;

        odd = odd -> next;
        even = even -> next;
    }

    odd -> next = evenHead;

    return head;
}