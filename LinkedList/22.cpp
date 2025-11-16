// -------- Remove duplicates from sorted DLL --------

Node* removeDuplicates(Node* head) {
    if (!head) return NULL;

    Node* current = head;
    while (current && current->next) {
        Node* nextUnique = current -> next;

        // iterate until a new unique values if found
        while (nextUnique && nextUnique->data == current->data) {
            Node* duplicateNode = nextUnique;
            nextUnique = nextUnique -> next;
            delete duplicateNode;
        }

        //  connect the current node with found unique node
        current -> next = nextUnique;
        if (nextUnique) nextUnique -> back = current;
        current = current -> next;
    }
    return head;
}
// TC - O(n) 
// Sc - O(1)