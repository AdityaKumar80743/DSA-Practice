// ----------- Find intersection of Two Linked Lists -----------

Node* intersection(Node* headA, Node* headB) {
    while (headA) {
        Node* temp = headB;
        while (temp) {
            if (temp = headA) return headA;
            temp = temp -> next;
        }
        headA = headA -> next;
    }
    return NULL;
}
// TC - O(n^2) 
// SC - O(1)

// not working
Node* intersection2(Node* headA, Node* headB) {
    unordered_map<Node*> hash;

    while (headA) {
        st.insert(headA)
        headA = headA -> next;
    }
    while (headB) {
        if (st.find(headB) != st.end()) return headB;
        headB = headB -> next;
    }
    return NULL;
}
// TC - O(n)
// SC - O(n)