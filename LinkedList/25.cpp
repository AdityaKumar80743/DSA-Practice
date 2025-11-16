// ------ Reverse Linked List in groups of Size K -------------

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

// get the last node in the group of k
Node* getKthNode(Node* temp, int k) {
    k -= 1;
    while(temp && k>0) {
        k--;
        temp = temp -> next;
    }
    return temp;
}


Node* kReverse(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp) {
        // get the last node in the group of k
        Node* kThNode =  getKthNode(temp, k);

        // check if group if of less than k 
        // means end of linked list
        if (kThNode == NULL) {
            if (prevLast) {
                prevLast -> next = temp;
            }
            // exit the loop
            break;
        }

        // store the first node of the next group
        Node* nextNode = kThNode->next;
        // seperate the last node of the group
        kThNode -> next = NULL;

        // reverse the group of nodes
        reverseLL(temp);

        // change the head if temp = head
        // now the last node of the first group becomes the head
        if (temp == head) {
            head = kThNode;
        }
        // connect the preveous node with first node of reversed group
        else {
            prevLast -> next = kThNode;
        }

        // update the previous last node
        prevLast = temp;
        // move to next groups first element
        temp = nextNode;
    }
    return head;
}
// TC - O(n) -> 2n
// SC - O(1)
