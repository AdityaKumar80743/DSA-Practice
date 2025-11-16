// -------- Delete all occurrences of a key in DLL --------

// head is not deleted
Node* delOccur(Node* node, int target) {
    Node* current = node;

    while(current) {
        if (current && current->data == target) {
            Node* targetNode = current;

            Node* prev = targetNode->back;
            Node* front = targetNode->next;

            // unlink
            prev->next = front;
            if (front) {
                front->back = prev;
            }

            // move pointers before deleting
            current = front;
            delete targetNode;
        }
        else current = current->next;
    }
    return node; 
}
// TC - O(n) 
// Sc - O(1)