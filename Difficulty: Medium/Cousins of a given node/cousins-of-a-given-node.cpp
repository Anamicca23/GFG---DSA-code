// User function Template for C++

/*
// A Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  public:
       void update(Node* root, map<int, map<int, int>>& mp, Node* parent, int level, Node* node_to_find, int &mumbai, Node* &juhu) {
    if (root == nullptr)
        return;
        
    if (root == node_to_find) {
        mumbai = level;
        juhu = parent;
    }
   if(parent!=NULL)
        mp[level][root->data] = parent->data;

    update(root->left, mp, root, level + 1, node_to_find, mumbai, juhu);
    update(root->right, mp, root, level + 1, node_to_find, mumbai, juhu);
}

vector<int> printCousins(Node* root, Node* node_to_find) {
    vector<int> ans;
    map<int, map<int, int>> mp;
    int mumbai = 0;
    Node* juhu = nullptr;
    int level = 0;
    
    update(root, mp, nullptr, level, node_to_find, mumbai, juhu);

    for (auto it = mp[mumbai].begin(); it != mp[mumbai].end(); ++it) {   // WE JUST TRAVERSE THAT LEVEL ONLY 
        if (it->second!=(juhu ? juhu->data:-1)) {  // Check if the parent is not the same
            ans.push_back(it->first);
        }
    }
    if(ans.size()==0)
    ans.push_back(-1);
    
    return ans;
}

};