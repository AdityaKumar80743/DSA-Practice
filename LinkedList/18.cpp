// ------------ sort a ll of 0s 1s and 2s -----------

Node* sort012(Node* head) {
    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;

    Node* oneHead = new Node(-1);
    Node* one = oneHead;

    Node* secondHead = new Node(-1);
    Node* second = secondHead;

    Node* temp = head;

    while (temp) {
        int data = temp -> data;
        if (data == 0) {
            zero -> next = temp;
            zero = zero -> next;
        } 
        else if (data == 1) {
            one -> next = temp;
            one = one -> next;
        }
        else {
            second -> next = temp;
            second = second -> next;
        }
        temp = temp -> next;
    }

    zero -> next = oneHead -> next ? oneHead -> next : secondHead -> head;
    one -> next = secondHead -> next;
    second -> next = nullptr;

    Node* newHead = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete secondHead;

    return zeroHead -> next;
}