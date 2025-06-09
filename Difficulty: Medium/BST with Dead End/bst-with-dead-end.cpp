/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool find(Node* root, unordered_map<int, bool> mp) {
        if(!root) return false;
        mp[root -> data] = true;
        if(!root -> left && !root -> right) {
            return mp[root -> data - 1] && mp[root -> data + 1];
        }
        return find(root -> left, mp) || find(root -> right, mp);
    }
    bool isDeadEnd(Node *root) {
        unordered_map<int, bool> mp;
        mp[0] = true;
        return find(root, mp);
    }
};