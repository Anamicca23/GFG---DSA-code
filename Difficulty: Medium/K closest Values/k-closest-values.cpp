/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root , vector<int>&arr){
        if(root == NULL )return;
        solve(root->left,arr);
        arr.push_back(root->data);
        solve(root->right,arr);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int>in;
        solve(root,in);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int num : in){
            pq.push({abs(target-num) , num});
        }
        
        vector<int>ans;
        while(ans.size() < k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};