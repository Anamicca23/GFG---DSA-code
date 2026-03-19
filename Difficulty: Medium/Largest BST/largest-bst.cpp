/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int largestBst(Node *root) {
        int size = 0; 
        auto f = [&](Node* root,auto&& f)->pair<int,pair<int,int>>{
            if(root==nullptr){return {0,{INT_MAX,INT_MIN}};}
            auto left = f(root->left,f);
            auto right = f(root->right,f);
            if(left.second.second<root->data && right.second.first>root->data)
            {
                return { left.first+right.first+1,{ min(root->data,left.second.first),max(root->data,right.second.second) }};
            }
            
            return {max(left.first,right.first),{INT_MIN,INT_MAX}};
        };
        
        auto x = f(root,f);
        return max(1,x.first);
    }
};