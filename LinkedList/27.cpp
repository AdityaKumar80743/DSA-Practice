// ------------- Flattening a Linked List ------------

// --- brute force
// add all data of linkedlist to vector 
// sort the vector
// create a new flatterend linked list
Node* flat(Node* head) {
    vector<int> hash;

    Node* temp = head;

    // access all the data of linked list
    while (temp) {
        Node* childN = temp
        // acces all the data of linked list childs
        while (childN) {
            // add data to the hash vector
            hash.push_back(childN->data);
            childN = childN->child;
        }
        temp = temp->next;
    }

    // sort the hash vector
    sort(hash.begin(), hash.end());

    // create new flatterend linked list 
    Node* newhead = new Node(-1);
    Node* dummy = newhead;

    for (const auto val:hash) {
        dummy -> child = new Node(val);
        dummy = dummy -> child;
    }    

    // return result
    return newhead->child;
}
// TC - O(n x m) (chile length and head length) + O((n*m) x log(n*m)) + O(n * m)
// SC - O(n x m) + O(n x m)




// --- optimal 

Node* merge(Node* p1, Node* p2) {
    Node dummy(-1);
    Node* tail = &dummy;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            tail->child = p1;
            p1 = p1->child;
        } else {
            tail->child = p2;
            p2 = p2->child;
        }
        tail = tail->child;
        tail->next = nullptr;
    }

    // Attach remaining part
    if (p1) tail->child = p1;
    else tail->child = p2;

    // modern cpp
    // tail->child = (a ? a : b);

    return dummy.child;
}


Node* flat2(Node* head) {
    if (!head || !head->next) return head;

    Node* rightFlat = flat2(head->next);
    return merge(head, rightFlat);
}
// TC - O(n x m)
// sc - O(1)