// ---------- LENGTH OF LOOP ----------
// --- brute
int cycle(Node* head) {
    unordered_map<Node*, int> hash;
    Node* temp = head;
    int len = 0;

    while (temp) {
        if (hash.find(temp) != hash.end()) {
            Node* start = temp;
            temp = temp -> next;
            while (temp != start) {
                len++;
                temp = temp -> next;
            }
            return len;
        }
        hash[temp] = 1;
        temp = temp -> next;
    }
    return len;
}
// TC - O(2n) 



// --- better
int cycle2(Node* head) {
    unordered_map<Node* , int> hash;
    int timer = 0;
    Node* temp = head;

    while (temp) {
        if (hash.find(temp) != temp.end()) {
            int loopLen = timer - hash[temp];
            return loopLen;
        }
        hash[temp] = timer;
        timer++;
        temp = temp -> next;
    }
    return 0;
}
// TC - O(n)


// --- optimal
int countLen(Node* meetingPoint) {
    Node* temp = meetingPoint;
    int length = 1;

    while (temp -> next != meetingPoint) {
        temp = temp -> next;
        length++;
    }
    return length;
}

int cycle3(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast) {
            return countLen(slow);
        }
    }
    return 0;
}

// TC - O(n)
// SC - O(1)