/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool checktree(Node* root1,Node* root2,bool &ans) {
       if (!root1 && !root2) return 1;
       if (!root1 || !root2) return 0;
        bool lefty = false,righty = false;
        if (root1->data == root2->data) {
            lefty = checktree(root1->left,root2->left,ans);
            righty = checktree(root1->right,root2->right,ans);
        }
        return lefty || righty;
    }
    bool iterate(Node* root1, Node* root2,bool &ans) {
        if (!root1 || !root2) return false;
        bool wow = false;
        if (root1->data == root2->data) {
            wow = checktree(root1,root2,ans);
        }
        
        bool lefty = iterate(root1->left,root2,ans);
        bool righty =iterate(root1->right,root2,ans);
        if (wow) return 1;
        return lefty || righty;
    }
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        bool ans = 0;
        ans = iterate(root1,root2,ans);
        return ans;
    }
};