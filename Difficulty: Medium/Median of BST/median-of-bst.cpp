/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void inorder(Node* root, int &count) {
        if (root == NULL) return;
        inorder(root->left, count);
        count++;
        inorder(root->right, count);
    }
    
    void findNodeHelper(Node* root, int &k, int &res) {
        if (root == NULL) return;
        findNodeHelper(root->left, k, res);
        k--;
        if (k == 0) {
            res = root->data;
            return;
        }
        findNodeHelper(root->right, k, res);
    }
    
    int findMedian(Node* root) {
        int Totalcount = 0;
        inorder(root, Totalcount);
        
        if (Totalcount == 0) return 0;
        
        if (Totalcount % 2 != 0) {
            int k = Totalcount / 2 + 1;
            int res = 0;
            findNodeHelper(root, k, res);
            return res;
        } else {
            int k1 = Totalcount / 2;
            //int k2 = k1 + 1;
            int res1 = 0, res2 = 0;
            findNodeHelper(root, k1, res1);
            //findNodeHelper(root, k2, res2);
            return (res1) ;
        }
    }
};