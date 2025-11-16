// ------ Find Pairs with Given Sum in Doubly Linked List ----------


// --- optimal 
vector<vector<int>> findPair2(Node* head, int target) {
    if (!head) return {};

    Node* low = head;
    Node* high = head;

    while (high->next) {
        high = high -> next;
    }

    vector<vector<int>> ans;
    while(high != low && low->back != high) {
        int sum = low->data + high->data;

        if (sum < target) {
            low = low -> next;
        }
        else if (sum > target) {
            high = high -> back;
        }
        else {
            ans.push_back({low->data, high->data});
            low = low -> next;
            high = high -> back;
        }
    }
    return ans;
}
// TC - O(n)
// SC - O(1)


// --- better solution but not return sorted answers
vector<vector<int>> findPair(Node* head, int target) {
    unordered_set<int> hash;
    vector<vector<int>> ans;

    int min = head->data;

    Node* current = head;

    while( current ) {
        int val = current -> data; // optimasation

        if (val + min > target) break;

        if (hash.count(target-val)) {
            ans.push_back({target-val, val})
        }

        hash.insert(val);
        current = current->next;
    }
    return ans;
}
// TC - O(n) 
// sc - O(n)


void printV(const vector<vector<int>>& v) {
    for (const auto& row : v) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}
