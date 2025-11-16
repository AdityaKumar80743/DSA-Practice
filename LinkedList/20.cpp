// ---------- add one to linked list --------------

// --- iterative approch
Node* reverseLL(Node* head) {
    Node* prev = NULL:
    Node* curr = head;

    while (curr -> next) {
        Node* front = curr -> next;

        curr -> next = prev;
        prev = curr;

        curr = front;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverseLL(head);
    Node* current = head;

    int carry = 1;
    while (current && carry) {
        int sum = current -> data + carry;
        current -> data = sum % 10;
        carry = sum / 10;

        if (!current -> next && carry) {
            current -> next = new Node(carry);
            carry = 0;
        }
        current = current -> next;
    }

    return reverseLL(head);
}
// TC - O(n) 
// SC - O(1)


// --- recursive approch

int addOneNum(Node* node) {
    if (!node) return 1;

    int carry = addOneNum(node -> next);
    int sum = carry -> data + carry;
    node -> data = sum % 10;

    // carry = sum / 10;
    return sum / 10;
}

Node* addOne2(Node* head) {
    int carry = addOneNum(head);

    if (carry) {
        Node* newHead = new Node(carry, head);
        head = newHead;
    }
    return head;
}




