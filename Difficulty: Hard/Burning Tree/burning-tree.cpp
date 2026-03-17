//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,bool> vis;
    Node *tar  =nullptr;
    int minTime(Node* root, int target) 
    {
        dfs1(root,target);
        return dfs2(tar)-1;
    }
    void dfs1(Node *root,int target){
        if(root == nullptr){
            return;
        }
        if(root->data == target){
            tar = root;
        }
        if(root->left != nullptr){
            par[root->left] =root;
        }if(root->right != nullptr){
            par[root->right]= root;
        }
        dfs1(root->left,target);
        dfs1(root->right,target);
    }
    int dfs2(Node* from){
        if(from == nullptr){
            return 0;
        }
        int lft = 0, rgt = 0, parent = 0;
        vis[from] =true;
        if(vis.find(from->left) == vis.end()){
            lft = dfs2(from->left);
        }
        if(vis.find(from->right) == vis.end()){
            rgt = dfs2(from->right);
        }
        if(par.find(from) != par.end() && vis.find(par[from]) == vis.end()){
            parent = dfs2(par[from]);
        }
        return 1 + max(max(lft, rgt), parent);
    }
};
