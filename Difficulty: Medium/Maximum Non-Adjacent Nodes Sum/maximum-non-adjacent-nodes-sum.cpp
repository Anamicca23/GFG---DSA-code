/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    void Travarse(Node* root, map<Node*, int>&take, 
    map<Node*, int>&not_take)
    {
        if(!root)return;
        
        Travarse(root -> left, take, not_take);
        Travarse(root -> right, take, not_take);
        
        take[root] += not_take[root -> left];
        take[root] += not_take[root -> right];
        take[root] += root -> data;
        
        not_take[root] += take[root -> left];
        not_take[root] += take[root -> right];
        if(not_take[root] > take[root])take[root] = not_take[root];
    }
    int getMaxSum(Node *root) {
        map<Node*, int>take, not_take;
        not_take[NULL] = take[NULL] = 0;
        
        Travarse(root, take, not_take);
        return max(take[root], not_take[root]);
    }
};