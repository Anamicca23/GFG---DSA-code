/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int,int> solve(Node* root){
        if(!root)return {0,0};
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        int cnt = root->data + l.first + r.first - 1;
        int cost = abs(cnt) + l.second + r.second;
        
        return {cnt, cost};
    }
    int distCandy(Node* root) {
        pair<int,int>  p = solve(root);
        return p.second;
    }
};