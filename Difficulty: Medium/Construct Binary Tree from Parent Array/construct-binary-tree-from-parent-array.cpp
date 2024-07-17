//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
   void dfs(Node* &root, unordered_map<int, pair<int, int> >& mp) {
        
        if(mp.find(root->data) != mp.end()) {
            root->left = new Node(mp[root->data].first);
            dfs(root->left, mp);
            if(mp[root->data].second != -1) {
                root->right = new Node(mp[root->data].second);
                dfs(root->right, mp);
            }
        }
    }
    Node *createTree(vector<int> parent) {
        // Your code here.
        int i = 0;
        for(; i < parent.size(); i++) {
            if(parent[i] == -1) break;
        }
        Node* root = new Node(i);
        unordered_map<int, pair<int, int> >mp;
        for(int i=0; i < parent.size(); i++) {
            if(parent[i] == -1) continue;
            if(mp.find(parent[i]) != mp.end()) {
                mp[parent[i]].second = i;
            } else {
                mp[parent[i]].first = i;
                mp[parent[i]].second = -1;
            }
        }
        dfs(root, mp);
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends