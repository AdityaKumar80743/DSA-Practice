// ----------- CHECK PALINDROME IN ll ----------


// --- optimal 
// correct appraoch
bool checkPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle of list
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* newHead = reverseLL(slow->next);

    // Step 3: Compare first and second halves
    Node* firstHalf = head;
    Node* secondHalf = newHead;

    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            // reverse and return the answer
            reverseLL(newHead);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Step 4: Restore original list order
    reverseLL(newHead);

    return true;
}
// tc - O(n)
// sc - O(1)


// incorrect approach

// 1: reverse the ll 
// 2: compare with original

// - reverse the ll
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

bool checkPalindrome(Node* head) {
    if (head == NULL || head -> next == NULL) return true;

    Node* original = head;
    Node* reversed = reverseLL(head);
    int pos = 0;

    while (original && reversed) {
        if (original -> data == reversed -> data) {
            original = original -> next;
            reversed = reversed -> next;
        }
        else return false;
    }
    return true;
}
// TC - O(n) => 2n -> n
// SC - O(1) - storing reversed ll


// works fine in terms of checking palindrome but.
// Problem 1 : the ll is reversed - destroyes the orignal data
// Problem 2 : as we are reversing head and original = head , we are checking the same nodes = ans will always be true; 
// CONTRADICTION : results are correct