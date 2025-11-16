//  ---------------- STARTING POINT OF LOOP --------------

// --- brute
Node* cycle(Node* head) {
    unordered_map<Node*, int> hash;
    Node* temp = head;

    while (temp) {
        if (hash.find(temp) != hash.end()) return temp;
        hash[temp] = 1;
        temp = temp -> next;
    }
    return NULL;
}
// TC - O(n) 
// SC - O(n)


// -- optimal 
// using floyd's algorithm
Node* cycle2(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast -> next) {
        start = start -> next;
        fast = fast -> next -> next;

        if (fast == slow) {
            start = head;
            while (start != head) {
                start = start -> next;
                fast = fast -> next;
                }
        }
    }  
    return NULL;
}

// TC =- O(n)
// SC =- O(1)