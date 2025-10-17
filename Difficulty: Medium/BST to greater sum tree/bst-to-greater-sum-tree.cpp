/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int solve(Node* root, int sum){
        if(!root)return 0;
        int r = solve(root->right, sum);
        int l = solve(root->left, root->data+sum+r);
        int to_return = root->data+l+r;
        root->data = r+sum;
        return to_return;
    }
    void transformTree(Node *root) {
        solve(root, 0);
    }
};