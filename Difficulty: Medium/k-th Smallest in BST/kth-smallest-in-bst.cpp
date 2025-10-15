/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int &k) {
        // code here
        if(root == NULL) return -1;
        int tmp = kthSmallest(root -> left, k);
        if(tmp != -1) return tmp;
        k--;
        if(k == 0) return root -> data;
        return kthSmallest(root -> right, k);
    }
};