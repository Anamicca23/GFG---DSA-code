/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
    using pri = pair<Node*, int>;
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        vector<int> ans;
        
        if (!root)
            return ans;
        map<int, int> map;
        
        queue<pri> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int n {q.size()};
            for(auto i {0}; i < n; i++) {
                auto node {q.front().first};
                auto dis {q.front().second};
                q.pop();
                
                map[dis] += node->data;
                
                if (node->left)
                    q.push({node->left, dis - 1});
                if (node->right)
                    q.push({node->right, dis + 1});
            }
        }
        for (auto& [k, v] : map)
            ans.push_back(v);
        return ans;
    }
};
