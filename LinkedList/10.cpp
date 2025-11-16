// ----------------- DETECT A CYCLE IN ll ----------------
// --- better
// using hash map
bool cycle(Node* head) {
    unordered_map<Node*, int> hash;
    Node* temp = head;

    while (temp) {
        if (hash.find(temp) != hash.end()) return true;
        hash[temp] = 1;
        temp = temp -> next;
    }
    return false;
}
// TC - O(n) 
// SC - O(n)


// --- optimal
// Floyd's Cycle-Finding Algorithm
bool cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
// TC - O(n)
// SC - O(1)