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
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> result;
        queue<pair<int, Node*>> q;
        map<int, vector<int>> table;
        if (root == nullptr)
            return result;
        q.push({0, root});
        while (!q.empty()) {
            int index = q.front().first;
            Node* currentNode = q.front().second;
            q.pop();
            table[index].push_back(currentNode->data);
            if (currentNode->left) {
                 q.push({index - 1, currentNode->left});
            }
            if (currentNode->right) {
                 q.push({index + 1, currentNode->right});
            }
        }
        for (auto column : table) {
            result.push_back(column.second);
        }
        return result;
    }
};