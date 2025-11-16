// ----- add two reversed linked list ------------
Node* addTwoLL(Node* tempA, Node* tempB) {
    Node* ansHead = new Node(-1);
    Node* ans = ansHead;
    int carry = 0;
    
    while (tempA && tempB) {
        int sum = tempA->data + tempB->data + carry;
        ans -> next = new Node(sum % 10);
        carry = sum / 10;

        tempA = tempA -> next;
        tempB = tempB -> next;
        ans = ans -> next; 
    }

    while (tempA) {
        int sum = tempA->data + carry;
        ans -> next = new Node(sum % 10);
        carry = sum / 10;

        tempA = tempA -> next;
        ans = ans -> next;
    }

    while (tempB) {
        int sum = tempB->data + carry;
        ans -> next = new Node(sum % 10);
        carry = sum / 10;

        tempB = tempB -> next;
        ans = ans -> next;
    }
    if (carry) { // can use while
        ans -> next = new Node(carry);
        ans = ans -> next; // optional
    }
    return ansHead -> next;
}


// --- better representation 
Node* addTwoLL(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = 0;

        if (l1) {
            sum += l1 -> data;
            l1 = l1 -> next;
        }

        if (l2) {
            sum += l2 -> data;
            l2 = l2 -> data;
        }

        sum += carry;
        carry = sum / 10;
        temp -> next = new Node(sum % 10);
        temp = temp -> next;
    }
    return dummy -> next;
}
// tc - 0(max(l1 ,l2))
// sc - O(max(l1, l2))