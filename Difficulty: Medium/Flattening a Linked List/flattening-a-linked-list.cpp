class Solution {
  public:
    
    // Function to merge two sorted linked lists using bottom pointer
    Node* merge(Node* a, Node* b) {
        Node dummy(-1);
        Node* ans = &dummy;

        while (a && b) {
            if (a->data <= b->data) {
                ans->bottom = a;
                a = a->bottom;
            } else {
                ans->bottom = b;
                b = b->bottom;
            }
            ans = ans->bottom;
            ans->next = NULL;   
        }

        if (a) ans->bottom = a;
        if (b) ans->bottom = b;

        return dummy.bottom;
    }

    // Function to flatten the linked list
    Node *flatten(Node *root) {
        // Base case
        if (root == NULL || root->next == NULL)
            return root;

        // Flatten the list on right side
        root->next = flatten(root->next);

        // Merge current list with flattened right list
        root = merge(root, root->next);

        return root;
    }
};
